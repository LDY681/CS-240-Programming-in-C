#ifndef TALK_CLIENT_H
#define TALK_CLIENT_H


//#include <time.h>
//#include <curses.h>
//#include <sys/types.h>
#include <sys/socket.h>
//#include <netinet/in.h>
//#include <arpa/inet.h>
//#include <netdb.h>
#include <stdio.h>
#include <string.h>
//#include <unistd.h>
//#include <stdlib.h>
//#include <pthread.h>

#define MAX_MESSAGES 100
#define MAX_MESSAGE_LEN 300
#define MAX_RESPONSE (20 * 1024)

class talk_client{
public:
    talk_client();
    int open_client_socket( char * host, int port);
    int sendCommand(char *host, int port, char *command, char *user, char *password, char *args, char *response);   //
    void printUsage();
    void add_user(char * _user, char *_password);

    void printPrompt();
    void printHelp();
    void * getMessagesThread(void * arg);
    void startGetMessageThread();

protected:
    int lastMessage;
    char * host;
    char * _user;
    char * _password;
    char * sport;
    int port;
};

#endif //TALK_CLIENT_H
