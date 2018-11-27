#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define BUF_SIZ 4096
foo()
{
	int a=12;
	return a;
}
int main(int argc, char* argv[])
{
	int sock;
	struct sockaddr_in serv_addr;
	unsigned char recv[BUF_SIZ];
	unsigned char send[BUF_SIZ];
	int str_len;
	
	if(argc !=3)
	{
		printf("Usage: %s <IP> <port>\n",argv[0]);
		exit(1);
	}
	sock = socket(PF_INET,SOCK_STREAM,0);
	if(sock == -1)
	{
		printf("socket() error");
		return -1;
	}
	
	memset(&serv_addr,0,sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
	serv_addr.sin_port = htons(atoi(argv[2]));
	
	if(connect(sock,(struct sockaddr*)&serv_addr,sizeof(serv_addr)) == -1)
	{
		printf("connect() error");
		return -1;
	
	}

	system("clear");
	memset(&send,0,BUF_SIZ+1);
	memcpy(send,foo,1024);
	
	for(int i=0;i<1024;i++)
	{
		printf("%02x ", send[i]);
	}	
	printf("\n");
	for(int i=0;i<1024;i++)
	{
		send[i] += 2;
	}
	write(sock,send,1024);

	str_len = read(sock,recv,sizeof(recv)-1);
	printf("%d\n", str_len);
	if(str_len == -1)
	{
		printf("read() error");
		return -1;
	}
	close(socket);
	return 0;
}
