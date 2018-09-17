

//Get host name
//test.c

#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

//struct hostent{
//        char *h_name;
//        char **h_aliases;
//        int h_addrtype;
//        int h_length;
//        char **h_addr_list;
//};

//struct in_addr{
//u_int32_t     s_addr; // 32 bits
//};

struct hostent *gethostbyname(const char *name);
uint32_t ntohl(uint32_t netlong);
int main(void)
{
      struct hostent *h;
      struct in_addr *a;
      if((h=gethostbyname("tejo"))==NULL)exit(1);//error
      printf("official host name: %s\n",h->h_name);
      a=(struct in_addr*)h->h_addr_list[0];
      printf("internet address: %s (%08lX)\n",inet_ntoa(*a),(unsigned long) ntohl(a->s_addr));
      exit(0);
}

/*#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
char *inet_ntoa(struct in_addr in); */
