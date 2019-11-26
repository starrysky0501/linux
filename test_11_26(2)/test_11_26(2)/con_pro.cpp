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
	std::vector<int> _queue;//ʹ������ʵ�ֻ��ζ���
	int _capacity; //��ʼ�����ζ��еĽڵ�����
	int _step_read;//��ǰ��λ�õ������±�
	int _step_write;//��ǰдλ�õ������±�
	sem_t _sem_lock;//�û�ʵ�ֻ������
	sem_t _sem_con;//�����ߵȴ����У��������������ݵĿռ���м���
	sem_t _sem_pro;//�����ߵȴ����У����������п��еĿռ���м���
public:
	RingQueue(int max_que = MAX_QUE) :_capacity(max_que),
		_queue(max_que), _step_read(0), _step_write(0)
	{
		//��ʼ���ź���
		sem_init(&_sem_lock, 0, 1);   //������ �̼߳� ֻ��0/1�ļ����� ������������1
		sem_init(&_sem_con, 0, 0);         //�����ߵȴ�����  ���ݵĽڵ�ĸ���
		sem_init(&_sem_pro, 0, max_que);   //�����ߵȴ�����  ���еĽڵ�ĸ���
	}
	~RingQueue()
	{
		//�����ź���
		sem_destroy(&_sem_lock);
		sem_destroy(&_sem_con);
		sem_destroy(&_sem_pro);
	}

	bool QueuePush(int &data)
	{
		//�������
		//1.�ж��Ƿ��ܹ������ٽ���Դ���жϿ��пռ�����Ƿ����0
		sem_wait(&_sem_pro);                      //�ж��������Ƿ����������ݣ��Կ��пռ���м���
		//2.�ȼ���
		sem_wait(&_sem_lock);
		//3.���ݵ���Ӳ���
		_queue[_step_write] = data;
		_step_write = (_step_write + 1) % _capacity;    //���õ��ĳ�������Ϊ�ź���������м���
		//4.����
		sem_post(&_sem_lock);
		//5.������Դ�Ŀռ����+1������������
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
		printf("consumer get data:%d\n", data);     //��ӡ�ͳ��Ӳ���ԭ�Ӳ��������Ի����һ�δ�ӡ����10��������                          
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
		printf("productor put data:%d\n", i++);     //��ӡ����Ӳ���ԭ�Ӳ���                     
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

//�������������ⲿ���������жϣ�����ȼ��������������ж�
//�ź�����ͨ������ļ�����ʵ���жϵģ�����Ҫ�������ڲ��Ѿ��Ըü��������б���
//����Զֻ�����ٽ���Դ
