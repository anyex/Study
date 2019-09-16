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

ssize_t readn(int fd, void *buf, size_t count)
{
        size_t nleft = count;
        ssize_t nread;
        char *bufp = (char*)buf;

        while (nleft > 0)
        {
                if ((nread = read(fd, bufp, nleft)) < 0)
                {
                        if (errno == EINTR)
                                continue;
                        return -1;
                }
                else if (nread == 0)
                        return count - nleft;

                bufp += nread;
                nleft -= nread;
        }

        return count;
}

ssize_t writen(int fd, const void *buf, size_t count)
{
        size_t nleft = count;
        ssize_t nwritten;
        char *bufp = (char*)buf;

        while (nleft > 0)
        {
                if ((nwritten = write(fd, bufp, nleft)) < 0)
                {
                        if (errno == EINTR)
                                continue;
                        return -1;
                }
                else if (nwritten == 0)
                        continue;

                bufp += nwritten;
                nleft -= nwritten;
        }

        return count;
}

ssize_t recv_peek(int sockfd, void *buf, size_t len)
{
        while (1)
        {
                int ret = recv(sockfd, buf, len, MSG_PEEK);//返回的接收数据不会被删除，下次调用recv还能接收到已经返回的数据
                if (ret == -1 && errno == EINTR)//如果被信号中断，重新接收
                        continue;
                return ret;
        }
		//这个函数主要是判断是否有数据可以接收，可接收的缓冲有多大
}

//按行读取
ssize_t readline(int sockfd, void *buf, size_t maxline)
{
        int ret;
        int nread;//读取的字节数
        char *bufp = buf;
        int nleft = maxline;//可读取的最大字节数
        while (1)
        {
                ret = recv_peek(sockfd, bufp, nleft);
                if (ret < 0)//说明没有数据可以接收
                        return ret;
                else if (ret == 0)//对方关闭了套接口
                        return ret;

                nread = ret;//接收到的字节数
				
                int i;
                for (i=0; i<nread; i++)//判断接收到的内容中是否有'\n'
                {
                        if (bufp[i] == '\n')
                        {
                                ret = readn(sockfd, bufp, i+1);//将数据从缓冲区移除
                                if (ret != i+1)
                                        exit(EXIT_FAILURE);

                                return ret;
                        }
                }
				
				//如果没有'\n'说明一条消息没有读取结束
                if (nread > nleft)//不允许超过剩余的字节数
                        exit(EXIT_FAILURE);

                nleft -= nread;
                ret = readn(sockfd, bufp, nread);
                if (ret != nread)
                        exit(EXIT_FAILURE);

                bufp += nread;//移动指针，下次读取的内容放到末尾
        }

        return -1;
}

int main(void)
{
	int sock;
	if ((sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0)
		ERR_EXIT("socket");

	struct sockaddr_in servaddr;
	memset(&servaddr, 0, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(5188);
	servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");

	if (connect(sock, (struct sockaddr*)&servaddr, sizeof(servaddr)) < 0)
		ERR_EXIT("connect");

	struct sockaddr_in localaddr;
	socklen_t addrlen = sizeof(localaddr);
	if (getsockname(sock, (struct sockaddr*)&localaddr, &addrlen) < 0)
		ERR_EXIT("getsockname");

	printf("ip=%s port=%d\n", inet_ntoa(localaddr.sin_addr), ntohs(localaddr.sin_port));


	char sendbuf[1024] = {0};
	char recvbuf[1024] = {0};
	while (fgets(sendbuf, sizeof(sendbuf), stdin) != NULL)
	{
		writen(sock, sendbuf, strlen(sendbuf));

		int ret = readline(sock, recvbuf, sizeof(recvbuf));
                if (ret == -1)
                        ERR_EXIT("readline");
                else if (ret == 0)
                {
                        printf("client close\n");
                        break;
                }

		fputs(recvbuf, stdout);
		memset(sendbuf, 0, sizeof(sendbuf));
		memset(recvbuf, 0, sizeof(recvbuf));
	}

	close(sock);
	
	return 0;
}
