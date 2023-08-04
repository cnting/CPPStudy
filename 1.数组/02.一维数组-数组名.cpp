#include "iostream"

using namespace std;

int main() {
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << "整个数组占用内存空间:" << sizeof(arr) << endl;
    cout << "每个元素占用内存空间:" << sizeof(arr[0]) << endl;
    cout << "数组中元素个数:" << sizeof(arr) / sizeof(arr[0]) << endl;

    cout << "数组首地址:"<< arr << endl;
    cout << "数组中第一个元素地址:"<< &arr[0] << endl;

    //数组名是常量，不可以进行赋值操作
    //arr = 100; //报错
}