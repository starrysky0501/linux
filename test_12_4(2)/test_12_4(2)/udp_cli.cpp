////ͨ��UdpSocketʵ��udp����˳���
//#include<stdlib.h>           //atoi����
//#include"udpsocket.hpp"
//
//#define CHECK_RET(q) if((q)==false){return -1;}
//int main(int argc, char* argv[])
//{
//	if (argc != 3)
//	{
//		printf("./udp_srv ip port\n");
//		return -1;
//	}
//	//�����ַ�Ƿ���˵ĵ�ַ��Ϊ���ÿͻ���֪�����������͵�����
//	std::string ip = argv[1];
//	uint16_t port = atoi(argv[2]);
//
//	Udpsocket sock;
//	CHECK_RET(sock.Socket());
//	//�ͻ��˲����Ƽ��ֶ��󶨵�ַ
//	//CHECK_RET(sock.Bind(ip,port));
//
//	struct sockaddr_in srv_addr;
//	srv_addr.sin_family = AF_INET;
//	srv_addr.sin_port = htons(port);
//	srv_addr.sin_addr.s_addr = inet_addr(ip.c_str());
//	while (1)
//	{
//		std::string buf;
//		std::cout << "client say:";
//		fflush(stdout);
//		std::cin >> buf;
//		CHECK_RET(sock.Send(buf, &srv_addr));
//
//		CHECK_RET(sock.Recv(buf, &srv_addr));
//		std::cout << "server say:" << buf << std::endl;
//	}
//	sock.Close();
//
//}
