#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define true 1
#define false 0

bool
resolve_host (const char *host, sa_family_t family, char *addrstr, int size)
{
  struct addrinfo hints, *res;
  int errcode;
  void *ptr;


  if (family != AF_INET && family != AF_INET6) {
      return false;
  }

  // If size of input is less than INET_ADDRSTRLEN return
  if (family == AF_INET && size < INET_ADDRSTRLEN) {
      return false;
  } else if (family == AF_INET6 && size < INET6_ADDRSTRLEN) {
      return false;
  }

  memset (&hints, 0, sizeof (hints));
  hints.ai_family = family;
  hints.ai_socktype = SOCK_STREAM;
  hints.ai_flags |= AI_CANONNAME;

  errcode = getaddrinfo (host, NULL, &hints, &res);
  if (errcode != 0)
    {
      perror ("getaddrinfo");
      return false;
    }

  if (res) {

      switch (res->ai_family)
        {

        case AF_INET:
          ptr = &((struct sockaddr_in *) res->ai_addr)->sin_addr;
          break;

        case AF_INET6:
          ptr = &((struct sockaddr_in6 *) res->ai_addr)->sin6_addr;
          break;
        }

      // Convert numeric ip to dotted decimal string format
      inet_ntop (res->ai_family, ptr, addrstr, size);

      res = res->ai_next;
    }

  // Make sure to free up the response returned by getaddrinfo
  freeaddrinfo(res); 
 
  return true;
}

int main (void)
{
  char inbuf[256] =  "172.22.10.22.nip.io";
  char ipaddr[INET_ADDRSTRLEN];

  scanf("%s", inbuf);
  if (resolve_host (inbuf, AF_INET, ipaddr, sizeof(ipaddr))) {
      printf("\nResolved host is %s\n", ipaddr);
  } else {
      printf("\nDns Resolution failed\n");
  }
}
