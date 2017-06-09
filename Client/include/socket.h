#ifndef SOCKET_H
#define SOCKET_H

#include <cstring> //memset
#include <netinet/in.h> //htons
#include <arpa/inet.h> //inet_addr
#include <iostream>
#include <unistd.h> 


typedef struct{
    int op;
    int id;
    int value;
}Operation;

class Socket
{
public:
    Socket(const char * _ip ,int _port );
    void setMensage(Operation & _OP);
    int send();
    
    
private:
    int ID;
    int port;
    const char * ip;
    struct sockaddr_in address;
    Operation OP;
};

#endif // SOCKET_H
