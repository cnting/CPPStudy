#include <unistd.h>
#include <stdio.h>
int main(int argc,const char* argv[]){
	pid_t pid = fork();
	

        if(pid==-1){
                 printf("fork error\n");
        }else if(pid==0){
		printf("I am child process! pid=%d, ppid=%d\n",getpid(),getppid());
                execlp("ls","ls","-l",NULL);
        }else{
                printf("I am parent,cpid = %d,pid=%d, ppid=%d\n",pid,getpid(),getppid());
        }
        printf("fork after\n");
        return 0;
}
