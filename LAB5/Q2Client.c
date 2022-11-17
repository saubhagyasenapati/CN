/*
** A datagram "client" demo
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#define SERVERPORT 4952 // the port users will be connecting to
int main()
{
    int sockfd;
    struct sockaddr_in their_addr; // connector's address information
    // struct hostent *he;
    // struct sockaddr_in my_addr;
    socklen_t addr_len;

    int numbytes;
    char arg[30];
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) == -1)
    {
        perror("socket");
        exit(1);
    }
    their_addr.sin_family = AF_INET;         // host byte order
    their_addr.sin_port = htons(SERVERPORT); // short, network byte order
    their_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    // memset(their_addr.sin_zero, '\0', sizeof their_addr.sin_zero);
    int n;
    for (int i = 0; i < 2; i++)
    {
        printf("Enter integer no %d\n", i);
        scanf("%d", &n);
        if ((numbytes = sendto(sockfd, &n, sizeof(int), 0,
                               (struct sockaddr *)&their_addr, sizeof their_addr)) == -1)
        {
            perror("sendto");
            exit(1);
        }
        printf("sent %d bytes to %s\n\n", numbytes, inet_ntoa(their_addr.sin_addr));
    }
    /////////////////////
    if ((numbytes = recvfrom(sockfd, &n, sizeof(int), 0,
                             (struct sockaddr *)&their_addr, &addr_len)) == -1)
    {
        perror("recvfrom");
        exit(1);
    }

    printf("\nSUM RECIEVED = %d \n", n);

    printf("got packet from %s\n", inet_ntoa(their_addr.sin_addr));
    printf("packet is %d bytes long\n", numbytes);
    // buf[numbytes] = '\0';
    // printf("packet contains \"%d\"\n", n);

    close(sockfd);
    return 0;
}