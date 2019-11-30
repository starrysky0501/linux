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
//			lock.lock();          //挂起等待不够实时，c++中的一个接口//			if (data == NULL)        //等于NULL,才会加载一次；只有调用的时候才会初始化，不调用，不初始化；
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


//单例模式是一种比较典型的设计模式，是大佬们针对典型场景而设计出的解决方案，其中单例模式，指的是一个对象/资源只能被实例化加载一次。
//(1)饿汉：所有的资源加载/对象实例化都放在程序的初始化阶段，接下来在各个线程中直接使用即可
//        优点：资源直接加载，运行时性能会比较高以及运行比较流畅
//        缺点：将当前不用的资源也加载到内存中，因此资源消耗较大，初始化阶段耗时较长   
//        静态成员的特性：不管实例化多少对象，这个成员占的内存只有一份，在程序运行起始阶段已经初始化完毕。
//(2)懒汉：资源并不在程序初始化阶段全部加载/初始化，而是等到使用的时候才去做判断来加载/初始化资源。
//        优点：初始化比较快，在运行阶段使用的时候也只需要加载一次（若不释放）
//        实现：
//          实现最基本的单例模式
//          防止编译器过度优化volatile
//          保证初始化加载过程线程安全
//          尽可能的避免锁冲突
