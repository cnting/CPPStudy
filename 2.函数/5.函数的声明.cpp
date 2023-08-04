#include "iostream"

using namespace std;
//函数提前声明
int max(int a, int b);

int main() {
    int a = 10;
    int b = 20;
    cout << max(a, b) << endl;
}

int max(int a, int b) {
    return a > b ? a : b;
}