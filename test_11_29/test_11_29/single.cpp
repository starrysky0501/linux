//�̰߳�ȫ�ĵ���ģʽ��ʵ��

//������ʽ
//#include <iostream>
//#include <stdio.h>
//#include <mutex>
//
//std::mutex lock;                           //ȫ����
//class Test
//{
//private:
//	volatile static int* data;     //ʵ���������Ķ����Ǹ�����ʹ�õ���ͬһ��ָ��  ��ֹ�����������Ż�
//public:
//	volatile int *get_instance()           //��ʹ�õ�ʱ���ʼ��    ������һ��ȫ�ֵ��ٽ���Դ(static),�ж�ΪNULL �����̰߳�ȫ������Ҫ����
//	{
//		if (data == NULL)            //��������ͻ�ĸ��ʣ�������Ҫ��������
//		{
//			lock.lock();          //����ȴ�����ʵʱ��c++�е�һ���ӿ�
//			if (data == NULL)        //����NULL,�Ż����һ�Σ�ֻ�е��õ�ʱ��Ż��ʼ���������ã�����ʼ����
//			{
//				data = new int;     //����ɹ��󣬾Ͳ�Ϊ�գ��Ͳ��ᱻ��ʼ���ڶ���   new��ʱ��ͻ��ʼ���ڲ�������Դ
//				*data = 4;
//			}
//			lock.unlock();
//		}
//		return data;
//	}
//};
//
//volatile int *Test::data = NULL;
//
//int main()
//{
//	Test a, b;
//	printf("%d-%p\n", *a.get_instance(), a.get_instance());
//	printf("%d-%p\n", *b.get_instance(), b.get_instance());
//	return 0;
//}




//����ģʽ
//#include <iostream>
//#include <stdio.h>
//class Test
//{
//private:
//	static int data;
//public:
//	int * get_instance()
//	{
//		return &data;
//	}
//};
//
//int Test::data = 10;
//int main()
//{
//	Test a, b;
//	printf("%d-%p\n", *a.get_instance(), a.get_instance());
//	printf("%d-%p\n", *b.get_instance(), b.get_instance());
//	return 0;
//}
