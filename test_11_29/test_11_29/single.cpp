//线程安全的单例模式的实现

//懒汉方式
//#include <iostream>
//#include <stdio.h>
//#include <mutex>
//
//std::mutex lock;                           //全局锁
//class Test
//{
//private:
//	volatile static int* data;     //实例化出来的对象那个，都使用的是同一个指针  防止编译器过度优化
//public:
//	volatile int *get_instance()           //在使用的时候初始化    操作了一个全局的临界资源(static),判断为NULL ，非线程安全。则需要加锁
//	{
//		if (data == NULL)            //减少锁冲突的概率，并不需要给他加锁
//		{
//			lock.lock();          //挂起等待不够实时，c++中的一个接口
//			if (data == NULL)        //等于NULL,才会加载一次；只有调用的时候才会初始化，不调用，不初始化；
//			{
//				data = new int;     //申请成功后，就不为空，就不会被初始化第二次   new的时候就会初始化内部各项资源
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




//饿汉模式
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
