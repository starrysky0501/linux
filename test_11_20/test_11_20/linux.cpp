//����tid�ĺ���
//#include <stdio.h>
//#include <unistd.h>
//#include <stdlib.h>
//#include <pthread.h>
//
//void *thr_start(void *arg)
//{
//	while (1)
//	{
//		printf("child thread---%s\n", (char*)arg);
//		sleep(1);
//	}
//	return NULL;
//}
//
//int main()
//{
//	pthread_t tid;
//	char *ptr = "this is thread\n";
//	int ret = pthread_create(&tid, NULL, thr_start, (void*)ptr); //�����߳�
//	if (ret != 0)
//	{
//		perror("thread create error");
//		return -1;
//	}
//	while (1)
//	{
//		printf("main thread---%p\n", tid);
//		sleep(1);
//	}
//	return 0;
//}


//�̵߳������˳���ʽ
//#include <stdio.h>
//#include <unistd.h>
//#include <stdlib.h>
//#include <pthread.h>
//
//void *thr_start(void *arg)
//{
//	//sleep(5);
//	//return NULL; //�̵߳ĵ�һ���˳���ʽ��return�˳�һ���̣߳���������
//
//	//sleep(5);
//	//pthread_exit(NULL); //�̵߳ĵڶ����˳���ʽ������Ϊ�˳��ķ���ֵ����������
//	while (1)
//	{
//		printf("child thread---%s\n", (char*)arg);
//		sleep(1);
//	}
//	return NULL;
//}
//int main()
//{
//	pthread_t tid;
//	char *ptr = "this is thread\n";
//	int ret = pthread_create(&tid, NULL, thr_start, (void*)ptr);
//	if (ret != 0)
//	{
//		perror("thread create error");
//		return -1;
//	}
//
//	//pthread_exit(NULL); //�˳����̣߳�ʹ���̱߳�Ϊ��ʬ�̣߳���os��û�н�ʬ�߳��������
//
//	sleep(5);
//	pthread_cancel(tid);  //�̵߳ĵ������˳���ʽ,����ָ���˳����̣߳�ȡ��һ���̡߳�
//	while (1)
//	{
//		printf("main thread---%p\n", tid);
//		sleep(1);
//	}
//	return 0;
//}



//�̵߳ȴ�
//#include <stdio.h>
//#include <unistd.h>
//#include <stdlib.h>
//#include <pthread.h>
//void *thr_start(void *arg)
//{
//	sleep(5);
//	char *ptr = "jintianhaoleng~~\n";     //ptrָ��ĳ������׵�ַ���ó�����ַ����ջ���߳��˳��������ͷ�����ռ�.ֻ��ջ�Ŀռ���ÿ���̶߳��еġ�
//	char ptr[] = "jintianhaoleng~~\n";  //ptr��һ���ֲ��������߳��˳���������  
//	pthread_exit(ptr);                  //��ptr��Ϊ����ֵ
//
//	while (1)
//	{
//		printf("child thread---%s\n", (char*)arg);
//		sleep(1);
//	}
//	return NULL;
//}
//int main()
//{
//	pthread_t tid;
//	char *ptr = "this is thread\n";
//	int ret = pthread_create(&tid, NULL, thr_start, (void*)ptr);
//	if (ret != 0)
//	{
//		perror("thread create error");
//		return -1;
//	}
//
//
//	char *retval;     //��������ﶨ�����ָ�룬������Ϊ���������ܸ�NULL��񣬶��ᵼ�³���δ���
//	pthread_join(tid, (void**)&retval);  //ע�⣺�ú����ĵڶ���������һ������ָ�룬Ҫ�����̵߳ķ���ֵ������봫��һ��ָ��ĵ�ַ.
//	printf("retval:%s\n", retval);
//
//	while (1)
//	{
//		printf("main thread---%p\n", tid);
//		sleep(1);
//	}
//	return 0;
//}

//�̷߳���
//#include <stdio.h>
//#include <unistd.h>
//#include <stdlib.h>
//#include <pthread.h>
//void *thr_start(void *arg)
//{
//	pthread_detach(pthread_self());
//	sleep(5);
//	char *ptr = "jintianhaoleng~~\n";     //ptrָ��ĳ������׵�ַ���ó�����ַ����ջ���߳��˳��������ͷ�����ռ�.ֻ��ջ�Ŀռ���ÿ���̶߳��еġ�
//	pthread_exit(ptr);
//
//	while (1)
//	{
//		printf("child thread---%s\n", (char*)arg);
//		sleep(1);
//	}
//	return NULL;
//}
//int main()
//{
//	pthread_t tid;
//	char *ptr = "this is thread\n";
//	int ret = pthread_create(&tid, NULL, thr_start, (void*)ptr);
//	if (ret != 0)
//	{
//		perror("thread create error");
//		return -1;
//	}
//
//	//pthread_detach(tid);//�̷߳��룬���ȡ��������ֵ����Ϊ�ǿ��ڴ��Ѿ����ͷš������ӡ�����������
//	sleep(1);  //�˴������þ��ǣ�����ʹ�´������߳�һ�����ȡ��cpu��ʱ��Ƭ���Ӷ�pthread_join��ȡ��������ֵ����������̻߳�û���õ���ʱ��Ƭ��pthread_join�Ϳ��Ի�ȡ������ֵ
//	char *retval;
//	pthread_join(tid, (void**)&retval);  //ע�⣺�ú����ĵڶ���������һ������ָ�룬Ҫ�����̵߳ķ���ֵ������봫��һ��ָ��ĵ�ַ.
//	printf("retval:%s\n", retval);
//
//	while (1)
//	{
//		printf("main thread---%p\n", tid);
//		sleep(1);
//	}
//	return 0;
//}
