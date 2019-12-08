////封装TcpSocket类，通过实例化的tcpsocket对象，来实现数据的通信（向外提供简单的接口）
//
//#ifndef __M_TCP_H__       //防止头文件重复包含
//#define __M_TCP_H__
//
//#include<iostream>             //标准输入输出流
//#include<string>               //string
//#include<stdio.h>              //perror函数
//
//#include<sys/socket.h>         //套接字接口的头文件
//#include<netinet/in.h>         //struct sockaddr_in结构体，这个头文件包含各种地址结构
//#include<arpa/inet.h>          //inet_addr函数
//#include<unistd.h>             //close函数
//
//#define CHECK_RET(q) if((q)==false){return -1;}
//
//#define MAX_LISTEN 10     //这个数字通常不会设置很大，限制同一时间能接收的连接，而不是服务端的最大连接数
//class TcpSocket
//{
//public:
//	TcpSocket() :_sockfd(-1){}
//	//1.创建套接字
//	bool Socket()
//	{
//		_sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
//		if (_sockfd<0)
//		{
//			perror("socket error");
//			return false;
//		}
//		return true;
//	}
//	//2.绑定地址信息
//	bool Bind(const std::string &ip, const uint16_t port)
//	{
//		struct sockaddr_in addr;
//		MakeAddr(addr, ip, port);
//		socklen_t len = sizeof(struct sockaddr_in);
//
//		int ret = bind(_sockfd, (struct sockaddr*)&addr, len);
//		if (ret<0)
//		{
//			perror("bind perror");
//			return false;
//		}
//		return true;
//	}
//	//3.开始监听（服务端）
//	bool Listen(int backlog = MAX_LISTEN)
//	{
//		int ret = listen(_sockfd, backlog);
//		if (ret<0)
//		{
//			perror("listen error");
//			return false;
//		}
//		return true;
//	}
//	//3.发起连接请求（客户端）
//	bool Connect(const std::string &srvip, const uint16_t port)
//	{
//		struct sockaddr_in addr;
//		MakeAddr(addr, srvip, port);
//		socklen_t len = sizeof(struct sockaddr_in);
//		int ret = connect(_sockfd, (struct sockaddr*)&addr, len);
//		if (ret<0)
//		{
//			perror("connect error");
//			return false;
//		}
//		return true;
//	}
//	//4.获取新连接（服务端）
//	bool Accept(TcpSocket *sock, std::string *ip = NULL, uint16_t *port = NULL)  //用户如果不想获取地址，则需采用默认参数
//	{
//		struct sockaddr_in addr;
//		socklen_t len = sizeof(struct sockaddr_in);
//		//获取新连接描述符，并且获取这个新连接对应的客户端地址
//		int newfd = accept(_sockfd，(struct sockaddr*)&addr, &len);
//		if (newfd<0)
//		{
//			perror("accept error");
//			return false;
//		}
//		sock->_sockfd = newfd;
//		if (ip != NULL)
//		{
//			//inet_ntoa将网络字节序的整数IP转换为字符串
//			*ip = inet_ntoa(addr.sin_addr);
//		}
//		if (port != NULL)
//		{
//			*port = ntohs(addr.sin_port);
//		}
//		return true;
//	}
//	//5.接收数据
//	bool Recv(std::string &buf)
//	{
//		char tmp[4096] = { 0 };
//		int rlen = recv(_sockfd, tmp, 4096, 0);
//		if (rlen<0)
//		{
//			perror("recv error");
//			return false;
//		}
//		else if (rlen == 0)
//		{
//			std::cerr << "peer shutdown\n";
//			return false;
//		}
//		buf.assign(tmp, rlen);
//		return true;
//	}
//	//6.发送数据
//	bool Send(std::string &buf)
//	{
//		int ret = send(_sockfd, &buf[0], buf.size(), 0);
//		if (ret<0)
//		{
//			perror("send error");
//			return false;
//		}
//		return true;
//	}
//	//7.关闭套接字
//	bool Close()
//	{
//		close(_sockfd);
//		return true;
//	}
//private:
//	void MakeAddr(struct sockaddr_in &addr, const std::string &ip, const uint16_t port)  //给一个地址结构赋值
//	{
//		addr.sin_family = AF_INET;
//		addr.sin_port = htons(port);
//		addr.sin_addr.s_addr = inet_addr(ip.c_str());
//	}
//private:
//	int _sockfd;
//};
//
//#endif
