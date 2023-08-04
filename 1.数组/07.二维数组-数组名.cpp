#include "iostream"

using namespace std;

int main() {
    int arr[2][3] = {
            {1, 2, 3},
            {4, 5, 6}
    };
    cout << "二维数组占用内存空间:" << sizeof(arr) << endl;
    cout << "二维数组第一行占用内存空间:" << sizeof(arr[0]) << endl;
    cout << "二维数组第一个元素占用内存空间:" << sizeof(arr[0][0]) << endl;
    cout << "行数:" << sizeof(arr) / sizeof(arr[0]) << endl;
    cout << "列数:" << sizeof(arr[0]) / sizeof(arr[0][0]) << endl;

    cout << "二维数组首地址:" << arr << endl;
    cout << "二维数组第一行首地址:" << arr[0] << endl;
    cout << "二维数组第二行首地址:" << arr[1] << endl;
    cout << "第一个元素首地址:" << arr[0][0] << endl;

}