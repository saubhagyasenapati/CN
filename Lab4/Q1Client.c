/*				THE CLIENT PROCESS

	Please read the file server.c before you read this file. To run this,
	you must first change the IP address specified in the line:

		serv_addr.sin_addr.s_addr = inet_addr("144.16.202.221");

	to the IP-address of the machine where you are running the server.
*/

#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<fcntl.h>
#include<string.h>
int main()
{
  int i,sockfd,a,b,p=6,q=7,r;
  char buf[100];
  struct sockaddr_in sa;

/* Opening a socket is exactly similar to the server process */
  sockfd=socket(AF_INET,SOCK_STREAM,0);

/* Recall that we specified INADDR_ANY when we specified the server
address in the server. Since the client can run on a different
machine, we must specify the IP address of the server. 

TO RUN THIS CLIENT, YOU MUST CHANGE THE IP ADDRESS SPECIFIED
BELOW TO THE IP ADDRESS OF THE MACHINE WHERE YOU ARE RUNNING
THE SERVER.*/
  sa.sin_family=AF_INET;
  sa.sin_addr.s_addr=inet_addr("127.0.0.1"); //Loop back IP address
  sa.sin_port=60018;

/* With the information specified in serv_addr, the connect()
system call establishes a connection with the server process.*/
  i=connect(sockfd,(struct sockaddr *)&sa,sizeof(sa));

/* After connection, the client can send or receive messages.
However, please note that recv() will block when the
server is not sending and vice versa. Similarly send() will
block when the server is not receiving and vice versa. For
non-blocking modes, refer to the online man pages.*/
for(i=0; i < 100; i++) buf[i] = '\0';
	recv(sockfd, buf, 100, 0);
	printf("%s\n", buf);

	for(i=0; i < 100; i++) buf[i] = '\0';
    printf("Enter the Roll number\n");
    int flag;
    int rollno;
    char name[50];
    int marks[5];
    scanf("%d", &rollno);
     send(sockfd, &rollno, 4, 0);
     recv(sockfd, &flag, 4, 0);
    recv(sockfd, &rollno, 4, 0);
    recv(sockfd, name, 50, 0);
    recv(sockfd, marks, 20, 0);
    
    if(flag==0)
    {
        printf("Student Not Found");
    }
    else
    {
   
    printf("Student details are:\n");
    printf("Roll NO:%d\n",rollno);
    printf("Name:%s\n",name);
    printf("Marks are %d,%d,%d,%d,%d\n",marks[0],marks[1],marks[2],marks[3],marks[4]);
    printf("\n");
    }
 
	
close(sockfd);

}