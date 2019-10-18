//这两个程序在vim中编程


//体现代码共享，数据独有，程序存放在虚拟内存中
//#include<stdio.h>
//#include<unistd.h>
//#include<stdlib.h>
//int gval = 100;
//int main()
//{
//	int ppid = gitpid();
//	int pid = fork(); //fork创建子进程之后，父子进程代码共享，数据独有
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
//	printf("---加油---%d--%p,pid=%d,ppid=%d\n", gval, &gval, getpid(), ppid);
//	while (1)
//	{
//		sleep(1);
//	}
//	return 0;
//}

//argv[]:存放程序运行参数
//argc:程序运行参数的个数
//env[]:当前程序的所有环境变量
//#include<stdio.h>
//#include<stdlib.h>
//int main(int argc, char *argv[], char* env[])
//{
//	extern char** environ; //库中的一个二级指针，返回环境变量的整个字符串
//	int i;
//	for (i = 0; environ[i] != NULL; i++)
//	{
//		printf("environ[%d]=[%s]\n", i, environ[i]);
//	}
//	/*for (i = 0; i<argc; i++)
//	{
//		printf("argv[%d]=[%s]\n", i, argv[i]);
//	}
//	for (i = 0; env[i] != NULL; i++)    //argv,env字符串指针数组中，都是以NULL作为结尾的
//	{
//		printf("env[%d]=[%s]\n", i, env[i]);
//	}*/
//	char *ptr = getenv("MYTEST"); //通过环境变量名称获取值，结果区别于environ
//	if (ptr == NULL)
//	{
//		printf("NO MYTEST!\n");
//		return -1;
//	}
//	printf("MYTEST=%s\n", ptr);
//	return 0;
//}
//代码原型：获取环境变量的3种方式
//char *getenv(const char * name) :通过环境变量名称获取环境变量内容
//main(int argc, char *argv[], char *env[]);
//extern char**environ;