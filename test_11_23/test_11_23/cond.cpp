//通过吃面的demo体会临界资源访问的时序合理性以及条件变量的基本使用
//不同的角色等待在不同的队列上，当有多个角色，则需要多个等待队列
/*#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

int is_have_noodle = 0;  //条件，但不是条件变量,一开始没有面，则为0
pthread_cond_t cond_foodie;   //定义一个条件变量
pthread_cond_t cond_chef;
pthread_mutex_t mutex;

void* foodie(void *arg)
{
	while (1)
	{
		pthread_mutex_lock(&mutex);
		while (is_have_noodle == 0)      //必须采用循环处理,当多个吃面条的人等在wait锁上，而不是卡在条件变量的等待队列上，吃完一碗面解锁，则其余卡在wait锁上的不判断是否有面条，则向下执行。
		{
			pthread_cond_wait(&cond_foodie, &mutex);
		}
		printf("eat noodles,delicious~~!\n");
		is_have_noodle--;
		pthread_mutex_unlock(&mutex);
		pthread_cond_signal(&cond_chef);  //至少唤醒一个
		//pthread_cond_broadcast  广播唤醒所有人
	}
	return NULL;
}

void* chef(void *arg)
{
	while (1)
	{
		pthread_mutex_lock(&mutex);
		while (is_have_noodle == 1)
		{
			pthread_cond_wait(&cond_chef, &mutex);
		}
		printf("cook noodels~~\n");
		is_have_noodle++;
		pthread_mutex_unlock(&mutex);  //先解锁在唤醒，减少锁冲突
		pthread_cond_signal(&cond_foodie);
	}
	return NULL;
}

#define MAX_FOODIE 4
int main()
{
	pthread_t foodie_tid, chef_tid;  //两个tid
	int ret = 0, i = 0;

	pthread_cond_init(&cond_foodie, NULL);
	pthread_cond_init(&cond_chef, NULL);
	pthread_mutex_init(&mutex, NULL);

	for (i = 0; i<MAX_FOODIE; i++)
	{
		ret = pthread_create(&foodie_tid, NULL, foodie, NULL);
		if (ret != 0)
		{
			printf("thread create error\n");
			return -1;
		}
	}

	ret = pthread_create(&chef_tid, NULL, chef, NULL);
	if (ret != 0)
	{
		printf("thread create error\n");
		return -1;
	}

	pthread_join(foodie_tid, NULL); //必须等待创建的线程的退出，因为没有这句，主线程运行到此处，最后直接return，退出进程
	pthread_join(chef_tid, NULL);

	pthread_cond_destroy(&cond_foodie);
	pthread_cond_destroy(&cond_chef);
	pthread_mutex_destroy(&mutex);
	return 0;
}*/

//条件变量是实现同步的变量。
//条件变量只提供等待与唤醒的功能，具体条件的判断，什么时候等待或唤醒，由用户自己定义
//使用挂起唤醒的方式更加实时，更加节省cpu的资源，操作起来更加方便
//通过吃面的demo体会临界资源访问的时序合理性以及条件变量的基本使用
//将进程从可中断休眠状态转变为运行状态，当该进程拿到时间片就可以运行。
//用户的条件判断需要使用while循环进行判断（被唤醒的多个线程，有可能都等待在锁上，解锁后，这时候有可能线程
//    在不具备访问条件的情况下，加锁成功进行资源访问)
//不同的角色要使用多个条件变量并且等待在不同的条件变量上










//实现一对一的场景，生产一碗面，吃一碗面,只有一个做面和吃面的人     程序暂时没问题
/*#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

int is_have_noodle = 0;  //条件，但不是条件变量,一开始没有面，则为0
pthread_cond_t cond;   //定义一个条件变量
pthread_mutex_t mutex;

void* foodie(void *arg)
{
	while (1)
	{
		pthread_mutex_lock(&mutex);
		if (is_have_noodle == 0)
		{
			//这三部操作并非原子操作，将这三部操作封装为pthread_cond_wait操作
			// pthread_mutex_unlock(&mutex);                                 //解锁
			// pause();  //挂起，程序暂停，可中断休眠                        //休眠
			// pthread_mutex_lock(&mutex);    //加锁后才能吃面               //被唤醒后加锁
			//若没有面，吃面的人应解锁，让做面的人去做面，但是解锁和休眠必须是一个原子操作
			//因为若解锁和休眠之间被打断，厨师做面唤醒吃面的人的时候，吃面的人还没有休眠，
			//就白唤醒了，但是因为没有第二次唤醒，吃面的人就有可能会永久休眠
			pthread_cond_wait(&cond, &mutex);
		}
		printf("eat noodles,delicious~~!\n");
		is_have_noodle--;
		pthread_mutex_unlock(&mutex);
		pthread_cond_signal(&cond);
	}
	return NULL;
}

void* chef(void *arg)
{
	while (1)
	{
		pthread_mutex_lock(&mutex);
		if (is_have_noodle == 1)
		{
			pthread_cond_wait(&cond, &mutex);
		}
		printf("cook noodels~~\n");
		is_have_noodle++;
		pthread_mutex_unlock(&mutex);  //先解锁在唤醒，减少锁冲突
		pthread_cond_signal(&cond);
	}
	return NULL;
}

int main()
{
	pthread_t foodie_tid, chef_tid;  //两个tid
	int ret = 0;

	pthread_cond_init(&cond, NULL);
	pthread_mutex_init(&mutex, NULL);

	ret = pthread_create(&foodie_tid, NULL, foodie, NULL);
	if (ret != 0)
	{
		printf("thread create error\n");
		return -1;
	}

	ret = pthread_create(&chef_tid, NULL, chef, NULL);
	if (ret != 0)
	{
		printf("thread create error\n");
		return -1;
	}

	pthread_join(foodie_tid, NULL); //必须等待创建的线程的退出，因为没有这句，主线程运行到此处，最后直接return，退出进程
	pthread_join(chef_tid, NULL);

	pthread_cond_destroy(&cond);
	pthread_mutex_destroy(&mutex);
	return 0;
}
*/





