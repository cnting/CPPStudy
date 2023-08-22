#include "iostream"

using namespace std;
#define MAX(a, b) a>b?a:b

/**
 * inline 内联函数，类似于define函数，做到编译时替换
 * inline关键字必须在函数定义处，位于函数声明处则无效，因此一般将公共的inline函数的定义写在头文件中。
 *
 * inline 和 define 区别：
 * (1)处理阶段：宏定义define在预处理阶段就替换，inline是在编译期替换
 * (2)类型安全检测：define是简单的字符串替换，不存在类型安全检测，而inline会进行类型安全检测
 * (3)替换方式：define是单纯的字符串替换，inline是代码嵌入，也就是说编译器在函数调用的地方直接将inline函数代码写进去，这样就不会产生函数的调用跳转
 * (4)使用方式：define只要定义了就会替换，而inline只是建议，编译器可以拒绝替换
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
