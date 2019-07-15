#include <QCoreApplication>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

using namespace std;

void error(char *msg)
{
  perror(msg);
  exit(0);
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    int sockfd, portnum, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[256];
    if (argc < 3)
    {
       cout << "error";
    }
    portnum = atoi(argv[2]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
      error("ERROR opening socket");
    server = gethostbyname(argv[1]);
    if (server == NULL)
    {
      cout << "ERROR, no such host";
      exit(0);
    }
    struct hostent *gethostbyname(char *name);
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr,
          (char *)&serv_addr.sin_addr.s_addr,
          server->h_length);
    serv_addr.sin_port = htons(portnum);
    printf("Please enter the message: ");
      bzero(buffer,256);
      fgets(buffer,255,stdin);

      td::ifstream input("/home/andrewt/outfile.txt");
          while(getline(input, writeline)){
              std::cout << writeline;
              n = write(sockfd,buffer,strlen(buffer));
              if (n < 0){
                error("ERROR writing to socket");
              }
              bzero(buffer,256);
              n = read(sockfd,buffer,255);
              if (n < 0)
                error("ERROR reading from socket");
              printf("%s",buffer);
          }
          input.close();
      return 0;
    return a.exec();
}

