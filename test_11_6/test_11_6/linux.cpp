//�źŵ�����
//#include <stdio.h>
//#include <stdlib.h>
//#include <unistd.h>
//#include <signal.h>
//
//void sigcb(int signum)    //дһ���ص�����
//{
//	printf("recv signal:%d\n", signum);
//}
//int main()
//{
//	//signal���������źŵĴ���
//	signal(SIGINT, sigcb);    //�ǿɿ��źţ�ctrl+c
//	signal(40, sigcb);        //�ɿ��ź�
//
//	sigset_t mask_set, old_set;  //�����źż���
//	sigemptyset(&mask_set);     //�ڴ�����ʲô���ݲ�֪��������Ӧʹ�����(����źż���)
//	sigfillset(&mask_set);      //�����е��ź���ӵ�������
//	sigprocmask(SIG_BLOCK, &mask_set, &old_set);   //����mask_set�������ź�
//	//old_set��ȡ������������ԭ�е���Ϣ
//	//��ΪSIG_BLOCK�Ĺ�������������źţ�����mask_set���ϻ������  
//	//��old_set����������źŲ����������ݺ�mask+setһ��
//
//	printf("press enter to continue!\n");
//	getchar();  //�����س�����������̾Ϳ�������
//	sigprocmask(SIG_UNBLOCK, &mask_set, NULL);   //����ź�����
//	//sigprocmask(SIG_SETMASK,&old_set,NULL);   //old_set�����ʲô��û����
//	return 0;
//}