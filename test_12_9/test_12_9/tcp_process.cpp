//#include <signal.h>
//#include <sys/wait.h>
//#include "tcpsocket.hpp"
//
//void sigcb(int signo)
//{
//	while (waitpid(-1, NULL, WNOHANG)>0);
//}
//
//int main(int argc, char *argv[])
//{
//	signal(SIGCHLD, sigcb);
//	if (argc != 3)
//	{
//		std::cout << "./tcp_srv ip port\n";
//		return -1;
//	}
//	std::string ip = argv[1];
//	uint16_t port = atoi(argv[2]);
//
//	TcpSocket lst_sock;
//	CHECK_RET(lst_sock.Socket());
//	CHECK_RET(lst_sock.Bind(ip, port));
//	CHECK_RET(lst_sock.Listen());
//	while (1)     //客户端不止一个,不可能只获取一次
//	{
//		TcpSocket cli_sock;
//		if (lst_sock.Accept(&cli_sock) == false)  //从已完成连接队列里获取新连接
//		{
//			continue;       //获取客户端新连接失败，忽略，而不是程序退出
//		}
//		std::cout << "new connect\n";
//
//		//创建子进程与客户端进行通信
//		//父进程永远只管一件事，获取新连接
//		pid_t pid = fork();
//		if (pid<0)
//		{
//			cli_sock.Close();
//			continue;
//		}
//
//		else if (pid == 0)
//		{
//			while (1)
//			{
//				std::string buf;
//				bool ret = cli_sock.Recv(buf);
//				if (ret == false)
//				{
//					cli_sock.Close();//新连接接收数据失败，只是服务端和这个客户端不能通信了，应该关闭连接，继续处理下个客户端，不能退出程序。
//					continue;
//				}
//				std::cout << "client say:" << buf << "\n";
//				std::cout << "server say:";
//				fflush(stdout);
//				buf.clear();
//				std::cin >> buf;
//				ret = cli_sock.Send(buf);
//				if (ret == false)             //发送失败
//				{
//					cli_sock.Close();      //关闭套接字，重新获取新连接
//					continue;
//				}
//			}
//			cli_sock.Close();
//			exit(0);   //阻止子程序向下执行，因为要保证accept函数只有父进程执行，注意：考虑僵尸进程
//		}
//
//		cli_sock.Close();
//		//父子进程，数据独有，各有各的描述符，但他们的描述符指向的是内核中的同一个socket结构体，如果
//		//父进程的描述符不关闭，则代表出现的资源泄露，父进程的cli.sock根本就不用，他不用和客户端通信，所以
//		//不用保留，并且cli.sock是一个局部变量，循环上去，它就释放了，但描述符并没有被关闭，所以要在父进
//		//程的执行流中关闭父进程的套接字描述符，父进程的套接字描述符的关闭是不影响子进程的。当父进程的描述符
//		//被用完了，就接收不了新连接了。
//	}
//	lst_sock.Close();              //关闭监听套接字
//	return 0;
//}

