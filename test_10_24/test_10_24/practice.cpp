//#include<stdio.h>
//#include<unistd.h>
//#include<stdlib.h>
//#include<string.h>
//int main()
//{
//	FILE* fp = NULL;   //�����ļ�ͨ���������������һ���ļ���ָ��
//	fp = fopen("./tmp.txt", "r+");//�Ը��ǵ���ʽд�룬���ļ�����ʼλ�ÿ�ʼ��������ļ�����
//	if (fp == NULL)
//	{
//		perror("fopen error");
//		return -1;
//	}
//	char ptr[] = "hello world!\n";
//	int ret = fwrite(ptr, strlen(ptr), 1, fp);//�����ĺ��壺Ҫд������ݣ����С���������Ҫд����ļ���ָ��
//	printf("write item:%d\n", ret); 
//	fseek(fp, 0, SEEK_SET);//��ת���ļ���ʼλ��
//	char buf[1024] = { 0 };
//	ret = fread(buf, 1023, 1, fp);//�ڶ�������Ϊ1023����ΪҪ����һ���ַ���������ʶ���������ӡ�������������
//	printf("read buf :[%s]-ret:[%d]\n", buf, ret);
//	fclose(fp);//�ر��ļ�������������Դй¶
//	return 0;
//}

//^@��ʾ�գ�һ������ļ�����ʾ����Ϊ�ļ�����д������ݣ�,freed����꣬�������պ󣬾���ʾ���������ݣ�������


//#include<stdio.h>
//#include<unistd.h>
//#include<stdlib.h>
//int main()
//{
//	printf("leihaoa--bite-!"); //�ַ�����д��������������������ӡ�����з���Ա�׼�л����������úͻ�����������
//	sleep(3);
//	_exit(0);
//	exit(0);  //����ִ�е�return�ͷ���
//	return 0;
//}