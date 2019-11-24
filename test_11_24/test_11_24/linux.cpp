//手撕生产者与消费者模型
#include<iostream>
#include<queue>
#include<stdio.h>
#include<unistd.h>
#include<pthread.h>

#define MAX_QUE 10

class BlockQueue
{
private:
	std::queue<int> _queue;
	int _capacity;

	pthread_cond_t _cond_productor;
	pthread_cond_t _cond_consumer;
	pthread_mutex_t _mutex;
public:
	BlockQueue(int que_num = MAX_QUE)
		:_capacity(que_num)
	{
		pthread_mutex_init(&_mutex, NULL);
		pthread_cond_init(&_cond_productor, NULL);
		pthread_cond_init(&_cond_consumer, NULL);
	}

	~BlockQueue()
	{

		pthread_mutex_destroy(&_mutex);
		pthread_cond_destroy(&_cond_productor);
		pthread_cond_destroy(&_cond_consumer);
	}

	bool QueuePush(int &data)
	{
		pthread_mutex_lock(&_mutex);
		while (_queue.size() == _capacity)   //队满,_queue_size()也是一个需要保护的操作,是一个临界资源
		{
			pthread_cond_wait(&_cond_productor, &_mutex);
		}
		_queue.push(data);
		pthread_mutex_unlock(&_mutex);
		pthread_cond_signal(&_cond_consumer);
		return true;
	}

	bool QueuePop(int &data)
	{
		pthread_mutex_lock(&_mutex);
		while (_queue.empty())
		{
			pthread_cond_wait(&_cond_consumer, &_mutex);
		}
		data = _queue.front();
		_queue.pop();
		pthread_mutex_unlock(&_mutex);
		pthread_cond_signal(&_cond_productor);
		return true;
	}
};


void *thr_consumer(void *arg)
{
	BlockQueue *queue = (BlockQueue*)arg;
	while (1)
	{
		int data;
		queue->QueuePop(data);   //如果没数据，会在QueuePop中被阻塞，并且此处不用考虑线程安全，因为在QueuePop中已实现。
		printf("**get a data:%d\n", data);
	}
	return NULL;
}

void *thr_productor(void *arg)
{
	int i = 0;
	BlockQueue *queue = (BlockQueue*)arg;
	while (1)
	{
		queue->QueuePop(i);
		printf("--put a data:%d\n", i++);
	}
	return NULL;
}

#define MAX_THREAD 4

int main()
{
	int i, ret;
	pthread_t ctid[MAX_THREAD], ptid[MAX_THREAD];
	BlockQueue queue;                                   //也可以将他声明为全局变量，就不需要传参。
	for (i = 0; i<MAX_THREAD; i++)
	{
		ret = pthread_create(&ctid[i], NULL, thr_consumer, (void*)&queue);   //第四个参数，一般传入的是临界资源，生产者和消费者都要访问线程安全的队列
		if (ret != 0)
		{
			std::cerr << "thread create error\n";
			return -1;
		}
	}
	for (i = 0; i<MAX_THREAD; i++)
	{
		ret = pthread_create(&ptid[i], NULL, thr_productor, (void*)&queue);   //第四个参数，一般传入的是临界资源，生产者和消费者都要访问线程安全的队列
		if (ret != 0)
		{
			std::cerr << "thread create error\n";
			return -1;
		}
	}
	for (i = 0; i<MAX_THREAD; i++)
	{
		pthread_join(ctid[i], NULL);
		pthread_join(ptid[i], NULL);
	}
	return 0;
}

//printf把字符串组装成一个整体，打印的。
