//命名管道的基本使用

//fifo.c
//#include <stdio.h>                                                                                             
//#include <unistd.h>
//#include <stdlib.h>
//#include <string.h>
//#include <fcntl.h>   //open的头文件
//#include <sys/stat.h>    //mkfifo函数的头文件
//#include <errno.h>
//
//int main()
//{
//	char* file = "./test.fifo";
//	int ret = mkfifo(file, 0664);
//	if (ret<0)
//	{
//		if (errno != EEXIST) //EEXIST：如果文件已经存在，则无法创建
//		{
//			perror("mkfifo error");
//			return -1;
//		}
//	}
//	int fd = open(file, O_RDONLY);
//	if (fd<0)
//	{
//		perror("open error");
//		return -1;
//	}
//	printf("open success\n");
//	while (1)
//	{
//		char buf[1024] = { 0 };
//		int ret = read(fd, buf, 1023);
//		if (ret == 0)
//		{
//			printf("管道没人写了~~所有写端被关闭\n");
//			return 0;
//		}
//		else if (ret<0)
//		{
//			perror("read error");
//			return -1;
//		}
//		printf("buf:[%s]\n", buf);
//	}
//	return 0;
//}
//命名管道涉及的信息：
//操作步骤：
//1.打开两个终端，一个运行只读，一个运行只写；当只运行一个时，则处于阻塞状态，只有另一个也运行，则管道文件打开成功
//2.接着在写端写入数据，则可以看到读端buf输出数据；只有写了，才会读出，否则read处于阻塞状态
//3.当先关闭写端，则读端返回0；当先关闭所有读端，则写端直接进程退出。
//
//代码中的15行：因为EEXIST也是也会使ret<0,所以我们使用不等于，用perror打印除了EEXIST出现的错误，文件创建不做处理。


//fifo_write.c
//#include <stdio.h>                                                                                             
//#include <unistd.h>
//#include <stdlib.h>
//#include <string.h>
//#include <fcntl.h>   //open的头文件
//#include <sys/stat.h>    //mkfifo函数的头文件
//#include <errno.h>
//
//int main()
//{
//	char* file = "./test.fifo";
//	int ret = mkfifo(file, 0664);
//	if (ret<0)
//	{
//		if (errno != EEXIST) //EEXIST：如果文件已经存在，则无法创建
//		{
//			perror("mkfifo error");
//			return -1;
//		}
//	}
//	int fd = open(file, O_WRONLY);
//	if (fd<0)
//	{
//		perror("open error");
//		return -1;
//	}
//	printf("open success\n");
//	while (1)
//	{
//		char buf[1024] = { 0 };
//		scanf("%s", buf);
//		int ret = write(fd, buf, strlen(buf));
//		if (ret == 0) //管道的所有读端被关闭，写端就触发异常了，所以准确来说，这里的返回值不是0
//		{
//			printf("管道没人读了~~所有读端被关闭\n");
//			return 0;
//		}
//		else if (ret<0)
//		{
//			perror("write error");
//			return -1;
//		}
//	}
//	return 0;
//}


