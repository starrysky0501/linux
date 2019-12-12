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
//		std::cout << "req:[" << buf << "]\n";      //打印接收到的请求
//
//		//响应一个页面，首行，头部信息，空行，正文
//		std::string text;
//		text = "<html><body><h1>Hello World</h1></body></html>";
//		std::stringstream tmp;                     // stringstream是一个string流，我们可以向里面写入数据
//		tmp << "HTTP/1.1 200 OK\r\n";
//		tmp << "Content-Length: " << text.size() << "\r\n";
//		tmp << "Connection: close\r\n";
//		tmp << "Content-Type: text/html\r\n";
//		//tmp << "Location: http://www.taobao.com/\r\n";
//		tmp << "\r\n";
//		tmp << text;
//		cli_sock.Send(tmp.str());                 //stringstream不是一个string对象，tmp.str是获取stream流的string对象
//		cli_sock.Close();                         //由于当前是短连接，不关闭时，会造成资源泄露，cli_sock是一个局部变量
//	}
//	lst_sock.Close();
//	return 0;
//}
