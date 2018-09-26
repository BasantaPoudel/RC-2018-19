#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>

#define PORT 58000 // Port to be passed in htons

// struct sockaddr_in{
//   sa_family_t sin_family;
//   u_int16_t sin_port;
//   struct in_addr sin_addr;
// };
void *memset(void *s, int c, size_t n);
int socket(int domain, int type, int protocol);
ssize_t sendto(int s, const void *buf, size_t len, int flags, const struct sockaddr *to, socklen_t token);

int main(){
int fd, n;
struct sockaddr_in addr;
struct hostent *hostptr;
// int addrlen;
// char msg[80], buffer[80];
//UDP Client
fd=socket(AF_INET,SOCK_DGRAM,0); // UDP SOCKET //
if(fd==-1)exit(1);

hostptr=gethostbyname("basanta-UX430UQ");

memset((void*)&addr,(int)'\0', sizeof(addr));
addr.sin_family = AF_INET;
addr.sin_addr.s_addr = ((struct in_addr *)
      (hostptr->h_addr_list[0]))->s_addr;
addr.sin_port = htons((u_short)PORT);
//addrlen = sizeof(addr);

// Sends data to the Server EX 3
n=sendto(fd, "Hello!\n", 7, 0, (struct sockaddr*)&addr, sizeof(addr));
if(n==-1) exit(1);
close(fd);
exit(0);
}
