#include "iostream"
#include "set"

using namespace std;

void test1() {
    //第一种创建方式
    pair<string, int> p("Tom", 10);
    cout << p.first << " " << p.second << endl;

    //第二种创建方式
    pair<string,int> p2 = make_pair("Jerry",30);
    cout << p2.first << " " << p2.second << endl;

}

int main() {
    test1();
}