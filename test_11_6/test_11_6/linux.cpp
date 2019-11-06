//信号的阻塞
//#include <stdio.h>
//#include <stdlib.h>
//#include <unistd.h>
//#include <signal.h>
//
//void sigcb(int signum)    //写一个回调函数
//{
//	printf("recv signal:%d\n", signum);
//}
//int main()
//{
//	//signal函数：对信号的处理
//	signal(SIGINT, sigcb);    //非可靠信号，ctrl+c
//	signal(40, sigcb);        //可靠信号
//
//	sigset_t mask_set, old_set;  //定义信号集合
//	sigemptyset(&mask_set);     //内存中有什么数据不知道，我们应使它清空(清空信号集合)
//	sigfillset(&mask_set);      //将所有的信号添加到集合中
//	sigprocmask(SIG_BLOCK, &mask_set, &old_set);   //阻塞mask_set中所有信号
//	//old_set获取阻塞集合里面原有的信息
//	//因为SIG_BLOCK的功能是添加阻塞信号，所以mask_set集合会变阻塞  
//	//则old_set集合里面的信号不阻塞，内容和mask+set一致
//
//	printf("press enter to continue!\n");
//	getchar();  //不按回车，则程序流程就卡在这里
//	sigprocmask(SIG_UNBLOCK, &mask_set, NULL);   //解除信号阻塞
//	//sigprocmask(SIG_SETMASK,&old_set,NULL);   //old_set里就是什么都没阻塞
//	return 0;
//}