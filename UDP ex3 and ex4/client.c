#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#define PORT 58000 // Port to be passed in htons
////
int main(){
int fd, n,i;
struct hostent *hostptr;
struct sockaddr_in serveraddr, clientaddr;
int addrlen;
char msg[80], buffer[80];
////
//UDP Client
fd=socket(AF_INET,SOCK_DGRAM,0);
hostptr=gethostbyname("basanta-UX430UQ");
memset((void*)&serveraddr,(int)'\0', sizeof(serveraddr));
serveraddr.sin_family = AF_INET;
serveraddr.sin_addr.s_addr = ((struct in_addr *)
      (hostptr->h_addr_list[0]))->s_addr;
serveraddr.sin_port = htons((u_short)PORT);
addrlen = sizeof(serveraddr);

// Sends data to the Server EX 3

sendto(fd, "Hello!\n", 7, 0, (struct sockaddr*)&serveraddr,addrlen);
//if(n==-1) exit(1);


close(fd);
exit(0);

}
