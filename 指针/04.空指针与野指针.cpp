#include "iostream"

using namespace std;

int main() {
    //空指针：指针变量指向内存中编号为0的空间
    //用途：初始化指针变量
    //注意：空指针指向的内存是不可以访问的
    int *p = NULL;

    //野指针：随便指向的一个地址
    int * a = (int *)0x1100;
}
