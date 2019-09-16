



# 						TCP/IP网络编程

## IP和端口

 		**TCP和UDP套接字不共用端口**。即如果TCP套接字使用了9000端口，则其他TCP套接字就无法使用该端口号，但是UDP套接字可以使用。

​		**数据传输目标地址同时包含地址和端口号，才能被正确传输**

### 地址信息的表示

​		即包括地址族，IP地址，端口。

~~~c
struct sockaddr_in
{
    sa_family_t 	sin_family;//地址族 
    uint16_t 		sin_Port;//16位TCP/UDP端口号
    struct in_addr 	sin_addr;//32位IP地址
    char 			sin_zero[8];//不使用
}

//其中in_addr

struct in_addr
{
    In_addr_t		s_addr;//32位IPv4地址 			    
}
~~~

对于sin_family

| 地址(Address Family) | 含义                           |
| -------------------- | ------------------------------ |
| AF_INET              | IPv4网络协议种使用的地址       |
| AF_INET6             | IPv6网络协议中使用的地址       |
| AF_LOCAL             | 本地通信中采用的UNIX协议地址族 |

sin_prot

该成员保留16位端口号，以网络字节序保存

sin_addr

保存32位IP地址信息，也以网络字节序保存



### 网络字节序与地址变换

#### 字节序

CPU向内存保存数据的方式有两种：

​		大端序：高位字节存放到低位地址

​		小端序：高位字节存放到高位地址

如在0x20地址开始时保存4字节int类型0x12345678



|      |      |      |      |      |
| ---- | ---- | ---- | ---- | ---- |
| 地址 | 0x20 | 0x21 | 0x22 | 0x23 |
| 大端 | 0x12 | 0x34 | 0x56 | 0x78 |
| 小端 | 0x78 | 0x56 | 0x34 | 0x12 |

为了兼容不同的大小端系统，就约定在网络数据传输时统一位大端序(网络字节序)；

Intel和AMD的CPU都采用小端字节序

~~~c
//常用字节序转换函数
unsigned short htons(unsigned short); //把short类型数据从主机字节序转换位网络字节序
unsigned short ntohs(unsigned short);//把short类型从网络字节序转换为主机字节序
unsigned short htonl(unsigned long);
unsigned short ntohl(unsigned long);

~~~

* htons h代表主机字节序
* ntohs n代表网络字节序

所以  **htons**   即h ,to,n,s的组合，把short类型数据从主机字节序转换位网络字节序



#### 网络地址的初始化与分配

~~~c
#include <arpa/inet.h>
in_addr_t inet_addr(const char* string);
//成功时返回32位大端序整型数值，失败时返回INADDR_NONE,传入参数位点分十进制

int inet_aton (const char* string,struct in_addr* addr);
//成功返回1，失败返回0
//string  需要转换的IP地址信息的字符串地址值
//addr    将保存转换结果的in_addr结构体变量的地址值

char* inet_ntoa(struct in_addr addr);
//将网络字节序整数型IP地址转换成字符串形式

~~~

~~~ c
//网络地址初始化

服务端

struct sockaddr_in addr;
char * serv_ip = "192.168.1.135";
char * server_port = "9000";
memset(&addr,0,sizeof(addr));
addr.sin_family = AF_INET;
//addr.sin_addr.s_addr = inet_addr(serv_ip);
//可以使用INADDR_ANY来设置服务端IP,就能自动获取服务端IP(若多网卡则需要指定IP)
addr.sin_addr.s_addr=htonl(INADDR_ANY);
addr.sin_port = htons(atoi(serv_port));

~~~

#### 向套接字分配IP

调用bind函数将sockaddr_in分配给套接字

~~~c
#include <sys/socket.h>
int bind(int sockfd,struct sockaddr * myaddr,socklen_t addrlen);
//成功返回0，失败返回-1
~~~



## 基于TCP的服务端/客户端

### TCP和UDP

+ TCP面向连接，基于流
+ UDP面向消息

### TCP/IP协议栈

~~~mermaid

graph TD
A(应用层)---B(TCP层)
A---C
C(UDP层)
D(IP层)
E(链路层)
B---D
C---D
D---E
~~~

#### 链路层

链路层负责LAN,WAN,MAN等网络标准，即处理网络的物理连接(网线，路由器等)

#### IP层

IP层考虑网络中的数据传输路径，IP本身面向消息，不可靠，每次传输时选择路径，但不一定一致，如果路径发生网络错误，则选择其他路径，如果发送数据丢失或错误，则无法解决

#### TCP/UPD层

TCP和UDP以IP层提供的路径信息为基础完成实际的数据传输。

IP层只关注1个数据包的传输过程，因此即使传输多个数据包，每个数据包也是由IP层实际传输。

TCP传输控制协议：

~~~sequence

主机A-->主机B:1号数据包
主机B-->主机A:1号数据包OK
主机A-->主机B:2号数据包
主机B-->主机A:2号数据包OK

主机A-->主机B:3号数据包
主机A-->主机B:3号数据包超时
主机A-->主机B:3号数据包
主机B-->主机A:3号数据包OK
~~~

#### 应用层

应用层主要是考虑服务端和客户端数据传输协议，网络编程的大部分内容就是设计并实现应用层协议



### TCP服务器端的默认函数调用函数

TCP 连接过程

![1567959342183](C:\Users\Jth\Documents\1567959342183.png)

#### listen

调用了listen函数，客户端才能进入可发出连接请求的状态。这时客户端才能调用connect函数(若提前调用将发生错误)

~~~c
#include <sys/socket.h>
int listen(int sock,int backlog)
//成功返回0，失败-1
~~~

+ sock	希望进入等待连接请求的套接字文件描述符
+ backlog 连接请求等待队列的长度，若为5，表示最多5个连接请求进入队列

#### accept

~~~ c
#include <sys/socket.h>
int accept(int sock,struct sockaddr* addr,scoklen_t* addrlen);
~~~

+ sock 服务器套接字的文件描述符

+ addr 保存发起连接请求的客户端地址信息的变量地址值

  

调用成功就返回已经连接成功的客户端的套接字。

#### connect

用于客户端套接字向服务端发起连接请求

~~~c
#include <sys/socket.h>
int connect(int sock,struct sockaddr*servaddr,socklen_t addrlen)
//成功时返回0,失败时返回-1
~~~

调用connect后，发生一下情况才返回

+ 服务端接收连接请求(服务端把连接请求信息记录到等待队列)
+ 发生断网等异常情况而中断连接请求

客户端的IP和端口在调用connect函数时自动分配，无需调用标记的bind函数进行分配



## TCP原理

### TCP套接字中的I/O缓冲

TCP套接字的数据收发无边界。write函数调用瞬间，数据将移至输出缓冲,read函数调用瞬间,从输入缓冲读取数据

I/O 缓冲：

+ I/O 缓冲在每个TCP套接字中单独存在
+ I/O 缓冲在创建套接字时自动生成
+ 关闭套接字也会继续传递输出缓冲中遗留的数据
+ 关闭套接字将丢失输入缓冲中的数据

###  TCP三次握手

~~~sequence
主机A-->主机B:SYN(SEQ:1000 ACK:-)
主机B-->主机A:SYN+ACK(SEQ:2000 ACK:1001)
主机A-->主机B:ACK(SEQ:1001  ACK:2001)

~~~

套接字以全双工方式工作，可以双向传递数据

[SYN] SEQ:1000,ACK:-

该消息中SEQ为1000,ACK为空,而SEQ为1000含义为:

​	现传递的数据包序号为1000,如果接收无误,请通知我向您传递1001号数据包

​	这是首次请求连接时使用的消息,又称为SYN,SYN是Synchronization的简写,表示收发数据前传输的同步消息,接下来主机B向A传递如下消息:

​	

[SYN+ACK] SEQ:2000, ACK:1001

此时SEQ为2000,ACK为1001

​	SEQ为2000的含义为：现传递的数据包序列号为2000,如果接收无误,请通知我向您传递2001号数据包

​	ACK 1001的含义为刚才传输的SEQ为1000的数据包接收无误,现在请传递SEQ为1001的数据包

​	这里对主机A首次传输的的数据包进行确认(ACK 1001)和为主机B传输数据作准备的同步消息(SEQ 2000)捆绑发送,因此消息类型为SYN+ACK

[ACK] SEQ:1001,ACK:2001

​	确认收到传输的SEQ为2000的数据包，现在可以传输SEQ为2001的数据包

至此,主机A和主机B确认了彼此均就绪



### TCP 数据交换

~~~sequence
主机A-->主机B:SEQ 1200,100 byte data
主机B-->主机A:ACK 1301
主机A-->主机B:SEQ 1301,100 byte data
主机B-->主机A:ACK 1402
~~~

上图为主机A分2次发送200字节的过程

主机A通过1个数据包发送了100个字节的数据,数据包的SEQ为1200,主机B为了确认这一点,向主机A发送ACK 1301消息

此时ACK号为1301而不是1201,原因在于ACK号的增量为传输的数据字节数。

​	ACK号=SEQ号+传递的字节数+1

与三次握手协议相同,最后加1是为了告知对方下次要传递的SEQ号

​	

### TCP断开与套接字的连接

套接字断开连接需要双方协商,断开连接时

先由套接字A向套接字B传递断开连接的消息,套接字B发出确认收到的消息,然后向套接字A传递可以断开连接的消息,套接字A同样发出确认消息

~~~sequence
主机A-->主机B:FIN(SEQ 5000,ACK -)
主机B-->主机A:ACK(SEQ 7500 ACK 5001)
主机B-->主机A:FIN(SEQ 7501 ACK 5001)
主机A-->主机B:ACK(SEQ 5001 ACK 7502)
~~~

其中FIN表示断开连接,双方各发送一次FIN消息后断开连接,主机B向主机A发送了两次ACK 5001,第二次FIN数据包中的ACK 5001是因为接收ACK消息后未接收数据而重传的



## 基于UDP的服务端和客户端

​	UDP最重要的作用就是根据端口号将主机的数据包交付到最终的UDP套接字一个UDP套接字就可以向任意主机传输数据



### 基于UDP的数据I/O函数

~~~c
#include <sys/socket.h>
ssize_t sendto(int sock,void *buff,size_t nbytes,int flags,
              struct sockaddr*to,socklen_t addrlen);
~~~

成功时返回传输的字节数,失败时返回-1

+ sock 用于传输数据的UDP套接字文件描述符

+ buff 保存待传输数据的缓冲地址值

+ nbytes 待传输的数据长度,以字节为单位

+ flags 可选项参数,若没有则传递0

+ to 存有目标地址信息的sockaddr 结构体变量的地址值

+ addrlen 传递给参数to的地址值结构体变量长度

  

~~~c
#include <sys/scoket.h>
ssize_t recvfrom(int sock,void*buff,size_t nbytes,int flags,
                struct sockaddr* from,socklen_t* addrlen)
~~~

成功时返回接收的字节数,失败时返回-1

+ sock 	用于接收数据的UDP套接字文件描述符
+ buff     保存接收数据的缓冲地址值
+ nbytes   可以接收的最大字节数
+ flags    可选项参数,若没有则传入0
+ from     存有发送端地址信息的sockaddr结构体变量的地址值
+ addrlen  保存参数from的结构体变量长度的变量地址值

​	

UDP是具有数据边界的协议,传输中调用I/O函数的次数非常重要,因此输入函数的调用次数和输出函数的调用次数完全一致,才能保证接收全部已发送数据



### 已连接UDP套接字和未连接UDP套接字

通过sendto函数传输数据

+ 向UDP套接字注册目标IP和端口号
+ 传输数据
+ 删除UDP套接字中注册的目标地址信息

每次调用sendto函数时需要重复上述过程,每次都变更目标地址,因此可以重复利用同一UDP套接字向不同目标传输数据，这种未注册目标地址信息的套接字称为未连接套接字,反之,注册了目标地址的套接字称为connected套接字

### 创建已连接UDP套接字

创建已连接UDP套接字，只需要针对UDP套接字调用connect函数

~~~c
scoket = scoket(PF_INET,SOCK_DGRAM,0);
memset(&addr,0,sizeof(addr));
addr.sin_family=AF_INET;
addr.sin_addr.s_addr=....
addr.sin_port=....
connect(sock,(struct sockaddr*)&addr,sizeof(addr));
~~~



## 断开套接字连接

### 基于TCP的半关闭

如果直接关闭连接将会导致无法再调用接收或发送的函数，则最后必须接收发送的数据也被销毁了,所以常使用半关闭的方法，即可以传输数据但无法接收或可以接收但无法传输



### 套接字和流

两台主机之间建立了套接字连接,每个主机就会拥有单独的输入流和输出流,一台主机的输入流和另外一台的输出流相连,而输出流和另外一台主机的输入流相连

### shutdown函数

~~~c
#include <sys/socket.h>
int shutdown(int sock,int howto);//成功返回0,失败返回-1

~~~

+ sock 	需要断开的套接字的文件描述符

+ howto	传递断开方式的信息

  ​		 SHUT_RD    断开输入流

  ​		 SHUT_WR	断开输出流

  ​		 SHUT_RDWR  同时断开I/O流





## 域名及网络地址

提供网络服务的服务器端都是通过IP地址区分,将容易记,容易表述的域名分配并取代IP地址

所有计算机中都记录着默认的DNS服务器地址，通过这个默认的DNS服务器可以得到相应域名的IP信息



### IP地址和域名的转换

~~~ c
#include <netdb.h>
struct hostnet * gethostbyname(const char* hostname);
//成功时返回hostent结构体地址,失败返回NULL

struct hostnet{
    char *h_name;//官方域名
    char *h_aliases;//同一IP可以绑定多个域名,除官方域名外的其他域名
    int h_addrtype;//如果是IPv4,则该变量为AF_INET
    int h_length;//地址长度
    char** h_addr_list;//IP地址,有些网站可能分配多个IP给同一域名
    
}


struct hostnet* gethostbyaddr(const char*addr,socklen_t len,int family);
//成功返回hostnet结构体的变量地址值,失败返回NULL

~~~





## 套接字选项和I/O缓冲大小

套接字的可选项的读取和设置通过如下函数完成

~~~c
#include <sys/socket.h>
int getsockopt(int sock,int level,int optname,void *optval,socklen_t *optlen);
~~~

+ sock	用于查看选项套接字的文件描述符

+ level   要查看的可选项的协议层

+ optname 要查看的可选项名

+ optval  保存查看结果的缓冲地址值

+ optlen  传递的缓冲大小

  ​	

~~~ c
#include <sys/socket.h>
int setsockopt(int sock,int level,int optname,const void *optval,socklen_t optlen);

~~~

+ 成功返回0,失败返回-1

+ optname 要更改的可选项名

+ optval  保存要更改的选项信息的缓冲地址值

+ optlen  可选项信息的字节数

  

### 套接字可选项

#### SO_SNDBUF & SO_RCVBUF

SO_SNDBUF是输入缓冲大小的相关可选项,SO_SNDBUF是输出缓冲大小相关可选项

#### SO_REUSEADDR

~~~ sequence
主机A-->主机B:FIN(SEQ 5000, ACK -)
主机B-->主机A:ACK(SEQ 7500, ACK 5001)
主机B-->主机A:FIN(SEQ 7501，ACK 5001)
主机A-->主机B:ACK(SEQ 5001, ACK 7502)
主机A-->主机A:Time-WAIT
~~~



套接字收到FIN消息后,并非马上消除,需要经过一段实际的TIME-WAIT状态

为什么需要time-wait

加上主机A向主机B传输ACK消息(SEQ 5001,ACK 7502)后马上消除套接字,但这条ACK消息在传递途中丢失,未能传递给主机B，这时主机B会认为之前发送的FIN(SEQ 7501,ACK 5001)未能成功发送,继而试图重传,但此时主机A已经是完全终止的状态,因此主机B永远无法收到从主机A最后传递来的ACK消息,但是若是处在Time-wait,则主机A会向主机B重传最后的ACK消息,主机B也能正常终止



##### 地址再分配

当处于TIME_WAIT状态时,如果需要进行重新连接则需要等待几分钟,解决办法就是在套接字的可选项中更改SO_REUSEADDR的状态,适当调整该参数,可将TIME_WAIT状态下的套接字端口号重新分配给新的套接字,SO_RESUSEADDR的默认值未0,意味着无法分配TIME_WAIT状态下的套接字端口号,需要修改为1



#### TCP_NODELAY

##### Nagle算法

收到前一数据的ACK消息时,Nagle算法才发送下一条数据

~~~ sequence
主机A-->主机B:data 'N'
主机B-->主机A:ACK 'N'
主机A-->主机B:data 'agle'
主机B-->主机A:ACK 'agle'
~~~

为了发送“Nagle”,将其传递到输出缓冲,这时头字符“N”之前没有其他数据,立即传输,之后开始等待‘N’的ACK消息,等待过程中,剩下的“agle”填入输出缓冲,接下来,收到字符“N”的ACK消息后,将输出缓冲的“agle”装入一个数据发送

这将大大降低网络带宽

在传输大文件数据时,将文件数据传入输出缓冲不会花太多时间,不使用Ngale算法也会在装满输出缓冲时传输数据包,这不仅不会增加数据包数量,也不需要等待ACK连续传输,这将大大提高传输速度

将TCP_NODELAY改为1即可禁用Nagle算法,默认开启

