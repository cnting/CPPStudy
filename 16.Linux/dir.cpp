#include<stdio.h>
#include<dirent.h>
#include<errno.h>
int main(int argc,char* argv[]){
	DIR *dir = opendir(argv[1]);
	if(dir==NULL){
		perror("open dir fail");
		return -1;
	}
	struct dirent* dirp;
	while((dirp=readdir(dir))!=NULL){
		printf("%s\t",dirp->d_name);
	}
	printf("\n");
	return 0;
}
