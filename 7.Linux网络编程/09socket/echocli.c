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

struct packet//定义数据包结构
{
        int len;
        char buf[1024];
};

	//接收count个字节数
ssize_t readn(int fd, void *buf, size_t count)
{
        size_t nleft = count;//剩余的接收字节数
        ssize_t nread;//接收到的字节数
        char *bufp = (char*)buf;

        while (nleft > 0)//只要剩余的字节数大于0，就应该继续读取
        {
                if ((nread = read(fd, bufp, nleft)) < 0)//如果读取字节数小于0，说明读取出错
                {
                        if (errno == EINTR)
                                continue;
                        return -1;
                }
                else if (nread == 0)//说明发送端关闭了发送操作
                        return count - nleft;

                bufp += nread;// 对读取的缓冲进行偏移
                nleft -= nread;// 还剩余的读取数
        }

        return count;
}

//发送count个字符
ssize_t writen(int fd, const void *buf, size_t count)
{
        size_t nleft = count;//待发送的字节数
        ssize_t nwritten;//接收的字节数
        char *bufp = (char*)buf;

        while (nleft > 0)
        {
                if ((nwritten = write(fd, bufp, nleft)) < 0)//说明发送出错
                {
                        if (errno == EINTR)//被其他信号中断
                                continue;
                        return -1;
                }
                else if (nwritten == 0)//什么都没发送过
                        continue;

                bufp += nwritten;//指针偏移
                nleft -= nwritten;//已发送的字节数
        }

        return count;
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


	struct packet sendbuf;
	struct packet recvbuf;
	memset(&sendbuf, 0, sizeof(sendbuf));
	memset(&recvbuf, 0, sizeof(recvbuf));
	int n;
	while (fgets(sendbuf.buf, sizeof(sendbuf.buf), stdin) != NULL)
	{
		n = strlen(sendbuf.buf);
		sendbuf.len = htonl(n);	
		writen(sock, &sendbuf, 4+n);


		int ret = readn(sock, &recvbuf.len, 4);
                if (ret == -1)
                        ERR_EXIT("read");
                else if (ret < 4)
                {
                        printf("client close\n");
                        break;
                }
                
                n = ntohl(recvbuf.len);
                ret = readn(sock, recvbuf.buf, n);
                if (ret == -1)
                        ERR_EXIT("read");
                else if (ret < n)
                {
                        printf("client close\n");
                        break;
                }


		fputs(recvbuf.buf, stdout);
		memset(&sendbuf, 0, sizeof(sendbuf));
		memset(&recvbuf, 0, sizeof(recvbuf));
	}

	close(sock);
	
	return 0;
}
