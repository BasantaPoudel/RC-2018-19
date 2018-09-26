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
    int nbytes, nleft, nwritten, nread;
    char *ptr, buffer[128];

fd=socket(AF_INET,SOCK_STREAM,0); // TCP SOCKET
if(fd==-1)exit(1);//error

// hostptr=gethostbyname("basanta-UX430UQ");
memset((void*)&addr,(int)'\0',sizeof(addr));
addr.sin_family = AF_INET;
addr.sin_addr.s_addr = (INADDR_ANY);
addr.sin_port = htons(PORT);

n=connect(fd,(struct sockaddr*)&addr,sizeof(addr));
if(n==-1)exit(1);//error

ptr=strcpy(buffer,"Hello\n");
nbytes=7;
nleft=nbytes;

      while (nleft>0) {nwritten=write(fd,ptr,nleft);
        if(nwritten<=0)exit(1);
        nleft-=nwritten;
        ptr+=nwritten;
      }
  nleft=nbytes;
  ptr=&buffer[0];
      while (nleft>0) {nread=read(fd,ptr,nleft);
        if(nread==-1)exit(1);
        else if(nread==0)break;
        nleft-=nread;
        ptr +=nread;
      }
nread=nbytes-nleft;
close(fd);
write(1,"echo: ",6);//stdout
write(1,buffer,nread);//stdout
exit(0);
}
