#include <cstdio>       //printf
#include <cstring>      //memset
#include <cstdlib>      //exit
#include <netinet/in.h> //htons
#include <arpa/inet.h>  //inet_addr
#include <sys/socket.h> //socket
#include <unistd.h>     //close
 
 
#define MAXMSG 1024
#define MAXNAME 100
#define PORTNUM 4555
 

typedef struct{
    int op;
    int id;
    int value;
}Operation;


 
 
int main(int argc, char *argv[])
{
    //variáveis do servidor
    struct sockaddr_in endereco;
    int socketId;
 
    //variáveis relacionadas com as conexões clientes
    struct sockaddr_in enderecoCliente;
    socklen_t tamanhoEnderecoCliente = sizeof(struct sockaddr);
    int conexaoClienteId;
 
    Operation op;
    int byteslidos;
 
    /*
     * Configurações do endereço
    */
    memset(&endereco, 0, sizeof(endereco));
    endereco.sin_family = AF_INET;
    endereco.sin_port = htons(PORTNUM);
    //endereco.sin_addr.s_addr = INADDR_ANY;
    endereco.sin_addr.s_addr = inet_addr("192.168.7.1");
 
    /*
     * Criando o Socket
     *
     * PARAM1: AF_INET ou AF_INET6 (IPV4 ou IPV6)
     * PARAM2: SOCK_STREAM ou SOCK_DGRAM
     * PARAM3: protocolo (IP, UDP, TCP, etc). Valor 0 escolhe automaticamente
    */
    socketId = socket(AF_INET, SOCK_STREAM, 0);
 
    //Verificar erros
    if (socketId == -1)
    {
        printf("Falha ao executar socket()\n");
        exit(EXIT_FAILURE);
    }
 
    //Conectando o socket a uma porta. Executado apenas no lado servidor
    if ( bind (socketId, (struct sockaddr *)&endereco, sizeof(struct sockaddr)) == -1 )
    {
        printf("Falha ao executar bind()\n");
        exit(EXIT_FAILURE);
    }
 
    //Habilitando o servidor a receber conexoes do cliente
    if ( listen( socketId, 10 ) == -1)
    {
        printf("Falha ao executar listen()\n");
        exit(EXIT_FAILURE);
    }
 
    //servidor ficar em um loop infinito
    while(1)
    {
 
        printf("Servidor: esperando conexões clientes\n");
 
        //Servidor fica bloqueado esperando uma conexão do cliente
        conexaoClienteId = accept( socketId,(struct sockaddr *) &enderecoCliente,&tamanhoEnderecoCliente );
 
        printf("Servidor: recebeu conexão de %s\n", inet_ntoa(enderecoCliente.sin_addr));
 
        //Verificando erros
        if ( conexaoClienteId == -1)
        {
            printf("Falha ao executar accept()");
            exit(EXIT_FAILURE);
        }
 
        //receber uma msg do cliente
        printf("Servidor vai ficar esperando uma mensagem\n");
        byteslidos = recv(conexaoClienteId,&op,sizeof(op),0);
 
        if (byteslidos == -1)
        {
            printf("Falha ao executar recv()");
            exit(EXIT_FAILURE);
        }
        else if (byteslidos == 0)
        {
            printf("Cliente finalizou a conexão\n");
            exit(EXIT_SUCCESS);
        }
 
        printf("Servidor recebeu a seguinte msg do cliente [%d:%d]: %d \n",op.op,op.id,op.value);
 
        close(conexaoClienteId);
    }
 
    return 0;
}