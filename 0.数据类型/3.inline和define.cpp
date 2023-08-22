#include "iostream"

using namespace std;
#define MAX(a, b) a>b?a:b

/**
 * inline 内联函数，类似于define函数，做到编译时替换
 * 使用场景：不涉及过于复杂的函数
 *
 * inline 和 define 区别：
 * （1）define不对参数进行有效性检测
 * （2）inline有严格的检测
 */
inline int max1(int num1, int num2) {
    return num1 > num2 ? num1 : num2;
};

int main() {
    int max = MAX(1, 2);
    cout << "max = " << max << endl;

    max = max1(1.2f, 2.2);
    cout << "max = " << max << endl;
}
