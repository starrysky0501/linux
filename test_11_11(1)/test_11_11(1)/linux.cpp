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

//代码解释：
//首先程序正常运行，调用test()函数，在sleep期间，给进程发送一个信号，触发信号回调，
//所以也就是说，在主控流程还没将test函数运行完的时候，信号执行流也进入了这个函数。

//信号处理完了，才会返回主控流程，所以signal的值是3，main的值是4；注意新的执行流进入函数，
//是从函数开始的位置进入。      