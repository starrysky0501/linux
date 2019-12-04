////实现以Udpsocket类封装udp常用操作
//#include <iostream>
//#include <string>
//#include <errno.h>    //error      
//#include <stdio.h>    //perror
//
//#include <sys/socket.h>        
//#include <netinet/in.h>     //sockaddr_in这个结构体在这个头文件里
//#include <arpa/inet.h>      //htons,inet_addr函数的头文件
//#include <unistd.h>         //close函数
//class Udpsocket
//{
//public:
//	Udpsocket() :_sock(-1){}
//	~Udpsocket(){}
//	bool Socket()
//	{
//		_sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
//		if (_sock<0)
//		{
//			perror("socket error");
//			return false;
//		}
//		return true;
//	}
//
//	bool Bind(std::string &ip, uint16_t port)
//	{
//		struct sockaddr_in addr;
//		addr.sin_family = AF_INET;
//		addr.sin_port = htons(port);
//		addr.sin_addr.s_addr = inet_addr(ip.c_str());              //将字符串的点分十进制ip地址转化为网络字节序的整数ip地址
//		socklen_t len = sizeof(struct sockaddr_in);
//		int ret = bind(_sock, (struct sockaddr*)&addr, len);
//		if (ret<0)
//		{
//			perror("bind error");
//			return false;
//		}
//		return true;
//	}
//	bool Recv(std::string &buf, struct sockaddr_in *saddr)
//	{
//		char tmp[1500] = { 0 };      //MTU
//		socklen_t len = sizeof(struct sockaddr_in);
//		int ret = recvfrom(_sock, tmp, 1500, 0, (struct sockaddr*)saddr, &len);
//		if (ret<0)
//		{
//			perror("recvfrom error");
//			return false;
//		}
//		buf.assign(tmp, len);   //从tmp中拷贝指定长度的数据到buf中，buf其实是一个指针，会自己申请一个len大小的空间
//		return true;
//	}
//	bool Send(std::string &buf, struct sockaddr_in *daddr)     //不建议使用string,遇到\0停止
//	{
//		socklen_t len = sizeof(struct sockaddr_in);
//		int ret = sendto(_sock, buf.c_str(), buf.size(), 0, (struct sockaddr*)daddr, len);
//		if (ret<0)
//		{
//			perror("send error");
//			return false;
//		}
//		return true;
//	}
//	bool Close()
//	{
//		close(_sock);
//		_sock = -1;
//		return true;
//	}
//private:
//	int _sock;
//};
//
////gg=G:从首行到尾行全文对齐；gg = shift g
////inet_addr函数：参数是char*,不能是string
////在早期的32操作系统中,long就是4个字节，64位的数据用户自己实现从主机字节序转换到网络字节序
////htons：自带判断我们的主机字节序，如果是小端，转化；如果是大端，什么都不做
////数字的字节序转换：主机字节序转换为网络字节序
//
