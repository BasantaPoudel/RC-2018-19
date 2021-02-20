//test.c
#include <stdlib.h>
#include <stdio.h>
#include <sys/socket.h>
#include <netdb.h>
#include <sys/socket.h> /* for AF_INET */
#include <arpa/inet.h>


#include <unistd.h>
#include <netdb.h>

#define PORT 58000
#define MAX 80


int main(void)
  {
    int fd,n;
    struct hostent *hostptr;
    struct sockaddr_in addr;
    char buffer[128];
    int addrlen;
    struct hostent *h;
    //char msg[MAX],

  	fd = socket(AF_INET, SOCK_DGRAM, 0);
  //	memset((void*) &addr, (int) '\0', sizeof(addr));
  	addr.sin_family = AF_INET;
  	addr.sin_addr.s_addr = htonl(INADDR_ANY);
  	addr.sin_port = htons((u_short) PORT);
  	bind(fd, (struct sockaddr*) &addr, sizeof(addr));
// (network to host short)
addrlen=sizeof(addr);
n=recvfrom(fd,buffer,128,0,(struct sockaddr*)&addr,&addrlen);
if(n==-1)exit(1);//error
/* ... */
write(1,"echo: ", 6); //stdout
write(1,buffer, n); //stdout

h=gethostbyaddr((char*)&addr.sin_addr,sizeof(struct in_addr),AF_INET);

if(h==NULL)
     printf("sent by [%s:%hu]\n",inet_ntoa(addr.sin_addr),ntohs(addr.sin_port));
else printf("sent by [%s:%hu]\n",h->h_name,ntohs(addr.sin_port));

close(fd);
exit(0);
}


// $ make
// gcc test.c -o test
// $ ./test
// echo: Hello!
// sent by [tejo.ist.utl.pt:8001]
// $

// #include <arpa/inet.h>
// uint16_t ntohs(uint16_t netshort);
