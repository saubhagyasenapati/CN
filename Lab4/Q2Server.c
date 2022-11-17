// 2.Create TCP socket through which two client can connect the  server.the first cleint will sent a number to the server and 
//server will forward that number to the se
// second client and the se cond client will sent the number to server then server will forward the number to the 1st client.

#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

int main()
{
int sockfd,fd1,fd2, length,i,x,y,sum;
char buf[100],p[3]; /* We will use this buffer for communication */
struct sockaddr_in sa,ta1;

sockfd=socket(AF_INET,SOCK_STREAM,0);

 sa.sin_family=AF_INET;
 sa.sin_addr.s_addr=INADDR_ANY;
 sa.sin_port=60010;


 i=bind(sockfd,(struct sockaddr *)&sa,sizeof(sa));
 printf("test %d%d\n",sockfd,i);

 listen(sockfd,5);



 length=sizeof(sa);
    fd1=accept(sockfd, (struct sockaddr *) &ta1,&length);
    fd2=accept(sockfd, (struct sockaddr *) &ta1,&length);


        for(i=0; i < 100; i++) buf[i] = '\0';
			strcpy(buf,"Message from server c1");
    send(fd1, buf, 100, 0);
    for(i=0; i < 100; i++) buf[i] = '\0';
    strcpy(buf,"Message from server c2");
    send(fd2, buf, 100, 0);


int l=5;
while(l--){
    for(i=0; i < 100; i++) buf[i] = '\0';
    recv(fd1, buf, 100, 0);
    send(fd2, buf, 100, 0);
    recv(fd2, buf, 100, 0);
    send(fd1, buf, 100, 0);
}

    close(fd1);
    close(fd2);

    return 0;

 }
