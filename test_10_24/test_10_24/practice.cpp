//#include<stdio.h>
//#include<unistd.h>
//#include<stdlib.h>
//#include<string.h>
//int main()
//{
//	FILE* fp = NULL;   //操作文件通过句柄操作，这是一个文件流指针
//	fp = fopen("./tmp.txt", "r+");//以覆盖的形式写入，从文件的起始位置开始，不清空文件内容
//	if (fp == NULL)
//	{
//		perror("fopen error");
//		return -1;
//	}
//	char ptr[] = "hello world!\n";
//	int ret = fwrite(ptr, strlen(ptr), 1, fp);//参数的含义：要写入的内容，块大小，块个数，要写入的文件流指针
//	printf("write item:%d\n", ret); 
//	fseek(fp, 0, SEEK_SET);//跳转到文件起始位置
//	char buf[1024] = { 0 };
//	ret = fread(buf, 1023, 1, fp);//第二个参数为1023，因为要保留一个字符串结束标识符，否则打印会出现乱码现象
//	printf("read buf :[%s]-ret:[%d]\n", buf, ret);
//	fclose(fp);//关闭文件，否则会造成资源泄露
//	return 0;
//}

//^@表示空，一般会在文件中显示（因为文件可以写入空数据）,freed会读完，但遇到空后，就显示不出来数据，处理不到


//#include<stdio.h>
//#include<unistd.h>
//#include<stdlib.h>
//int main()
//{
//	printf("leihaoa--bite-!"); //字符串被写到缓冲区，并非立即打印，换行符针对标准有缓冲区的作用和换行两个作用
//	sleep(3);
//	_exit(0);
//	exit(0);  //不会执行到return就返回
//	return 0;
//}