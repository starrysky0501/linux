//#include<iostream>
//#include<queue>
//#include<stdio.h>
//#include<unistd.h>
//#include<stdlib.h>
//#include<pthread.h>
//
//
//typedef void(*TaskHandler)(int data);
//class ThreadTask    //任务类  处理什么数据以及怎么处理都有用户定义，和线程池模块解耦合
//{
//private:
//	int _data;
//	TaskHandler _handler;
//public:
//	ThreadTask(){}
//	ThreadTask(int data, TaskHandler handler) :_data(data), _handler(handler){}
//	void SetTask(int data, TaskHandler handler)   //和没有参数的构造函数一起组合，使初始化更加灵活
//	{
//		_data = data;
//		_handler = handler;
//	}
//	void Run()
//	{
//		_handler(_data);
//	}
//
//};
//
//#define MAX_THR 5
//
//
//class ThreadPool    //线程类       变形的生产者与消费者模型
//{
//private:
//	int thr_num;                         //线程池中线程的最大数量
//	std::queue<ThreadTask> _task_queue;  //任务队列,没设置最大上限
//	pthread_mutex_t _mutex;              //保护队列的安全操作
//	pthread_cond_t _cond_con;            //实现队列的同步操作---消费者
//	pthread_cond_t _cond_pro;            //实现队列的同步操作---生产者
//private:
//	static void *thr_start(void *arg)    //为什么声明为ststic函数：因为thr_start函数的参数只有一个为void*类型，而成员函数的第一个参数默认为this指针，所以会导致参数不匹配
//	{
//		ThreadPool *pool = (ThreadPool*)arg;   //因为该函数声明为static函数，则没有this指针，所以对参数做了处理，传递过来为一个对象。
//		while (1)    //线程池中的线程一直在工作，只要有任务，则一直处理。
//		{
//			//1.先加锁
//			//2.判断队列是否有任务，没有，则等待，有则处理任务；
//			//3.处理时，取队首数据，出队 （取出任务，是为了执行任务）
//			//4.解锁
//			//5.执行任务； 如果将Run放在解锁之前，则失去线程并发额意义
//			//由于此处定义队列无上限，所以不用通知生产者，尽管生产任务
//			pool->ThreadLock();
//			while (pool->TaskIsEmpty())
//			{
//				pool->ThreadWait();
//			}
//			ThreadTask tt;
//			pool->QueuePop(tt);
//			pool->ThreadUnLock();
//			tt.Run();
//		}
//		return NULL;
//	}
//public:
//	bool QueuePop(ThreadTask &t)
//	{
//		t = _task_queue.front();
//		_task_queue.pop();
//		return true;
//	}
//	void ThreadWait()
//	{
//		pthread_cond_wait(&_cond_con, &_mutex);
//	}
//	bool TaskIsEmpty()
//	{
//		return _task_queue.empty();
//	}
//	void ThreadLock()
//	{
//		pthread_mutex_lock(&_mutex);
//	}
//	void ThreadUnLock()
//	{
//		pthread_mutex_unlock(&_mutex);
//	}
//public:
//	ThreadPool(int max_thr = MAX_THR) :thr_num(max_thr){}
//	bool PoolInit()                      //线程的创建以及锁和条件变量的初始化
//	{
//		int i = 0;
//		pthread_mutex_init(&_mutex, NULL);    //互斥锁和条件变量的初始化一定要放在线程创建之前
//		pthread_cond_init(&_cond_con, NULL);
//		pthread_cond_init(&_cond_pro, NULL);
//		for (int i = 0; i<thr_num; i++)
//		{
//			pthread_t tid;
//			int ret = pthread_create(&tid, NULL, thr_start, (void *)this);   //疑问： 不要detach没影响?
//			if (ret != 0)
//			{
//				std::cerr << "create thread error\n";
//				return false;
//			}
//			pthread_detach(tid);     //线程分离
//		}
//		return true;
//	}
//	bool TaskPush(ThreadTask &tt)
//	{
//		pthread_mutex_lock(&_mutex);    //队列没有最大上限，所以不存在同步等待问题
//		_task_queue.push(tt);
//		pthread_mutex_unlock(&_mutex);
//		pthread_cond_signal(&_cond_con); //唤醒线程池中的线程，因为有可能因为没有任务都陷入了休眠，每当有一个任务，都需要唤醒线程，让去处理任务
//		return true;
//	}
//};
//
//void test(int data)
//{
//	srand(data);
//	int sec = rand() % 5;
//	printf("thread:%p--get data:%d,sleep %d sec\n", pthread_self(), data, sec);
//	sleep(sec);
//}
//int main()
//{
//	ThreadPool pool;
//	int i = 0;
//	pool.PoolInit();
//	for (i = 0; i<10; i++)
//	{
//		ThreadTask task(i, test);
//		pool.TaskPush(task);
//	}
//	while (1)
//	{
//		sleep(1);
//	}
//	return 0;
//}

//线程池：提前创建一堆线程（最大数量限制），以及一个线程安全的任务队列，当大量的请求到来后，被添加到任务队列中，而线程池中的线程在不
//断从任务队列中获取任务进行处理即可。

//作用：
//1.避免大量线程的频繁创建与销毁锁带来的时间成本
//2.避免峰值压力下的线程创建过多导致资源耗尽的风险---线程池中的线程有一个最大数量的限制

//实现：一个以上(一个)的线程+线程安全的任务队列

//特性：
//1.固定数量的线程：数量设置+初始化接口 ---创建线程
//(不在构造函数中完成线程的创建，因为没有返回值，无法判断是否创建成功，放在初始化的接口)
//2.线程安全的任务队列
//(任务本身设定好如何去处理任务，封装一个任务类，添加到线程池中的任务队列中)
