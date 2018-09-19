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

int main(){
int fd, nbytes, nleft, nwritten, nread;
char *ptr, buffer[128];
ptr=strcpy(buffer,"Hello\n");
nbytes=7;
nleft=nbytes;


//TCP Server
 while (nleft>0) {nwritten=write(fd,ptr,nleft);
   if(nwritten<=0)exit(1);
   nleft-=nwritten;
   ptr+=nwritten;
 }
 while (nleft>0) {nread=read(fd,ptr,nleft);
   if(nread==-1)exit(1);
   else if(nread==0)break;
   nleft-=nread;
 }
 nread=nbytes-nleft;
 close(fd);
 write(1,"echo: ",6);//stdout
 write(1,buffer,nread);//stdout
 exit(0);
}












//
//
// fd=socket(AF_INET,SOCK_STREAM,0);
//
// memset((void*)&serveraddr,(int)'\0',sizeof(serveraddr));
// serveraddr.sin_family = AF_INET;
// serveraddr.sin_addr.s_addr = htonl(INADDR_ANY);
// serveraddr.sin_port = htons((u_short)PORT);
//
// bind(fd,(struct sockaddr*)&serveraddr,
//         sizeof(serveraddr));
//
// listen(fd,5);
//
// clientlen = sizeof(clientaddr);
// newfd = accept(fd,(struct sockaddr*)&clientaddr,
//         &clientlen);
//
//
// read(newfd,...);
// write(newfd,...);
// close(fd); close(newfd);
