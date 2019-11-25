#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
//信号量实现互斥
sem_t sem;
int tickets = 100;
void *thr_eat(void *arg)
{
	while (1)
	{
		sem_wait(&sem);   //加锁，判断当前的状态是否可以访问，能访问，才往下走 -1   P操作
		if (tickets>0)
		{
			usleep(5000);
			printf("i get tickets:%d\n", tickets--);
			sem_post(&sem);   //解锁  +1    V操作
		}
		else
		{
			sem_post(&sem);      //在线程任何可以退出的地方，都要解锁 
			pthread_exit(NULL);
		}
	}
	return NULL;
}


int main()
{
	int ret;
	pthread_t tid1;
	pthread_t tid2;
	sem_init(&sem, 0, 1);   //此处的1，表示的是一种状态判断，不是为了资源计数，表示同时只有一个线程可以访问。

	ret = pthread_create(&tid1, NULL, thr_eat, NULL);   //对于互斥来说，都是相同的角色，都是顾客
	if (ret != 0)
	{
		return -1;
	}

	ret = pthread_create(&tid2, NULL, thr_eat, NULL);
	if (ret != 0)
	{
		return -1;
	}

	pthread_join(tid1, NULL);
	pthread_join(tid2, NULL);
	sem_destroy(&sem);
	return 0;
}




//使用信号量实现同步,厨师做面和顾客吃面的场景，实现一对一的场景
/*
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

sem_t sem;

void *thr_eat(void *arg)
{
while(1)
{
sem_wait(&sem);      // 计数判断有没有面，没面，就等待了
printf("delicious~~~\n");
}
return NULL;
}

void *thr_cook(void *arg)    //厨师尽管做，对厨师没要求
{
while(1)
{
printf("cook noodle~~\n");
sem_post(&sem);     //做了一碗面，有阻塞的就唤醒，计数+1，没就计数+1
sleep(1);
}
return NULL;
}

int main()
{
int ret;
pthread_t tid1;
pthread_t tid2;
sem_init(&sem,0,0);

ret=pthread_create(&tid1,NULL,thr_eat,NULL);
if(ret!=0)
{
return -1;
}

ret=pthread_create(&tid2,NULL,thr_cook,NULL);
if(ret!=0)
{
return -1;
}

pthread_join(tid1,NULL);
pthread_join(tid2,NULL);
sem_destroy(&sem);
return 0;
}
*/
