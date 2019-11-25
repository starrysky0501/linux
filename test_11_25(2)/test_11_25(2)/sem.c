#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
//�ź���ʵ�ֻ���
sem_t sem;
int tickets = 100;
void *thr_eat(void *arg)
{
	while (1)
	{
		sem_wait(&sem);   //�������жϵ�ǰ��״̬�Ƿ���Է��ʣ��ܷ��ʣ��������� -1   P����
		if (tickets>0)
		{
			usleep(5000);
			printf("i get tickets:%d\n", tickets--);
			sem_post(&sem);   //����  +1    V����
		}
		else
		{
			sem_post(&sem);      //���߳��κο����˳��ĵط�����Ҫ���� 
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
	sem_init(&sem, 0, 1);   //�˴���1����ʾ����һ��״̬�жϣ�����Ϊ����Դ��������ʾͬʱֻ��һ���߳̿��Է��ʡ�

	ret = pthread_create(&tid1, NULL, thr_eat, NULL);   //���ڻ�����˵��������ͬ�Ľ�ɫ�����ǹ˿�
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




//ʹ���ź���ʵ��ͬ��,��ʦ����͹˿ͳ���ĳ�����ʵ��һ��һ�ĳ���
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
sem_wait(&sem);      // �����ж���û���棬û�棬�͵ȴ���
printf("delicious~~~\n");
}
return NULL;
}

void *thr_cook(void *arg)    //��ʦ���������Գ�ʦûҪ��
{
while(1)
{
printf("cook noodle~~\n");
sem_post(&sem);     //����һ���棬�������ľͻ��ѣ�����+1��û�ͼ���+1
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
