//这个demo体会匿名管道的基本使用                                                                               
//#include<stdio.h>
//#include<unistd.h>
//#include<stdlib.h>
//#include<string.h>
//int main()
//{
//	int pid = 0;
//	int pipefd[2];
//	int ret = pipe(pipefd);   //系统调用接口
//	if (ret<0)
//	{
//		perror("pipe error\n");
//		return -1;
//	}
//	pid = fork();
//	if (pid == 0)
//	{
//		//子进程从管道读取数据
//		char buf[1024] = { 0 };
//		int ret = read(pipefd[0], buf, 1023);
//
//if (ret<0)
//{
//	perror("read error\n");
//	return -1;
//}
//printf("child get data:[%s]\n", buf);
//	  }
//	  else
//	  {
//		  //父进程向管道写入数据
//		  char *ptr = "天天好心情";
//		  int ret = write(pipefd[1], ptr, strlen(ptr));
//		  if (ret<0)
//		  {
//			  perror("write error\n");
//			  return -1;
//		  }
//	  }
//	  return 0;
//
//  }