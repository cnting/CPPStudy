#include "iostream"
#include "string"

using namespace std;

//查找
void test1() {
    string s1 = "abcdefgde";
    int pos = s1.find("de");
    cout << "pos=" << pos << endl;

    //rfind是从右往左查
    pos = s1.rfind("de");
    cout << "pos=" << pos << endl;

}

//替换
void test2() {
    string str1 = "abcdefg";
    str1.replace(1, 3, "1111");
    cout << "str1=" << str1 << endl;

}

int main() {
    test1();
    test2();
}