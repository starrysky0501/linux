////��װTcpSocket�࣬ͨ��ʵ������tcpsocket������ʵ�����ݵ�ͨ�ţ������ṩ�򵥵Ľӿڣ�
//
//#ifndef __M_TCP_H__       //��ֹͷ�ļ��ظ�����
//#define __M_TCP_H__
//
//#include<iostream>             //��׼���������
//#include<string>               //string
//#include<stdio.h>              //perror����
//
//#include<sys/socket.h>         //�׽��ֽӿڵ�ͷ�ļ�
//#include<netinet/in.h>         //struct sockaddr_in�ṹ�壬���ͷ�ļ��������ֵ�ַ�ṹ
//#include<arpa/inet.h>          //inet_addr����
//#include<unistd.h>             //close����
//
//#define CHECK_RET(q) if((q)==false){return -1;}
//
//#define MAX_LISTEN 10     //�������ͨ���������úܴ�����ͬһʱ���ܽ��յ����ӣ������Ƿ���˵����������
//class TcpSocket
//{
//public:
//	TcpSocket() :_sockfd(-1){}
//	//1.�����׽���
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
//	//2.�󶨵�ַ��Ϣ
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
//	//3.��ʼ����������ˣ�
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
//	//3.�����������󣨿ͻ��ˣ�
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
//	//4.��ȡ�����ӣ�����ˣ�
//	bool Accept(TcpSocket *sock, std::string *ip = NULL, uint16_t *port = NULL)  //�û���������ȡ��ַ���������Ĭ�ϲ���
//	{
//		struct sockaddr_in addr;
//		socklen_t len = sizeof(struct sockaddr_in);
//		//��ȡ�����������������һ�ȡ��������Ӷ�Ӧ�Ŀͻ��˵�ַ
//		int newfd = accept(_sockfd��(struct sockaddr*)&addr, &len);
//		if (newfd<0)
//		{
//			perror("accept error");
//			return false;
//		}
//		sock->_sockfd = newfd;
//		if (ip != NULL)
//		{
//			//inet_ntoa�������ֽ��������IPת��Ϊ�ַ���
//			*ip = inet_ntoa(addr.sin_addr);
//		}
//		if (port != NULL)
//		{
//			*port = ntohs(addr.sin_port);
//		}
//		return true;
//	}
//	//5.��������
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
//	//6.��������
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
//	//7.�ر��׽���
//	bool Close()
//	{
//		close(_sockfd);
//		return true;
//	}
//private:
//	void MakeAddr(struct sockaddr_in &addr, const std::string &ip, const uint16_t port)  //��һ����ַ�ṹ��ֵ
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
