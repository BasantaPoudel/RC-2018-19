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

int main(void){
  int fd,addrlen,newfd;
  int n,nw;
  int nbytes, nleft, nwritten, nread;
  char *ptr, buffer[128];
  struct hostent *hostptr;
  struct sockaddr_in addr;

 if((fd=socket(AF_INET,SOCK_STREAM,0))==-1){
   printf("Not created\n" );
 exit(1);} // TCP SOCKET

 hostptr=gethostbyname("basanta-UX430UQ");

 memset((void*)&addr,(int)'\0',sizeof(addr));
 addr.sin_family = AF_INET;
 addr.sin_addr.s_addr = htonl(INADDR_ANY);
 addr.sin_port = htons((u_short)PORT);

 if(bind(fd,(struct sockaddr*)&addr,sizeof(addr))==-1){
   printf("could not create bind socket\n");
  exit(1);}

 if(listen(fd,5)==-1){
   printf("could not create listen socket\n");
  exit(1);}

 while (1) {addrlen=sizeof(addr);
   if ((newfd=accept(fd,(struct sockaddr*)&addr,&addrlen))==-1)
      exit(1);
  while ((n=read(newfd,buffer,128))!=0){if(n==-1)exit(1);
    ptr=&buffer[0];
    while (n>0){if((nw=write(newfd,ptr,n))<=0)exit(1);
      n-=nw;ptr+=nw;}
    }
   printf("%s\n",buffer);
   close(fd);
   close(newfd);
   }
   exit(0);
 }
