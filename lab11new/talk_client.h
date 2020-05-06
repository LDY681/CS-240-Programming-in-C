#ifndef TALK_CLIENT_H
#define TALK_CLIENT_H


#include <time.h>
#include <curses.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_MESSAGES 100
#define MAX_MESSAGE_LEN 300
#define MAX_RESPONSE (20 * 1024)

class talk_client{
public:
//    talk_client();
    int open_client_socket( char * host, int port);
    int sendCommand(char *host, int port, char *command, char *user, char *password, char *args, char *response);   //
    void printUsage();
    void add_user();
    void enter_room();
    void leave_room();
    void get_messages();
    void send_message(char * msg);
    void print_users_in_room() ;
    void print_users();

    void printPrompt();
    void printHelp();
    void * getMessagesThread(void * arg);
    void startGetMessageThread();

    char * host;
    char * user;
    char * password;
    char *room;
    char *message;
    char *args;
    char * sport;
    int port;
};

#endif //TALK_CLIENT_H
