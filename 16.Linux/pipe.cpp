#include<stdio.h>
#include<unistd.h>
int main(){
	int fd[2];
	pid_t pid;
	char buf[20];
	int ret = pipe(fd);
	if(ret!=0){
		printf("create pipe error\n");
	}
	pid = fork();
	if(pid<0){
		printf("fork error\n");
	}else if(pid==0){
		//子进程
		close(fd[1]); //关闭写端
		//等等再读
		sleep(1);
		read(fd[0],buf,11);
		printf("pipe read:%s",buf);
	}else{
		//父进程
		close(fd[0]); //关闭读端
		write(fd[1],"hello pipe\n",11);	
	}
	return 0;
}
