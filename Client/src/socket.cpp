#include "socket.h"

Socket::Socket(const char * _ip ,int _port ) : ip(_ip), port(_port)
{

    memset(&address, 0, sizeof(address));
    address.sin_family = AF_INET;
    address.sin_port = htons(port);
    address.sin_addr.s_addr = inet_addr(ip);
}

void Socket::setMensage(Operation & _OP)
{
    OP = _OP;
}

int Socket::send()
{
    ID = ::socket(AF_INET,SOCK_STREAM, 0);

    if(ID == -1)
    {
        std::cout << "Falha ao executar socket()" << std::endl;
        return -1;
    }

    if( ::connect(ID, (struct sockaddr*) &address, sizeof(struct sockaddr)) == -1)
    {
        std::cout << "Falha ao executar connect()" << std::endl;
        return -2;
    }
    if(::send(ID, &OP, sizeof(OP), 0) == -1)
    {
        std::cout << "Falha ao executar send()" << std::endl;
        return -3;
    }

    ::close(ID);

    return 0;
}
