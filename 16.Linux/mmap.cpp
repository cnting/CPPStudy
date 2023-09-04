#include<stdio.h>
#include<stdlib.h>
#include <sys/mman.h>
#include<string.h>
#include<errno.h>
#include<fcntl.h>
#include<unistd.h>
void sys_err(const char* msg){
	perror(msg);
	exit(0);
}
int main(){
	/**
	* addr:地址，一般可以不传(NULL)
	* length:内存的大小
	* prot:PROT_EXEC:内容可以被执行
	*      PROT_READ:内容可以被读取
	*      PROT_WRITE:内容可以被写
	*      PROT_NONE:内容不可访问
	* flags:MAP_SHARED 共享
	* 	MAP_PRIVATE 私有
	* 	MAP_ANONYMOUS 匿名映射（不基于文件）,fd就传-1
	* fd:文件句柄
	* offset:偏移大小，必须是4k的整数倍（因为一个物理页映射是4k）
	**/
	
	//打开一个文件
	int fd;
	char* p;
	fd = open("test_map",O_RDWR|O_CREAT|O_TRUNC,0644);
	if(fd==-1){
		sys_err("open file error");
	}
	//要把文件变大
	ftruncate(fd,20);
	p = (char *)mmap(NULL,20,PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);
	
	//这里关闭不会影响mmap操作，因为mmap是走内存映射的方式，而不是通过内核空间那套了
	//close(fd);
	
	if(p==MAP_FAILED){
		sys_err("mmap error");
	}
	//假如这里用write方式写，mmap也是可以读到的
	write(fd,"hello mmap0125\n",16);
	
	//通过mmap方式写
	//strcpy(p,"hello mmap\n");
	printf("--->%s",p);

	//要记得释放mmap
	munmap(p,20);
	return 0;
}
