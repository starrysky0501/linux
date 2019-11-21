//通过黄牛抢票的例子体会线程安全的重要性以及认识互斥锁
//#include<stdio.h>
//#include<unistd.h>
//#include<stdlib.h>
//#include<pthread.h>
//
//#define MAX_THR 4
//int tickets = 100;
//pthread_mutex_t mutex;    //互斥锁作为保护临界资源的数据，需要被每个线程访问到，所以将他定义为全局变量
//
//void *cattle(void *arg)     //线程的入口函数，模拟实现黄牛抢票,操控一个全局变量
//{
//	while (1)
//	{
//		pthread_mutex_lock(&mutex);
//
//		if (tickets>0)
//		{
//			printf("%p i get a ticket:%d\n", pthread_self(), tickets);
//			usleep(1000); //单位：微秒
//			tickets--; //抢票总要有个过程
//			pthread_mutex_unlock(&mutex);
//		}
//		else
//		{
//			printf("have no tickets\n");
//			pthread_mutex_unlock(&mutex);  //加锁之后，需要在任意有可能退出线程的地方都要进行解锁
//			pthread_exit(NULL);
//		}
//	}
//	return NULL;
//}
//
//int main()
//{
//	pthread_t tid[MAX_THR];
//	pthread_mutex_init(&mutex, NULL);//(初始化)一定要放在创建线程之前,因为一旦创建了线程，谁先运行就不一定了。
//	int i = 0, j = 0;
//	for (i = 0; i<MAX_THR; i++)
//	{
//		int ret = pthread_create(&tid[i], NULL, cattle, NULL);  //线程创建
//		if (ret != 0)
//		{
//			printf("thread create error\n");
//			return -1;
//		}
//	}
//	for (j = 0; j<MAX_THR; j++)
//	{
//		pthread_join(tid[j], NULL);    //线程等待
//	}
//	pthread_mutex_destroy(&mutex); //销毁互斥锁
//	return 0;
//}
//1.先初始化锁，再创建线程
//2.互斥锁是为了保护临界资源的操作，其他的操作一概不保护。加锁的位置，一定要在临界资源访问之前。
//3.加锁的三种方式：
//  pthread_mutex_lock  阻塞加锁
//  pthread_mutex_trylock  非阻塞加锁
//  pthread_mutex_timedlock 限制阻塞时长的阻塞加锁
//4.锁导致程序流程无法推进，则可以称为死锁；在线程中加锁，则需要在任意线程可能退出的地方解锁
