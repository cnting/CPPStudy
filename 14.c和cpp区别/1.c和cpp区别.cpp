
#include <cstdio>

void test1(){
    //register把a变量放到寄存器里，在c中寄存器的变量不能取地址
    //下面这行代码在c++中可以，在c中不行
    register int a = 10;
    printf("%d",&a);
}

void test2(){

}

int main(){


}