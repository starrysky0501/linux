// ���demo��ʾ���̵ȴ�
//#include<stdio.h>
//#include<unistd.h>
//#include<stdlib.h>
//#include<errno.h>
//int main()
//{
//	pid_t = fork();
//	if (pid < 0)
//	{
//		perror("fork error");
//		return -1;
//	}
//	else if (pid == 0)
//	{
//		sleep(3);
//		//exit(0);   //������ʬ���̣��ӽ������ڸ������˳�
//		exit(99);
//	}
//	//wait(NULL);  //����ʽ�ӿڣ������ӽ����˳���ԭ�򣬷�ֹ������ʬ����
//	//waitpid(pid,NULL,0);//��һ������ʽ�����̵�pid���ڶ���������Ҫ����ֵ������ΪNULL,����������������������ʽ�ӿ�
//	//waitpid(2345656,NULL,0);//�ӽ��̳�Ϊ��ʬ���̣���Ϊ��pid�����ڣ�����û�ж�Ӧ�ĺ��ӣ�ֱ���˳���waitpid������û��Ч����ֱ�����--���ȴ�3���ӣ��ӽ��̱�ɽ�ʬ����
//	while (waitpid(-1, NULL, WNOHANG) == 0)  //WNOHANG��waitpid����Ϊ�������ӿڣ��������̵���ʱ���ӽ�������sleep,����ֱ���˳�
//	{
//		printf("��ȥ�ɵ�����!!\n");   //�����һ�����������һ��ֵ���򷵻�ֵС��0���ȴ�����û���ӽ��̣�������ѭ�������ӡperror�����ԭ��
//		sleep(1);   //���ֵȴ��Ľ���
//	}
//	int status;
//	while (waitpid(-1, &status, WNOHANG) == 0);
//	{
//		printf("��ȥ�ɵ�����!\n");
//		sleep(1);
//	}
//	printf("exit child code:%d\n", (status >> 8) & 0xff);
//	while (1)
//	{
//		printf("--------\n");
//		sleep(1);
//	}
//	return 0;
//}