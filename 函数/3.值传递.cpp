#include "iostream"

using namespace std;

void swap(int num1, int num2) {
    int temp = num1;
    num1 = num2;
    num2 = temp;

    cout << "num1:" << num1 << endl;
    cout << "num2:" << num2 << endl;
}

int main() {
    int a = 10;
    int b = 20;

    //值传递时，形参改变不会影响实参
    swap(a, b);
    cout << "a:" << a << endl;
    cout << "b:" << b << endl;
}