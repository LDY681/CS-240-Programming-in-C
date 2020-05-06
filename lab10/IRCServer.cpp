//TODO: -> when is a pointer . when normally 
const char * usage =
"                                                               \n"
"IRCServer:                                                   \n"
"                                                               \n"
"Simple server program used to communicate multiple users       \n"
"                                                               \n"
"To use it in one window type:                                  \n"
"                                                               \n"
"   IRCServer <port>                                          \n"
"                                                               \n"
"Where 1024 < port < 65536.                                     \n"
"                                                               \n"
"In another window type:                                        \n"
"                                                               \n"
"   telnet <host> <port>                                        \n"
"                                                               \n"
"where <host> is the name of the machine where talk-server      \n"
"is running. <port> is the port number you used when you run    \n"
"daytime-server.                                                \n"
"                                                               \n";

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>
#include <map>
#include<string>
#include<iterator>
#include <iostream>
#include <utility>
#include "IRCServer.h"
#include <sstream>

using namespace std;

int QueueLength = 5;

//test

//TODO: User & UList
struct User{
	char *name;	//username
	char *pass;	//password
	struct User * next;	//next user 
};
typedef struct User User;

struct UList{
	User * head;
};
typedef struct UList UList;

//TODO: Message & MList

struct Message{
	char * msg;
	char * user;
	struct Message *next;
};
typedef struct Message Message;

struct MList{
	Message *head;
};
typedef struct MList MList;


//TODO: Room & RList
struct Room{
	UList *users;
	MList *msgs;
	char *name;
	struct Room *next;
};
typedef struct Room Room;

struct RList{
	Room * head;
};
typedef struct RList RList;

UList uList;
RList rList;




int
IRCServer::open_server_socket(int port) {

	// Set the IP address and port for this server
	struct sockaddr_in serverIPAddress; 
	memset( &serverIPAddress, 0, sizeof(serverIPAddress) );
	serverIPAddress.sin_family = AF_INET;
	serverIPAddress.sin_addr.s_addr = INADDR_ANY;
	serverIPAddress.sin_port = htons((u_short) port);
  
	// Allocate a socket
	int masterSocket =  socket(PF_INET, SOCK_STREAM, 0);
	if ( masterSocket < 0) {
		perror("socket");
		exit( -1 );
	}

	// Set socket options to reuse port. Otherwise we will
	// have to wait about 2 minutes before reusing the sae port number
	int optval = 1; 
	int err = setsockopt(masterSocket, SOL_SOCKET, SO_REUSEADDR, 
			     (char *) &optval, sizeof( int ) );
	
	// Bind the socket to the IP address and port
	int error = bind( masterSocket,
			  (struct sockaddr *)&serverIPAddress,
			  sizeof(serverIPAddress) );
	if ( error ) {
		perror("bind");
		exit( -1 );
	}
	
	// Put socket in listening mode and set the 
	// size of the queue of unprocessed connections
	error = listen( masterSocket, QueueLength);
	if ( error ) {
		perror("listen");
		exit( -1 );
	}

	return masterSocket;
}

void
IRCServer::runServer(int port)
{
	int masterSocket = open_server_socket(port);

	initialize();
	
	while ( 1 ) {
		
		// Accept incoming connections
		struct sockaddr_in clientIPAddress;
		int alen = sizeof( clientIPAddress );
		int slaveSocket = accept( masterSocket,
					  (struct sockaddr *)&clientIPAddress,
					  (socklen_t*)&alen);
		
		if ( slaveSocket < 0 ) {
			perror( "accept" );
			exit( -1 );
		}
		
		// Process request.
		processRequest( slaveSocket );		
	}
}

int
main( int argc, char ** argv )
{
	// Print usage if not enough arguments
	if ( argc < 2 ) {
		fprintf( stderr, "%s", usage );
		exit( -1 );
	}
	
	// Get the port from the arguments
	int port = atoi( argv[1] );

	IRCServer ircServer;

	// It will never return
	ircServer.runServer(port);
	
}

//
// Commands:
//   Commands are started y the client.
//
//   Request: ADD-USER <USER> <PASSWD>\r\n
//   Answer: OK\r\n or DENIED\r\n
//
//   REQUEST: GET-ALL-USERS <USER> <PASSWD>\r\n
//   Answer: USER1\r\n
//            USER2\r\n
//            ...
//            \r\n
//
//   REQUEST: CREATE-ROOM <USER> <PASSWD> <ROOM>\r\n
//   Answer: OK\n or DENIED\r\n
//
//   Request: LIST-ROOMS <USER> <PASSWD>\r\n
//   Answer: room1\r\n
//           room2\r\n
//           ...
//           \r\n
//
//   Request: ENTER-ROOM <USER> <PASSWD> <ROOM>\r\n
//   Answer: OK\n or DENIED\r\n
//
//   Request: LEAVE-ROOM <USER> <PASSWD>\r\n
//   Answer: OK\n or DENIED\r\n
//
//   Request: SEND-MESSAGE <USER> <PASSWD> <MESSAGE> <ROOM>\n
//   Answer: OK\n or DENIED\n
//
//   Request: GET-MESSAGES <USER> <PASSWD> <LAST-MESSAGE-NUM> <ROOM>\r\n
//   Answer: MSGNUM1 USER1 MESSAGE1\r\n
//           MSGNUM2 USER2 MESSAGE2\r\n
//           MSGNUM3 USER2 MESSAGE2\r\n
//           ...\r\n
//           \r\n
//
//    REQUEST: GET-USERS-IN-ROOM <USER> <PASSWD> <ROOM>\r\n
//    Answer: USER1\r\n
//            USER2\r\n
//            ...
//            \r\n
//

void
IRCServer::processRequest( int fd )
{
	// Buffer used to store the comand received from the client
	const int MaxCommandLine = 1024;
	char commandLine[ MaxCommandLine + 1 ];
	int commandLineLength = 0;
	int n;
	
	// Currently character read
	unsigned char prevChar = 0;
	unsigned char newChar = 0;
	
	//
	// The client should send COMMAND-LINE\n
	// Read the name of the client character by character until a
	// \n is found.
	//

	// Read character by character until a \n is found or the command string is full.
	while ( commandLineLength < MaxCommandLine &&
		read( fd, &newChar, 1) > 0 ) {

		if (newChar == '\n' && prevChar == '\r') {
			break;
		}
		
		commandLine[ commandLineLength ] = newChar;
		commandLineLength++;

		prevChar = newChar;
	}
	
	// Add null character at the end of the string
	// Eliminate last \r
	commandLineLength--;
        commandLine[ commandLineLength ] = 0;

	printf("RECEIVED: %s\n", commandLine);

	printf("The commandLine has the following format:\n");
	printf("COMMAND <user> <password> <arguments>. See below.\n");
	printf("You need to separate the commandLine into those components\n");
	printf("For now, command, user, and password are hardwired.\n");
	
	//TODO:
	char command1[1025];
	char user1[1025];
	char password1[1025];
	char args1[1025];
	memset(command1,0,1025);
	memset(user1,0,1025);
	memset(password1,0,1025);
	memset(args1,0,1025);	

	int nRead = sscanf(commandLine, "%s %s %s %[^\n]", command1, user1, password1, args1);

	const char * command = command1;
	const char * user = user1;
	const char * password = password1;
	const char * args = args1;
	

	printf("command=%s\n", command);
	printf("user=%s\n", user);
	printf( "password=%s\n", password );
	printf("args=%s\n", args);

	
	
	if (!strcmp(command, "ADD-USER")) {
		addUser(fd, user, password, args);
	}
	else if (!strcmp(command, "ENTER-ROOM")) {
		enterRoom(fd, user, password, args);
	}
	else if (!strcmp(command, "LEAVE-ROOM")) {
		leaveRoom(fd, user, password, args);
	}
	else if (!strcmp(command, "SEND-MESSAGE")) {
		sendMessage(fd, user, password, args);
	}
	else if (!strcmp(command, "GET-MESSAGES")) {
		getMessages(fd, user, password, args);
	}
	else if (!strcmp(command, "GET-USERS-IN-ROOM")) {
		getUsersInRoom(fd, user, password, args);
	}
	else if (!strcmp(command, "GET-ALL-USERS")) {
		getAllUsers(fd, user, password, args);
	}
	else if (!strcmp(command, "CREATE-ROOM")) {
		createRoom(fd, user, password, args);
	}
	else if (!strcmp(command, "LIST-ROOMS")){	//FIXME
		listRoom(fd, user, password, args);
	}
	else {
		const char * msg =  "UNKNOWN COMMAND\r\n";
		write(fd, msg, strlen(msg));
	}

	// Send OK answer
	//const char * msg =  "OK\n";
	//write(fd, msg, strlen(msg));

	close(fd);	
}


void
IRCServer::initialize()
{


	// Open password file

	// Initialize users in room

	// Initalize message list

}

bool
IRCServer::checkPassword(int fd, const char * user, const char * password) {
	User *u = uList.head;
	while ( u != NULL){
		if (!strcmp(user, u->name)){
			if(!strcmp(password, u->pass)){	//password is correct
				return true;	
			}else{
				return false;	//password is incorrent
			}
		}
		u = u->next;
	}
	return false;	//user not found
}

void
IRCServer::addUser(int fd, const char * user, const char * password, const char * args)
{
	// Here add a new user. For now always return OK.
	
	//Add user
	User *u = (User*) malloc(sizeof(User));
	u->name = strdup(user);
	u->pass = strdup(password);
	u->next = uList.head;
	uList.head = u;
	
	//TODO:
	//
	//
	//
	//reorder uList
	User *prev = uList.head;
	User *curr = prev->next;
	while (curr != NULL){
		if (strcmp(prev->name, curr->name) >0){
			char *n = strdup(prev->name);
			char *p = strdup(prev->pass);
			prev->name = curr->name;
			prev->pass = curr->pass;
			curr->name = n;
			curr->pass = p;
		}
		prev = prev->next;
		curr = prev->next;
	}	


	//Message
	const char * msg =  "OK\r\n";
	write(fd, msg, strlen(msg));

	return;		
}

void
IRCServer::enterRoom(int fd, const char * user, const char * password, const char * args)
{
	//pass check 
	if(!checkPassword(fd,user,password)){
		write(fd,"ERROR (Wrong password)\r\n",strlen("ERROR (Wrong password)\r\n"));
		return;
	}
	int roomfound = 0;
	int userfound = 0;
	Room *r = rList.head;

	while (r != NULL){
		//strcmp return 0 when same, !strcmp = !0 = return true
		if ( !strcmp(r->name, args) ){	//Room found
			roomfound = 1;
			
			//Create uList for r & add new user
			if (r->users == NULL){
				UList *ur = (UList*)malloc(sizeof(UList));
				ur->head = NULL;
				r->users = ur;
				
				User *u = (User *)malloc(sizeof(User));
				u->name = strdup(user);
				u->pass = strdup(password);
				u->next = r->users->head;	//r is curr room
				r->users->head = u;
				userfound = 1;
			}
			


			User *u = r->users->head;	//users type pointer
			while (u != NULL){
				if (!strcmp(u->name, user)){	//User already in room
					userfound = 1;
					break;
				}
				u = u->next;
			}

			//need to create user if not found
			if (userfound == 0){	//user not found
				User *u = (User *)malloc(sizeof(User));
				u->name = strdup(user);
				u->pass = strdup(password);
				u->next = r->users->head;	//r is curr room
				r->users->head = u;	
			}

			//Message
			const char * msg =  "OK\r\n";
			write(fd, msg, strlen(msg));
			break;	
		}
	
	r = r->next;
	}

	//Room not found, You are innocent! Sry for blaming you on not passing TEST10!
	if (roomfound == 0){
		write(fd, "ERROR (No room)\r\n", strlen("ERROR (No room)\r\n"));
		return;
	}

	//NOW WE NEED TO REORDER USERLIST AGAIN!!!
	User *prev = r->users->head;
	User *curr = prev->next;
	while (curr != NULL){
		if (strcmp(prev->name, curr->name) >0){
			char *n = strdup(prev->name);
			char *p = strdup(prev->pass);
			prev->name = curr->name;
			prev->pass = curr->pass;
			curr->name = n;
			curr->pass = p;
		}
		prev = prev->next;
		curr = prev->next;
	}
	
}

void
IRCServer::leaveRoom(int fd, const char * user, const char * password, const char * args)
{
	//pass check 
	if(!checkPassword(fd,user,password)){
		write(fd,"ERROR (Wrong password)\r\n",strlen("ERROR (Wrong password)\r\n"));
		return;
	}

	int roomfound = 0;
	int userfound = 0;	
	Room *r = rList.head;
	while (r != NULL){
		if ( !strcmp(r->name, args) ){	//roomname match
			roomfound = 1;
			User *u = r->users->head;

			//First User condition
			if (!strcmp(u->name, user) ){
				r->users->head = u->next;
				write(fd, "OK\r\n", strlen("OK\r\n") );
				return;
			}

			while (u != NULL && u->next != NULL){
				if ( !strcmp(u->next->name ,user) ){	//username match
					userfound = 1;

					//last user condition
					if (u->next->next == NULL){
						u->next = NULL;
						write(fd, "OK\r\n", strlen("OK\r\n") );
						return;
					}

					//Normal
					u->next = u->next->next;
					write(fd, "OK\r\n", strlen("OK\r\n") );
					return;
				}
				u = u->next;
			}
		}
		r = r->next;
	}

	if (roomfound == 0 || userfound == 0 ){
		write(fd, "ERROR (No user in room)\r\n", strlen("ERROR (No user in room)\r\n") );
	}
}

void
IRCServer::sendMessage(int fd, const char * user, const char * password, const char * args)
{

	//pass check 
	if(!checkPassword(fd,user,password)){
		write(fd,"ERROR (Wrong password)\r\n",strlen("ERROR (Wrong password)\r\n"));
		return;
	}


	//char *args \A1\D9 char **argv
	char *arg = strdup(args);
	char *token1 = strtok(arg, " ");
	char *token2 = strtok(NULL, "");

	int roomfound = 0;
	int userfound = 0;
	Room *r = rList.head;
	while (r != NULL){
		if ( !strcmp(r->name, token1) ){	//Roomname match
			roomfound = 1;
			User *u = r->users->head;
			while (u != NULL){
				if ( !strcmp(u->name, user) ){	//User match
					userfound = 1;

					//ADD MESSAGE TO LAST!
					Message *message = (Message*)malloc(sizeof(Message));
					message->msg = strdup(token2);
					message->user = strdup(user);
					message->next = NULL;

					Message * it = r->msgs->head;
					Message * prev = (Message*)malloc(sizeof(Message));

					if (it == NULL){
						r->msgs->head = message;
					}
					while (it != NULL){
						prev = it;
						it = it->next;
					}
					prev->next = message;
					write(fd, "OK\r\n", strlen("OK\r\n") );
					return;		
				}
				u = u->next;
			}
		}
		r = r->next;
	}
	if (userfound == 0){
		write(fd,"ERROR (user not in room)\r\n",strlen("ERROR (user not in room)\r\n"));
		return;
	}

}
void
IRCServer::getMessages(int fd, const char * user, const char * password, const char * args)
{
	//pass check 
	if(!checkPassword(fd,user,password)){
		write(fd,"ERROR (Wrong password)\r\n",strlen("ERROR (Wrong password)\r\n"));
		return;
	}

	
	int count = 0;

	//char *args \A1\D9 char **argv
	char *arg = strdup(args);
	char *iindex = strtok(arg, " ");
	int index = atoi(iindex);
	char *rname = strtok(NULL, " ");

	int roomfound = 0;
	int userfound = 0;
	Room *r = rList.head;
	while (r != NULL){
		if ( !strcmp(r->name, rname) ){	//Roomname match
			roomfound = 1;
			User *u = r->users->head;
			while (u != NULL){
				if ( !strcmp(u->name, user) ){	//User match
					userfound = 1;

					if (r->msgs == NULL){
					}

					Message *m = r->msgs->head;

					int i;
					for (i = 0; i <= index; i++){
						if (m == NULL){
						write(fd, "NO-NEW-MESSAGES\r\n", strlen("NO-NEW-MESSAGES\r\n"));
						return;
						}
						m = m->next;
						count++;
					}

					while (m != NULL){
						//to_string doesnt work too! cant go any worser!
						//std::string  c = std::to_string(count);
						//strcat(str, c.c_str());

						std::stringstream ss;
						ss << count << " " << m->user << " " << m->msg << "\r\n";

						string result = ss.str();
						const char * str = strdup(result.c_str());
						write(fd, str, strlen(str) );

						//There is no difference! Idiot Testall!
						//sprintf(str, "%d %s %s", count, m->user, m->msg);
						//write(fd, str, strlen(str) );
						//write(fd, "\r\n", strlen("\r\n") );
						//

						
						m = m->next;
						count++;
					}
				}
				u = u->next;
			}
			if (userfound == 0){
				write(fd,"ERROR (User not in room)\r\n",strlen("ERROR (User not in room)\r\n"));
				return;
			}

			write(fd,"\r\n",strlen("\r\n"));
			//return;

		}
		r = r->next;
	}
	
}

void
IRCServer::listRoom(int fd, const char * user, const char * password, const char * args)
{
	if(!checkPassword(fd,user,password)){
		write(fd,"ERROR (Wrong password)\r\n",strlen("ERROR (Wrong password)\r\n"));
		return;
	}
	Room *r = rList.head;
		while (r != NULL){
			char *roomname = strdup(r->name);
			write(fd,roomname,strlen(roomname));
			write(fd, "\r\n", strlen("\r\n"));
			r = r->next;
		}
}

void
IRCServer::getUsersInRoom(int fd, const char * user, const char * password, const char * args)
{
	//pass check 
	if(!checkPassword(fd,user,password)){
		write(fd,"ERROR (Wrong password)\r\n",strlen("ERROR (Wrong password)\r\n"));
		return;
	}

	Room *r = rList.head;
	while (r != NULL){
		if ( !strcmp(r->name, args) ){
			
			//Real problem of not passing test10!
			if (r->users == NULL || r->users->head == NULL){
				write(fd, "\r\n", strlen("\r\n"));
				return;
			}
			if (r->users != NULL && r->users->head != NULL){
				User *u = r->users->head;
				while (u != NULL){
					char *n = strdup(u->name);	
					strcat(n, "\r\n");
					write(fd, n, strlen(n));
					u = u->next;	
				}
				write(fd, "\r\n", strlen("\r\n"));
			}	
		}
		r = r->next;
	}
}

void
IRCServer::getAllUsers(int fd, const char * user, const char * password,const  char * args)
{
	//pass check 
	if(!checkPassword(fd,user,password)){
		write(fd,"ERROR (Wrong password)\r\n",strlen("ERROR (Wrong password)\r\n"));
		return;
	}

	User *u = uList.head;
	while (u != NULL){
		char *n = strdup(u->name);
		strcat(n, "\r\n");
		const char *wr = strdup(n);
		write(fd, wr, strlen(wr));
		u = u->next;
	}
	write(fd, "\r\n", strlen("\r\n"));
}

void
IRCServer::createRoom(int fd, const char * user, const char * password,const  char * args)
{
	//pass check 
	if(!checkPassword(fd,user,password)){
		write(fd,"ERROR (Wrong password)\r\n",strlen("ERROR (Wrong password)\r\n"));
		return;
	}
	
	//TODO: check if room is already created
	
	//Normal
	Room *r = (Room *) malloc(sizeof(Room));
	UList * u = (UList *)malloc(sizeof(UList));
	r->users = u;
	MList *m = (MList *)malloc(sizeof(MList));
	r->msgs = m;
	r->name = strdup(args);
	r->next = rList.head;
	rList.head = r;

	//Message
	const char * msg =  "OK\r\n";
	write(fd, msg, strlen(msg));

	return;	
}

