//ͨ����ţ��Ʊ����������̰߳�ȫ����Ҫ���Լ���ʶ������
//#include<stdio.h>
//#include<unistd.h>
//#include<stdlib.h>
//#include<pthread.h>
//
//#define MAX_THR 4
//int tickets = 100;
//pthread_mutex_t mutex;    //��������Ϊ�����ٽ���Դ�����ݣ���Ҫ��ÿ���̷߳��ʵ������Խ�������Ϊȫ�ֱ���
//
//void *cattle(void *arg)     //�̵߳���ں�����ģ��ʵ�ֻ�ţ��Ʊ,�ٿ�һ��ȫ�ֱ���
//{
//	while (1)
//	{
//		pthread_mutex_lock(&mutex);
//
//		if (tickets>0)
//		{
//			printf("%p i get a ticket:%d\n", pthread_self(), tickets);
//			usleep(1000); //��λ��΢��
//			tickets--; //��Ʊ��Ҫ�и�����
//			pthread_mutex_unlock(&mutex);
//		}
//		else
//		{
//			printf("have no tickets\n");
//			pthread_mutex_unlock(&mutex);  //����֮����Ҫ�������п����˳��̵߳ĵط���Ҫ���н���
//			pthread_exit(NULL);
//		}
//	}
//	return NULL;
//}
//
//int main()
//{
//	pthread_t tid[MAX_THR];
//	pthread_mutex_init(&mutex, NULL);//(��ʼ��)һ��Ҫ���ڴ����߳�֮ǰ,��Ϊһ���������̣߳�˭�����оͲ�һ���ˡ�
//	int i = 0, j = 0;
//	for (i = 0; i<MAX_THR; i++)
//	{
//		int ret = pthread_create(&tid[i], NULL, cattle, NULL);  //�̴߳���
//		if (ret != 0)
//		{
//			printf("thread create error\n");
//			return -1;
//		}
//	}
//	for (j = 0; j<MAX_THR; j++)
//	{
//		pthread_join(tid[j], NULL);    //�̵߳ȴ�
//	}
//	pthread_mutex_destroy(&mutex); //���ٻ�����
//	return 0;
//}
//1.�ȳ�ʼ�������ٴ����߳�
//2.��������Ϊ�˱����ٽ���Դ�Ĳ����������Ĳ���һ�Ų�������������λ�ã�һ��Ҫ���ٽ���Դ����֮ǰ��
//3.���������ַ�ʽ��
//  pthread_mutex_lock  ��������
//  pthread_mutex_trylock  ����������
//  pthread_mutex_timedlock ��������ʱ������������
//4.�����³��������޷��ƽ�������Գ�Ϊ���������߳��м���������Ҫ�������߳̿����˳��ĵط�����
