// 这个demo演示进程等待
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
//		//exit(0);   //产生僵尸进程，子进程先于父进程退出
//		exit(99);
//	}
//	//wait(NULL);  //阻塞式接口，接受子进程退出的原因，防止产生僵尸进程
//	//waitpid(pid,NULL,0);//第一个参数式父进程的pid，第二个参数不要返回值，设置为NULL,第三个个参数代表是阻塞式接口
//	//waitpid(2345656,NULL,0);//子进程成为僵尸进程，因为该pid不存在，所以没有对应的孩子，直接退出，waitpid在这里没有效果，直接输出--，等待3秒钟，子进程变成僵尸进程
//	while (waitpid(-1, NULL, WNOHANG) == 0)  //WNOHANG将waitpid设置为非阻塞接口，当父进程到达时，子进程正在sleep,所以直接退出
//	{
//		printf("先去干点别的事!!\n");   //如果第一个参数随意给一个值，则返回值小于0，等待出错，没有子进程，可以在循环外面打印perror出错的原因
//		sleep(1);   //体现等待的进程
//	}
//	int status;
//	while (waitpid(-1, &status, WNOHANG) == 0);
//	{
//		printf("先去干点别的事!\n");
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