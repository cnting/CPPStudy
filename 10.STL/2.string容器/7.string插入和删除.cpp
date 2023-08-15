#include "iostream"
#include "string"

using namespace std;

void test1() {
    string str = "hello";
    str.insert(1, "111");
    cout << str << endl;

//    str.erase(1, 3);
    str.erase(0);  //第二个参数默认到字符串结尾，也就是全删了

    cout << str << endl;
}


int main() {
    test1();
}