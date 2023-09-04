#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
int main(int argc,const char*argv[]){
	int fd1,fd2,flag;
	char buffer[1];
    fd1 = open(argv[1],O_RDONLY);
    if(-1==fd1){
        printf("%s:%s\n",strerror(errno),argv[1]);
        return -1;
    }
    fd2 = open(argv[2],O_WRONLY|O_CREAT,S_IRUSR|S_IWUSR);
    if(-1==fd2){
        return -1;
    }
    while((flag=read(fd1,buffer,1))>0){
        write(fd2,buffer,flag);
    }
    close(fd1);
    close(fd2);
    return 0;
}
