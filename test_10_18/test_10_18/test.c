//������������vim�б��


//���ִ��빲�����ݶ��У��������������ڴ���
//#include<stdio.h>
//#include<unistd.h>
//#include<stdlib.h>
//int gval = 100;
//int main()
//{
//	int ppid = gitpid();
//	int pid = fork(); //fork�����ӽ���֮�󣬸��ӽ��̴��빲�����ݶ���
//	if (pid > 0)
//	{
//		//parent
//		gval = 10;
//	}
//	else if (pid == 0)
//	{
//		//child
//		sleep(3);
//	}
//	printf("---����---%d--%p,pid=%d,ppid=%d\n", gval, &gval, getpid(), ppid);
//	while (1)
//	{
//		sleep(1);
//	}
//	return 0;
//}

//argv[]:��ų������в���
//argc:�������в����ĸ���
//env[]:��ǰ��������л�������
//#include<stdio.h>
//#include<stdlib.h>
//int main(int argc, char *argv[], char* env[])
//{
//	extern char** environ; //���е�һ������ָ�룬���ػ��������������ַ���
//	int i;
//	for (i = 0; environ[i] != NULL; i++)
//	{
//		printf("environ[%d]=[%s]\n", i, environ[i]);
//	}
//	/*for (i = 0; i<argc; i++)
//	{
//		printf("argv[%d]=[%s]\n", i, argv[i]);
//	}
//	for (i = 0; env[i] != NULL; i++)    //argv,env�ַ���ָ�������У�������NULL��Ϊ��β��
//	{
//		printf("env[%d]=[%s]\n", i, env[i]);
//	}*/
//	char *ptr = getenv("MYTEST"); //ͨ�������������ƻ�ȡֵ�����������environ
//	if (ptr == NULL)
//	{
//		printf("NO MYTEST!\n");
//		return -1;
//	}
//	printf("MYTEST=%s\n", ptr);
//	return 0;
//}
//����ԭ�ͣ���ȡ����������3�ַ�ʽ
//char *getenv(const char * name) :ͨ�������������ƻ�ȡ������������
//main(int argc, char *argv[], char *env[]);
//extern char**environ;