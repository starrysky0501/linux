//#include <stdio.h>
//#include <stdlib.h>
//#include <unistd.h>
//#include <signal.h>
//
//int a = 0;
//int b = 0;
//int test()
//{
//	a++;
//	sleep(10);
//	b++;
//	return a + b;
//}
//void sigcb(int signo)
//{
//	printf("signal:%d\n", test());
//}
//
//int main()
//{
//	signal(SIGINT, sigcb);
//	printf("main:%d\n", test());
//	return 0;
//}

//������ͣ�
//���ȳ����������У�����test()��������sleep�ڼ䣬�����̷���һ���źţ������źŻص���
//����Ҳ����˵�����������̻�û��test�����������ʱ���ź�ִ����Ҳ���������������

//�źŴ������ˣ��Ż᷵���������̣�����signal��ֵ��3��main��ֵ��4��ע���µ�ִ�������뺯����
//�ǴӺ�����ʼ��λ�ý��롣      