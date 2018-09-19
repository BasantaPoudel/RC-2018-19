#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h> //memset
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 58000
/////

int main(void)
  {
    int fd,n;
    struct sockaddr_in addr;
    struct hostent *hostptr;
    // int addrlen;
    // struct hostent *h;
    // int clientlen;
//TCP Client
// Ex 6 Part 1 :socket
fd=socket(AF_INET,SOCK_STREAM,0);
if(fd==-1)exit(1);//error

hostptr=gethostbyname("basanta-UX430UQ");

memset((void*)&addr,(int)'\0',sizeof(addr));
addr.sin_family = AF_INET;
addr.sin_addr.s_addr = ((struct in_addr *)(hostptr->h_addr_list[0]))->s_addr;
addr.sin_port = htons((u_short)PORT);
// Ex 6 Part 2 :connect
n=connect(fd,(struct sockaddr*)&addr,sizeof(addr));
if(n==-1)exit(1);//error
// write(fd,...);
// read(fd,...);
// close(fd);
}
