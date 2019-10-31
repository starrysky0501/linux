//int pipefd[2] = { 0 };
//int ret = pipe(pipefd);
//if (ret<0)
//{
//	perror("pipe error");
//	return -1;
//}
//int pid1 = fork();
//if (pid1 == 0)
//{
//	//进程1实现ps
//	close(pipefd[0]);
//	dup2(pipefd[1], 1); //向标准输出写入数据改变为向管道写入数据
//	execlp("ps", "ps", "-ef", NULL); //程序替换,该程序完成，自己会关闭pipefd[1]
//	exit(0);   //1子进程退出
//}
//int pid2 = fork();
//if (pid2 == 0)
//{
//	//进程2实现grep
//	close(pipefd[1]);    //当程序关闭所有的写端，read读完管道中的数据后，则read不会阻塞，则返回0。    
//	dup2(pipefd[0], 0); //从标准输入读数据改变为从管道读数据
//	execlp("grep", "grep", "ssh", NULL); //程序替换
//	exit(0);   //2子进程退出
//}
//close(pipefd[0]);
//close(pipefd[1]);  //要将管道的所有的写端关闭
//waitpid(pid1, NULL, 0);//等待两个子进程退出
//waitpid(pid2, NULL, 0);//阻塞式接口，第一个参数是父进程的pid,该处只是为了表达清楚
//return 0;
//}


//1.ps和grep是别人写的程序，没办法修改他们的代码，ps向标准输出写入数据，grep从标准输入读取数据
//2.标准输入没数据，则被阻塞，标准输入scanf就是，grep同样的道理。
//3.重定向：改变ps和grep的写入和读出文件
//4。代码中的dup2可以使管道完成通信
//5.管道哪端不适用就把哪端关掉
//6.grep的特性：一直从管道中读数据，没人限制读多少，但写多少都多少，所以当管道中没数据的时候则会持续阻塞，等待数据，进程不会退出。