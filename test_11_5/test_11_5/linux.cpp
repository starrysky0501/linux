//�����ܵ��Ļ���ʹ��

//fifo.c
//#include <stdio.h>                                                                                             
//#include <unistd.h>
//#include <stdlib.h>
//#include <string.h>
//#include <fcntl.h>   //open��ͷ�ļ�
//#include <sys/stat.h>    //mkfifo������ͷ�ļ�
//#include <errno.h>
//
//int main()
//{
//	char* file = "./test.fifo";
//	int ret = mkfifo(file, 0664);
//	if (ret<0)
//	{
//		if (errno != EEXIST) //EEXIST������ļ��Ѿ����ڣ����޷�����
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
//			printf("�ܵ�û��д��~~����д�˱��ر�\n");
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
//�����ܵ��漰����Ϣ��
//�������裺
//1.�������նˣ�һ������ֻ����һ������ֻд����ֻ����һ��ʱ����������״̬��ֻ����һ��Ҳ���У���ܵ��ļ��򿪳ɹ�
//2.������д��д�����ݣ�����Կ�������buf������ݣ�ֻ��д�ˣ��Ż����������read��������״̬
//3.���ȹر�д�ˣ�����˷���0�����ȹر����ж��ˣ���д��ֱ�ӽ����˳���
//
//�����е�15�У���ΪEEXISTҲ��Ҳ��ʹret<0,��������ʹ�ò����ڣ���perror��ӡ����EEXIST���ֵĴ����ļ�������������


//fifo_write.c
//#include <stdio.h>                                                                                             
//#include <unistd.h>
//#include <stdlib.h>
//#include <string.h>
//#include <fcntl.h>   //open��ͷ�ļ�
//#include <sys/stat.h>    //mkfifo������ͷ�ļ�
//#include <errno.h>
//
//int main()
//{
//	char* file = "./test.fifo";
//	int ret = mkfifo(file, 0664);
//	if (ret<0)
//	{
//		if (errno != EEXIST) //EEXIST������ļ��Ѿ����ڣ����޷�����
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
//		if (ret == 0) //�ܵ������ж��˱��رգ�д�˾ʹ����쳣�ˣ�����׼ȷ��˵������ķ���ֵ����0
//		{
//			printf("�ܵ�û�˶���~~���ж��˱��ر�\n");
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


