#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

#define MAX_QUE 10

class RingQueue
{
private:
	std::vector<int> _queue;//使用数组实现环形队列
	int _capacity; //初始化环形队列的节点数量
	int _step_read;//当前读位置的数组下标
	int _step_write;//当前写位置的数组下标
	sem_t _sem_lock;//用户实现互斥的锁
	sem_t _sem_con;//消费者等待队列，计数器对有数据的空间进行计数
	sem_t _sem_pro;//生产者等待队列，计数器对有空闲的空间进行计数
public:
	RingQueue(int max_que = MAX_QUE) :_capacity(max_que),
		_queue(max_que), _step_read(0), _step_write(0)
	{
		//初始化信号量
		sem_init(&_sem_lock, 0, 1);   //互斥锁 线程间 只有0/1的计数器 起初必须计数是1
		sem_init(&_sem_con, 0, 0);         //消费者等待队列  数据的节点的个数
		sem_init(&_sem_pro, 0, max_que);   //生产者等待队列  空闲的节点的个数
	}
	~RingQueue()
	{
		//销毁信号量
		sem_destroy(&_sem_lock);
		sem_destroy(&_sem_con);
		sem_destroy(&_sem_pro);
	}

	bool QueuePush(int &data)
	{
		//数据入对
		//1.判断是否能够访问临界资源，判断空闲空间计数是否大于0
		sem_wait(&_sem_pro);                      //判断生产者是否还能生产数据，对空闲空间进行计数
		//2.先加锁
		sem_wait(&_sem_lock);
		//3.数据的入队操作
		_queue[_step_write] = data;
		_step_write = (_step_write + 1) % _capacity;    //不用担心超过，因为信号量本身就有计数
		//4.解锁
		sem_post(&_sem_lock);
		//5.数据资源的空间计数+1，唤醒消费者
		sem_post(&_sem_con);
		return true;
	}

	bool QueuePop(int &data)
	{
		sem_wait(&_sem_con);
		sem_wait(&_sem_lock);
		data = _queue[_step_read];
		_step_read = (_step_read + 1) % _capacity;
		sem_post(&_sem_lock);
		sem_post(&_sem_pro);
		return true;
	}
};

#define MAX_THR 4

void *consumer(void *arg)
{
	RingQueue *queue = (RingQueue*)arg;
	while (1)
	{
		int data;
		queue->QueuePop(data);
		printf("consumer get data:%d\n", data);     //打印和出队不是原子操作，所以会出现一次打印多余10个的数据                          
	}
	return NULL;

}

void *productor(void *arg)
{
	RingQueue *queue = (RingQueue*)arg;
	int i = 0;
	while (1)
	{
		queue->QueuePush(i);
		printf("productor put data:%d\n", i++);     //打印和入队并非原子操作                     
	}
	return NULL;

}


int main()
{
	pthread_t ctid[MAX_THR], ptid[MAX_THR];
	RingQueue queue;

	for (int i = 0; i < MAX_THR; i++)
	{
		int ret = pthread_create(&ctid[i], NULL, consumer, (void*)&queue);
		if (ret != 0)
		{
			printf("thread create error\n");
			return -1;
		}
	}
	for (int i = 0; i < MAX_THR; i++)
	{
		int ret = pthread_create(&ptid[i], NULL, productor, (void*)&queue);
		if (ret != 0)
		{
			printf("thread create error\n");
			return -1;
		}
	}
	for (int i = 0; i < MAX_THR; i++)
	{
		pthread_join(ctid[i], NULL);
		pthread_join(ptid[i], NULL);
	}
	return 0;
}

//条件变量：在外部进行条件判断，因此先加锁，保护条件判断
//信号量是通过自身的计数器实现判断的，不需要保护，内部已经对该计数器进行保护
//锁永远只保护临界资源
