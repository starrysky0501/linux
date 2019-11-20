//讨论tid的含义
//#include <stdio.h>
//#include <unistd.h>
//#include <stdlib.h>
//#include <pthread.h>
//
//void *thr_start(void *arg)
//{
//	while (1)
//	{
//		printf("child thread---%s\n", (char*)arg);
//		sleep(1);
//	}
//	return NULL;
//}
//
//int main()
//{
//	pthread_t tid;
//	char *ptr = "this is thread\n";
//	int ret = pthread_create(&tid, NULL, thr_start, (void*)ptr); //创建线程
//	if (ret != 0)
//	{
//		perror("thread create error");
//		return -1;
//	}
//	while (1)
//	{
//		printf("main thread---%p\n", tid);
//		sleep(1);
//	}
//	return 0;
//}


//线程的三种退出方式
//#include <stdio.h>
//#include <unistd.h>
//#include <stdlib.h>
//#include <pthread.h>
//
//void *thr_start(void *arg)
//{
//	//sleep(5);
//	//return NULL; //线程的第一种退出方式，return退出一个线程，主动调用
//
//	//sleep(5);
//	//pthread_exit(NULL); //线程的第二种退出方式，参数为退出的返回值，主动调用
//	while (1)
//	{
//		printf("child thread---%s\n", (char*)arg);
//		sleep(1);
//	}
//	return NULL;
//}
//int main()
//{
//	pthread_t tid;
//	char *ptr = "this is thread\n";
//	int ret = pthread_create(&tid, NULL, thr_start, (void*)ptr);
//	if (ret != 0)
//	{
//		perror("thread create error");
//		return -1;
//	}
//
//	//pthread_exit(NULL); //退出主线程，使主线程变为僵尸线程，在os中没有僵尸线程这个概念
//
//	sleep(5);
//	pthread_cancel(tid);  //线程的第三种退出方式,参数指定退出的线程，取消一个线程。
//	while (1)
//	{
//		printf("main thread---%p\n", tid);
//		sleep(1);
//	}
//	return 0;
//}



//线程等待
//#include <stdio.h>
//#include <unistd.h>
//#include <stdlib.h>
//#include <pthread.h>
//void *thr_start(void *arg)
//{
//	sleep(5);
//	char *ptr = "jintianhaoleng~~\n";     //ptr指向的常量的首地址，该常量地址不在栈。线程退出，不会释放这个空间.只有栈的空间是每个线程独有的。
//	char ptr[] = "jintianhaoleng~~\n";  //ptr是一个局部变量，线程退出，则被销毁  
//	pthread_exit(ptr);                  //将ptr作为返回值
//
//	while (1)
//	{
//		printf("child thread---%s\n", (char*)arg);
//		sleep(1);
//	}
//	return NULL;
//}
//int main()
//{
//	pthread_t tid;
//	char *ptr = "this is thread\n";
//	int ret = pthread_create(&tid, NULL, thr_start, (void*)ptr);
//	if (ret != 0)
//	{
//		perror("thread create error");
//		return -1;
//	}
//
//
//	char *retval;     //如果在这里定义二级指针，将它作为参数，不管赋NULL与否，都会导致程序段错误，
//	pthread_join(tid, (void**)&retval);  //注意：该函数的第二个参数是一个二级指针，要想获得线程的返回值，则必须传递一级指针的地址.
//	printf("retval:%s\n", retval);
//
//	while (1)
//	{
//		printf("main thread---%p\n", tid);
//		sleep(1);
//	}
//	return 0;
//}

//线程分离
//#include <stdio.h>
//#include <unistd.h>
//#include <stdlib.h>
//#include <pthread.h>
//void *thr_start(void *arg)
//{
//	pthread_detach(pthread_self());
//	sleep(5);
//	char *ptr = "jintianhaoleng~~\n";     //ptr指向的常量的首地址，该常量地址不在栈。线程退出，不会释放这个空间.只有栈的空间是每个线程独有的。
//	pthread_exit(ptr);
//
//	while (1)
//	{
//		printf("child thread---%s\n", (char*)arg);
//		sleep(1);
//	}
//	return NULL;
//}
//int main()
//{
//	pthread_t tid;
//	char *ptr = "this is thread\n";
//	int ret = pthread_create(&tid, NULL, thr_start, (void*)ptr);
//	if (ret != 0)
//	{
//		perror("thread create error");
//		return -1;
//	}
//
//	//pthread_detach(tid);//线程分离，则获取不到返回值，因为那块内存已经被释放。下面打印会出出现乱码
//	sleep(1);  //此处的作用就是：可以使新创建的线程一定会获取的cpu的时间片，从而pthread_join获取不到返回值，否则，如果线程还没有拿到过时间片，pthread_join就可以获取到返回值
//	char *retval;
//	pthread_join(tid, (void**)&retval);  //注意：该函数的第二个参数是一个二级指针，要想获得线程的返回值，则必须传递一级指针的地址.
//	printf("retval:%s\n", retval);
//
//	while (1)
//	{
//		printf("main thread---%p\n", tid);
//		sleep(1);
//	}
//	return 0;
//}
