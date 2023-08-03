#include "iostream"
#include "string"

using namespace std;

void test1() {
    string str = "hello";
    string substr = str.substr(1, 3);
    cout << substr << endl;
}

void test2() {
    string str = "hello@sina.com";
    int index = str.find('@');
    string name = str.substr(0, index);
    cout << name << endl;
}


int main() {
    test1();
    test2();
}