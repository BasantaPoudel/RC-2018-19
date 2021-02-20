
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
	char *ptr, buffer[128];
	struct hostent *hostptr;
	struct sockaddr_in serveraddr, clientaddr;
	int clientlen;

	//TCP Server

	fd=socket(AF_INET,SOCK_STREAM,0);

	memset((void*)&serveraddr,(int)'\0', sizeof(serveraddr));
	serveraddr.sin_family = AF_INET;
	serveraddr.sin_addr.s_addr = htonl(INADDR_ANY);
	serveraddr.sin_port = htons((u_short)PORT);

	bind(fd,(struct sockaddr*)&serveraddr, sizeof(serveraddr));

	listen(fd,5);

	clientlen = sizeof(clientaddr);

	newfd = accept(fd,(struct sockaddr*)&clientaddr, &clientlen);
 printf("Got connection. \n");
	while(nleft>0) {nread = read(newfd, ptr, nleft);
					if(nread==-1) exit(1);
					else if(nread==0) break;
					nleft-=nread;
					ptr+=nread;
	}
	while(nleft>0){
	      nwritten=write(fd,ptr,nleft);
	      if(nwritten<=0)exit(1);//error
	      nleft-=nwritten;
	      ptr+=nwritten;
	}

	printf("%s\n", ptr);


	close(fd); close(newfd);
}
