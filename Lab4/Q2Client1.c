#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<fcntl.h>
#include<string.h>
#include <unistd.h>
int main()
{
  int i,sockfd,a,b,p=6,q=7,r;
  char buf[100];
  struct sockaddr_in sa;
    sockfd=socket(AF_INET,SOCK_STREAM,0);

  sa.sin_family=AF_INET;
  sa.sin_addr.s_addr=inet_addr("127.0.0.1"); //Loop back IP address
  sa.sin_port=60010;

  i=connect(sockfd,(struct sockaddr *)&sa,sizeof(sa));

for(i=0; i < 100; i++) buf[i] = '\0';
	recv(sockfd, buf, 100, 0);
	printf("%s\n", buf);

    char t[100];
    for(i=0; i < 100; i++) t[i] = '\0';
    strcpy(t,"bye");
    for(i=0; i < 100; i++) buf[i] = '\0';
    while(1){
        char s[100];
        printf("Enter some data: ");
        scanf("%s",s);
        strcpy(buf,s);
        send(sockfd, buf, 100, 0);
        recv(sockfd, buf, 100, 0);
        printf("Client  : %s \n",buf);
        if(strcmp(buf, t) == 0){
  
            close(sockfd);
            break;
        }
    }

return 0;
 
}
