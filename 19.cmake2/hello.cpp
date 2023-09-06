#include<stdio.h>
#include "add.h"
#include "sub.h"
#include "div.h"
#include "multi.h"
int main(){
	int a = 20,b = 10;
	printf("%d+%d=%d\n",a,b,add(a,b));
	printf("%d=%d=%d\n",a,b,sub(a,b));
	printf("%d*%d=%d\n",a,b,multi(a,b));
	printf("%d/%d=%d\n",a,b,div(a,b));
	return 0;
}
