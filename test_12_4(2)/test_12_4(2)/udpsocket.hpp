////ʵ����Udpsocket���װudp���ò���
//#include <iostream>
//#include <string>
//#include <errno.h>    //error      
//#include <stdio.h>    //perror
//
//#include <sys/socket.h>        
//#include <netinet/in.h>     //sockaddr_in����ṹ�������ͷ�ļ���
//#include <arpa/inet.h>      //htons,inet_addr������ͷ�ļ�
//#include <unistd.h>         //close����
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
//		addr.sin_addr.s_addr = inet_addr(ip.c_str());              //���ַ����ĵ��ʮ����ip��ַת��Ϊ�����ֽ��������ip��ַ
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
//		buf.assign(tmp, len);   //��tmp�п���ָ�����ȵ����ݵ�buf�У�buf��ʵ��һ��ָ�룬���Լ�����һ��len��С�Ŀռ�
//		return true;
//	}
//	bool Send(std::string &buf, struct sockaddr_in *daddr)     //������ʹ��string,����\0ֹͣ
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
////gg=G:�����е�β��ȫ�Ķ��룻gg = shift g
////inet_addr������������char*,������string
////�����ڵ�32����ϵͳ��,long����4���ֽڣ�64λ�������û��Լ�ʵ�ִ������ֽ���ת���������ֽ���
////htons���Դ��ж����ǵ������ֽ��������С�ˣ�ת��������Ǵ�ˣ�ʲô������
////���ֵ��ֽ���ת���������ֽ���ת��Ϊ�����ֽ���
//
