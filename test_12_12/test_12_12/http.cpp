//#include <iostream>
//#include <string>
//#include <cstdlib>
//#include <sstream>
//#include "tcpsocket.hpp"
//
//int main(int argc, char *argv[])
//{
//	if (argc != 3) {
//		std::cerr << "./http ip port\n";
//		return -1;
//	}
//	std::string ip = argv[1];
//	uint16_t port = atoi(argv[2]);
//
//	TcpSocket lst_sock;
//	CHECK_RET(lst_sock.Socket());
//	CHECK_RET(lst_sock.Bind(ip, port));
//	CHECK_RET(lst_sock.Listen());
//
//	while (1) {
//		TcpSocket cli_sock;
//		if (lst_sock.Accept(&cli_sock) == false) {
//			continue;
//		}
//
//		std::string buf;
//		if (cli_sock.Recv(buf) == false) {
//			cli_sock.Close();
//			continue;
//		}
//		std::cout << "req:[" << buf << "]\n";      //��ӡ���յ�������
//
//		//��Ӧһ��ҳ�棬���У�ͷ����Ϣ�����У�����
//		std::string text;
//		text = "<html><body><h1>Hello World</h1></body></html>";
//		std::stringstream tmp;                     // stringstream��һ��string�������ǿ���������д������
//		tmp << "HTTP/1.1 200 OK\r\n";
//		tmp << "Content-Length: " << text.size() << "\r\n";
//		tmp << "Connection: close\r\n";
//		tmp << "Content-Type: text/html\r\n";
//		//tmp << "Location: http://www.taobao.com/\r\n";
//		tmp << "\r\n";
//		tmp << text;
//		cli_sock.Send(tmp.str());                 //stringstream����һ��string����tmp.str�ǻ�ȡstream����string����
//		cli_sock.Close();                         //���ڵ�ǰ�Ƕ����ӣ����ر�ʱ���������Դй¶��cli_sock��һ���ֲ�����
//	}
//	lst_sock.Close();
//	return 0;
//}
