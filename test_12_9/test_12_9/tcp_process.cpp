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
//	while (1)     //�ͻ��˲�ֹһ��,������ֻ��ȡһ��
//	{
//		TcpSocket cli_sock;
//		if (lst_sock.Accept(&cli_sock) == false)  //����������Ӷ������ȡ������
//		{
//			continue;       //��ȡ�ͻ���������ʧ�ܣ����ԣ������ǳ����˳�
//		}
//		std::cout << "new connect\n";
//
//		//�����ӽ�����ͻ��˽���ͨ��
//		//��������Զֻ��һ���£���ȡ������
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
//					cli_sock.Close();//�����ӽ�������ʧ�ܣ�ֻ�Ƿ���˺�����ͻ��˲���ͨ���ˣ�Ӧ�ùر����ӣ����������¸��ͻ��ˣ������˳�����
//					continue;
//				}
//				std::cout << "client say:" << buf << "\n";
//				std::cout << "server say:";
//				fflush(stdout);
//				buf.clear();
//				std::cin >> buf;
//				ret = cli_sock.Send(buf);
//				if (ret == false)             //����ʧ��
//				{
//					cli_sock.Close();      //�ر��׽��֣����»�ȡ������
//					continue;
//				}
//			}
//			cli_sock.Close();
//			exit(0);   //��ֹ�ӳ�������ִ�У���ΪҪ��֤accept����ֻ�и�����ִ�У�ע�⣺���ǽ�ʬ����
//		}
//
//		cli_sock.Close();
//		//���ӽ��̣����ݶ��У����и����������������ǵ�������ָ������ں��е�ͬһ��socket�ṹ�壬���
//		//�����̵����������رգ��������ֵ���Դй¶�������̵�cli.sock�����Ͳ��ã������úͿͻ���ͨ�ţ�����
//		//���ñ���������cli.sock��һ���ֲ�������ѭ����ȥ�������ͷ��ˣ�����������û�б��رգ�����Ҫ�ڸ���
//		//�̵�ִ�����йرո����̵��׽����������������̵��׽����������Ĺر��ǲ�Ӱ���ӽ��̵ġ��������̵�������
//		//�������ˣ��ͽ��ղ����������ˡ�
//	}
//	lst_sock.Close();              //�رռ����׽���
//	return 0;
//}

