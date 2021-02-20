
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#define PORT 58000


int main(){
int fd, newfd, nbytes, nleft, nwritten, nread;
struct hostent *hostptr;
struct sockaddr_in serveraddr, clientaddr;
int clientlen;
char *ptr, buffer[128];

ptr=strcpy(buffer,"Hello!\n");
nbytes=7;
nleft=nbytes;
//TCP Client

fd=socket(AF_INET,SOCK_STREAM,0);
if (fd==-1) exit(1);
hostptr=gethostbyname("basanta-UX430UQ");

memset((void*)&serveraddr,(int)'\0', sizeof(serveraddr));
serveraddr.sin_family = AF_INET;
serveraddr.sin_addr.s_addr = ((struct in_addr *) (hostptr->h_addr_list[0]))->s_addr;
serveraddr.sin_port = htons((u_short)PORT);

connect(fd,(struct sockaddr*)&serveraddr, sizeof(serveraddr));

////READ WRITE
while(nleft>0){
      nwritten=write(fd,"hello",nleft);
      if(nwritten<=0)exit(1);//error
      nleft-=nwritten;
      ptr+=nwritten;
}

nleft=nbytes; ptr=&buffer[0];

while(nleft>0){
      nread=read(fd,ptr,nleft);
      if(nread==-1)exit(1);//error
      else if(nread==0)break;//closed by peer
      nleft-=nread;
      ptr+=nread;
}

nread=nbytes-nleft;
write(1,"echo: ",6);//stdout
write(1,buffer,nread);
close(fd);

exit(0);
}
