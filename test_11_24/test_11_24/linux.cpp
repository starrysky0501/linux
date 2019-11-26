//手撕生产者与消费者模型

//使用条件变量和互斥锁实现一个安全队列
#include<iostream>
#include<queue>
#include<stdio.h>
#include<unistd.h>
#include<pthread.h>

#define MAX_QUE 10

class BlockQueue
{
    private:
        std::queue<int> _queue;   //使用链表实现的队列，是一个动态增长的队列，我们如今要实现的是一个阻塞队列，当队列放满，就不能放
        int _capacity;            //队列的最大容量

        //队列的线程安全
        //实现同步，条件变量，不同的角色要等在不同的条件变量上
        pthread_cond_t _cond_productor;  //生产者等待队列
        pthread_cond_t _cond_consumer;   //消费者等待队列
        pthread_mutex_t _mutex;          //保证安全，实现互斥，采用互斥锁
    public:
        //确定队列的最大容量数，初始条件变量和互斥锁
        BlockQueue(int que_num=MAX_QUE)
            :_capacity(que_num)
        {
            pthread_mutex_init(&_mutex,NULL);
            pthread_cond_init(&_cond_consumer,NULL);
            pthread_cond_init(&_cond_productor,NULL);
        }
        
        //销毁条件变量和互斥锁
        ~BlockQueue()
        {

            pthread_mutex_destroy(&_mutex);
            pthread_cond_destroy(&_cond_consumer);
            pthread_cond_destroy(&_cond_productor);
        }
        
        //提供给生产者的接口，数据入队
        bool QueuePush(int &data)
        {
            pthread_mutex_lock(&_mutex);      //queue是临界资源，需要加锁保护
            while(_queue.size()==_capacity)   //判断队列节点是否添加满了，必须while，因为要支持并发。
            {
                pthread_cond_wait(&_cond_productor,&_mutex);
            }
            _queue.push(data);
            pthread_mutex_unlock(&_mutex);
            pthread_cond_signal(&_cond_consumer);
            return true;
        }
        
        //提供给消费者的接口，数据出队
        bool QueuePop(int &data)
        {
            pthread_mutex_lock(&_mutex);    //加锁保护临界资源queue
            while(_queue.empty())           //循环判断，支持并发
            {
                pthread_cond_wait(&_cond_consumer,&_mutex);
            }
            data=_queue.front();      //读指针并没有向后移动，只是读队首元素
            _queue.pop();
            pthread_mutex_unlock(&_mutex);
            pthread_cond_signal(&_cond_productor);
            return true;
        }
};


void *thr_consumer(void *arg)
{
    BlockQueue *queue=(BlockQueue*)arg;
    while(1)
    {
        int data;
        queue->QueuePop(data);   //如果没数据，会在QueuePop中被阻塞，并且此处不用考虑线程安全，因为在QueuePop中已实现。
        printf("**get a data:%d\n",data);
    }
    return NULL;
}

void *thr_productor(void *arg)
{
    int i=0;
    BlockQueue *queue=(BlockQueue*)arg;
    while(1)
    {
        queue->QueuePush(i);                  //入队和打印并非原子操作，线程有多个，每次打印获取的个数多余10个很正常。
        printf("--put a data:%d\n",i++);      //每个线程获取的每个数据肯定是唯一的，因为是线程安全的。
    }
    return NULL;
}

#define MAX_THREAD 4

int main()
{
    int i,ret;
    pthread_t ctid[MAX_THREAD],ptid[MAX_THREAD];
    BlockQueue queue;                                   //也可以将他声明为全局变量，就不需要传参。
    for(i=0;i<MAX_THREAD;i++)
    {
        ret=pthread_create(&ctid[i],NULL,thr_consumer,(void*)&queue);   //第四个参数，一般传入的是临界资源，生产者和消费者都要访问线程安全的队列
        if(ret!=0)
        {
            std::cerr<<"thread create error\n";
            return -1;
        }
    }
    for(i=0;i<MAX_THREAD;i++)
    {
        ret=pthread_create(&ptid[i],NULL,thr_productor,(void*)&queue);   //第四个参数，一般传入的是临界资源，生产者和消费者都要访问线程安全的队列
        if(ret!=0)
        {
            std::cerr<<"thread create error\n";
            return -1;
        }
    }
    for(i=0;i<MAX_THREAD;i++)
    {
        pthread_join(ctid[i],NULL);
        pthread_join(ptid[i],NULL);
    }
    return 0;
}

//printf把字符串组装成一个整体，打印的。
//在多线程的设计模式下，如果多个线程都使用cout打印信息，很容易出现内容交替的现象
//cout不是线程安全的，要靠自己线程同步，比较麻烦；printf是线程安全的，自己本身做了线程同步的原理。
