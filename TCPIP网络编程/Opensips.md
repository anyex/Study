一.Opensips 变量





| 变量名称    | 含义                                                         |
| ----------- | ------------------------------------------------------------ |
| af          | SIP消息的地址协议是IPV4还是IPV6                              |
| dst_ip      | 接收到的opensips的IP                                         |
| dst_port    | 接收到的opensips的端口                                       |
| form_uri    | SIP消息中的From头                                            |
| method      | SIP的方法类型 （method=="REGISTER"）                         |
| msg:len     | sip消息长度                                                  |
| proto       | SIP的传输类型，UDP/TCP                                       |
| to_uri      | SIP中的From的值                                              |
| ai          | request中的P-Asserted-Identity header                        |
| ar          | Authorization时的Proxy-Authorization                         |
| au          | Authorization或Proxy-Authorization中的username部分           |
| ad          | Authorization或Proxy-Authorization中的domain部分             |
| an          | Authorization或Proxy-Authorization中的onnce部分              |
| auth.resp   | Authorization or Proxy-Authorization header的返回值          |
| ci          | sip消息中的call-id                                           |
| cl          | sip消息中的content-length                                    |
| ct          | h获取第一个contact头域                                       |
| ct.fields() | 获取contact中的值(支持name,uri,q,expires,methods,recevied,params) |
| du          | 获取目的uri                                                  |
| fu          | 获取uri中的‘From’                                            |
| fU          | 获取fu中的username                                           |
| oP          |                                                              |
|             |                                                              |
|             |                                                              |
|             |                                                              |
|             |                                                              |
|             |                                                              |
|             |                                                              |
|             |                                                              |

