//这个demo体会共享内存的基本操作
//vim  shm.c
//#include <stdio.h>
//#include <unistd.h>
//#include <stdlib.h>
//#include <string.h>
//#include <sys/shm.h>
//#include <sys/ipc.h>
//
//#define IPC_KEY 0X12345678
//#define SHM_SIZE 4096
//
//int main()
//{
//	int shmid = shmget(IPC_KEY, SHM_SIZE, IPC_CREAT | 0664);
//	if (shmid<0)
//	{
//		perror("shmid error");
//		return -1;
//	}
//	//shmctl(shmid,IPC_RMID,NULL);//IPC_RMID:删除共享内存
//	//return 0;                                                                 
//	if (shm_start == (void *)-1)
//	{
//		perror("shmat error");
//		return -1;
//	}
//	int i = 0;
//	while (1)
//	{
//		✗         sprintf(shm_start, "%s-%d\n", "今天天气暖洋洋~", i++);//发送格式化输出给到shm_start所指向的地址
//		sleep(1);
//	}
//	shmdt(shm_start);
//	shmctl(shmid, IPC_RMID, NULL);//IPC_RMID:删除共享内存
//	return 0;
//}



//int  shmget(key_t key,size_t size,int shmflg);
//功能：创建共享内存
//参数：
//    key:共享内存在内核中的标志，其他进程通过相同的标志打开同一个内存
//    size:共享内存的大小
//    shmflg:IPC_CREAT |IPC_EXCL|mode
//    返回值：成功返回共享内存的操作句柄，失败返回-1
//
//功能演示：当去掉20和21行，我们起初先运行shm进程，接着在另一个终端运行shm_read进程，我们会发现数据不是从0
//开始写入。之后我们ctrl+c终止shm进程，发现，shm_read继续运行,但i值不变，ctrl+c后,再次运行shm_read，结果仍是运>
//的i值，说明共享内存并未销毁；
//接着进入shm进程，我们加上20和21行，先编译，ipcs查看共享内存信息，发现该共享区仍存在；运行shm后，发现该
//共享内存处于被销毁状态，键值也变为0，但链接数位1，之后CTRL+c关闭shm_read进程，ipcs发现，该共享内存以不在


//vim shm_read.c

//#include <stdio.h>
//#include <unistd.h>
//#include <stdlib.h>
//#include <string.h>
//#include <sys/shm.h>
//#include <sys/ipc.h>
//
//#define IPC_KEY 0X12345678
//#define SHM_SIZE 4096
//
//int main()
//{
//	int shmid = shmget(IPC_KEY, SHM_SIZE, IPC_CREAT | 0664);
//	if (shmid<0)
//	{
//		perror("shmid error");
//		return -1;
//	}
//	void *shm_start = shmat(shmid, NULL, 0);
//	if (shm_start == (void *)-1)
//	{
//		perror("shmat error");
//		return -1;
//	}
//	✹     int i = 0;
//	while (1)
//	{
//		printf("%s", (char *)shm_start);//直接打印，不用数据拷贝，区分管道
//		sleep(1);
//	}
//	shmdt(shm_start);
//	shmctl(shmid, IPC_RMID, NULL);//IPC_RMID:删除共享内存
//	return 0;
//}
