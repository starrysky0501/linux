//ͨ�������demo����ٽ���Դ���ʵ�ʱ��������Լ����������Ļ���ʹ��
//��ͬ�Ľ�ɫ�ȴ��ڲ�ͬ�Ķ����ϣ����ж����ɫ������Ҫ����ȴ�����
/*#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

int is_have_noodle = 0;  //��������������������,һ��ʼû���棬��Ϊ0
pthread_cond_t cond_foodie;   //����һ����������
pthread_cond_t cond_chef;
pthread_mutex_t mutex;

void* foodie(void *arg)
{
	while (1)
	{
		pthread_mutex_lock(&mutex);
		while (is_have_noodle == 0)      //�������ѭ������,��������������˵���wait���ϣ������ǿ������������ĵȴ������ϣ�����һ��������������࿨��wait���ϵĲ��ж��Ƿ���������������ִ�С�
		{
			pthread_cond_wait(&cond_foodie, &mutex);
		}
		printf("eat noodles,delicious~~!\n");
		is_have_noodle--;
		pthread_mutex_unlock(&mutex);
		pthread_cond_signal(&cond_chef);  //���ٻ���һ��
		//pthread_cond_broadcast  �㲥����������
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
		pthread_mutex_unlock(&mutex);  //�Ƚ����ڻ��ѣ���������ͻ
		pthread_cond_signal(&cond_foodie);
	}
	return NULL;
}

#define MAX_FOODIE 4
int main()
{
	pthread_t foodie_tid, chef_tid;  //����tid
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

	pthread_join(foodie_tid, NULL); //����ȴ��������̵߳��˳�����Ϊû����䣬���߳����е��˴������ֱ��return���˳�����
	pthread_join(chef_tid, NULL);

	pthread_cond_destroy(&cond_foodie);
	pthread_cond_destroy(&cond_chef);
	pthread_mutex_destroy(&mutex);
	return 0;
}*/

//����������ʵ��ͬ���ı�����
//��������ֻ�ṩ�ȴ��뻽�ѵĹ��ܣ������������жϣ�ʲôʱ��ȴ����ѣ����û��Լ�����
//ʹ�ù����ѵķ�ʽ����ʵʱ�����ӽ�ʡcpu����Դ�������������ӷ���
//ͨ�������demo����ٽ���Դ���ʵ�ʱ��������Լ����������Ļ���ʹ��
//�����̴ӿ��ж�����״̬ת��Ϊ����״̬�����ý����õ�ʱ��Ƭ�Ϳ������С�
//�û��������ж���Ҫʹ��whileѭ�������жϣ������ѵĶ���̣߳��п��ܶ��ȴ������ϣ���������ʱ���п����߳�
//    �ڲ��߱���������������£������ɹ�������Դ����)
//��ͬ�Ľ�ɫҪʹ�ö�������������ҵȴ��ڲ�ͬ������������










//ʵ��һ��һ�ĳ���������һ���棬��һ����,ֻ��һ������ͳ������     ������ʱû����
/*#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

int is_have_noodle = 0;  //��������������������,һ��ʼû���棬��Ϊ0
pthread_cond_t cond;   //����һ����������
pthread_mutex_t mutex;

void* foodie(void *arg)
{
	while (1)
	{
		pthread_mutex_lock(&mutex);
		if (is_have_noodle == 0)
		{
			//��������������ԭ�Ӳ�������������������װΪpthread_cond_wait����
			// pthread_mutex_unlock(&mutex);                                 //����
			// pause();  //���𣬳�����ͣ�����ж�����                        //����
			// pthread_mutex_lock(&mutex);    //��������ܳ���               //�����Ѻ����
			//��û���棬�������Ӧ���������������ȥ���棬���ǽ��������߱�����һ��ԭ�Ӳ���
			//��Ϊ������������֮�䱻��ϣ���ʦ���滽�ѳ�����˵�ʱ�򣬳�����˻�û�����ߣ�
			//�Ͱ׻����ˣ�������Ϊû�еڶ��λ��ѣ�������˾��п��ܻ���������
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
		pthread_mutex_unlock(&mutex);  //�Ƚ����ڻ��ѣ���������ͻ
		pthread_cond_signal(&cond);
	}
	return NULL;
}

int main()
{
	pthread_t foodie_tid, chef_tid;  //����tid
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

	pthread_join(foodie_tid, NULL); //����ȴ��������̵߳��˳�����Ϊû����䣬���߳����е��˴������ֱ��return���˳�����
	pthread_join(chef_tid, NULL);

	pthread_cond_destroy(&cond);
	pthread_mutex_destroy(&mutex);
	return 0;
}
*/





