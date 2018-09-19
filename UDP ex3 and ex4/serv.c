#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>

#include <unistd.h>
#include <netdb.h>

#define PORT 58000
#define MAX 80


int main(void){
  int fd,n;
  struct hostent *hostptr;
  struct sockaddr_in addr;
  //int addrlen;
  //char msg[MAX],
  char buffer[128];

	fd = socket(AF_INET, SOCK_DGRAM, 0);

//	memset((void*) &addr, (int) '\0', sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = htonl(INADDR_ANY);
	addr.sin_port = htons((u_short) PORT);

	bind(fd, (struct sockaddr*) &addr, sizeof(addr));

	addrlen = sizeof(addr);

  n=recvfrom(fd, buffer, 128, 0, (struct sockaddr*) &addr, sizeof(addr));
  if(n==-1)exit(1);
  write(1,"echo: ", 6); //stdout
  write(1,buffer, n); //stdout

	// printf("%s\n", buffer);
	// sendto(fd, buffer, strlen(buffer), 0, (struct sockaddr*) &clientaddr, addrlen);

	close(fd);
  exit(0);
}
