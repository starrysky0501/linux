//#include<iostream>
//#include<queue>
//#include<stdio.h>
//#include<unistd.h>
//#include<stdlib.h>
//#include<pthread.h>
//
//
//typedef void(*TaskHandler)(int data);
//class ThreadTask    //������  ����ʲô�����Լ���ô�������û����壬���̳߳�ģ������
//{
//private:
//	int _data;
//	TaskHandler _handler;
//public:
//	ThreadTask(){}
//	ThreadTask(int data, TaskHandler handler) :_data(data), _handler(handler){}
//	void SetTask(int data, TaskHandler handler)   //��û�в����Ĺ��캯��һ����ϣ�ʹ��ʼ���������
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
//class ThreadPool    //�߳���       ���ε���������������ģ��
//{
//private:
//	int thr_num;                         //�̳߳����̵߳��������
//	std::queue<ThreadTask> _task_queue;  //�������,û�����������
//	pthread_mutex_t _mutex;              //�������еİ�ȫ����
//	pthread_cond_t _cond_con;            //ʵ�ֶ��е�ͬ������---������
//	pthread_cond_t _cond_pro;            //ʵ�ֶ��е�ͬ������---������
//private:
//	static void *thr_start(void *arg)    //Ϊʲô����Ϊststic��������Ϊthr_start�����Ĳ���ֻ��һ��Ϊvoid*���ͣ�����Ա�����ĵ�һ������Ĭ��Ϊthisָ�룬���Իᵼ�²�����ƥ��
//	{
//		ThreadPool *pool = (ThreadPool*)arg;   //��Ϊ�ú�������Ϊstatic��������û��thisָ�룬���ԶԲ������˴������ݹ���Ϊһ������
//		while (1)    //�̳߳��е��߳�һֱ�ڹ�����ֻҪ��������һֱ����
//		{
//			//1.�ȼ���
//			//2.�ж϶����Ƿ�������û�У���ȴ�������������
//			//3.����ʱ��ȡ�������ݣ����� ��ȡ��������Ϊ��ִ������
//			//4.����
//			//5.ִ������ �����Run���ڽ���֮ǰ����ʧȥ�̲߳���������
//			//���ڴ˴�������������ޣ����Բ���֪ͨ�����ߣ�������������
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
//	bool PoolInit()                      //�̵߳Ĵ����Լ��������������ĳ�ʼ��
//	{
//		int i = 0;
//		pthread_mutex_init(&_mutex, NULL);    //�����������������ĳ�ʼ��һ��Ҫ�����̴߳���֮ǰ
//		pthread_cond_init(&_cond_con, NULL);
//		pthread_cond_init(&_cond_pro, NULL);
//		for (int i = 0; i<thr_num; i++)
//		{
//			pthread_t tid;
//			int ret = pthread_create(&tid, NULL, thr_start, (void *)this);   //���ʣ� ��ҪdetachûӰ��?
//			if (ret != 0)
//			{
//				std::cerr << "create thread error\n";
//				return false;
//			}
//			pthread_detach(tid);     //�̷߳���
//		}
//		return true;
//	}
//	bool TaskPush(ThreadTask &tt)
//	{
//		pthread_mutex_lock(&_mutex);    //����û��������ޣ����Բ�����ͬ���ȴ�����
//		_task_queue.push(tt);
//		pthread_mutex_unlock(&_mutex);
//		pthread_cond_signal(&_cond_con); //�����̳߳��е��̣߳���Ϊ�п�����Ϊû���������������ߣ�ÿ����һ�����񣬶���Ҫ�����̣߳���ȥ��������
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
