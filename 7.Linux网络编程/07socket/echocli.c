#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

#define ERR_EXIT(m) \
        do \
        { \
                perror(m); \
                exit(EXIT_FAILURE); \
        } while(0)

int main(void)
{
	int sock;
	if ((sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0)//创建一个TCP协议套接字
		ERR_EXIT("socket");

	//设置要连接的服务端的IP地址
	struct sockaddr_in servaddr;
	memset(&servaddr, 0, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(5188);
	servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	
	
	//连接服务端
	if (connect(sock, (struct sockaddr*)&servaddr, sizeof(servaddr)) < 0)
		ERR_EXIT("connect");

	char sendbuf[1024] = {0};
	char recvbuf[1024] ={0};
	//获取stdin输入流，并将输入的内容写入sendbuf
	while (fgets(sendbuf, sizeof(sendbuf), stdin) != NULL)
	{
		//向服务器发送数据
		write(sock, sendbuf, strlen(sendbuf));
		//获取从服务器发回的数据
		read(sock, recvbuf, sizeof(recvbuf));
        //输出获取的数据
		fputs(recvbuf, stdout);
		//清空接收和发送的内容
		memset(sendbuf, 0, sizeof(sendbuf));
		memset(recvbuf, 0, sizeof(recvbuf));
	}
    //关闭套接字
	close(sock);
	
	return 0;
}
