
//Get host name
//test.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <string.h>

#include <unistd.h>
int gethostname(char *name,size_t len);

char *strerror(int errnum);

extern int errno;

int main(void)
{
char buffer[128];

if(gethostname(buffer,128)==-1)
  printf("error: %s\n",strerror(errno));
else printf("host name: %s\n",buffer);
exit(0);
}
