#include "iostream"
#include "string"

using namespace std;

void test1() {
    //这种方式如果访问错误位置，会抛异常(没法try catch住)或访问到其他错误数据
    string s1 = "hello";
    for (int i = 0; i < s1.size(); i++) {
        cout << s1[i] << " ";
    }
    cout << endl;

    //这种方式如果访问错误位置，会抛异常(可以try catch住)
    for (int i = 0; i < s1.size(); i++) {
        cout << s1.at(i) << " ";
    }
    cout << endl;

    s1[0] = 'x';
    s1.at(1) = 'h';
}


int main() {
    test1();
}