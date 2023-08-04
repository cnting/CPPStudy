#include "iostream"
#include "string"

using namespace std;

void test1() {
    string s1 = "hello";
    string s2 = "hello";
    if (s1.compare(s2) == 0) {
        cout << "相等" << endl;
    }else if(s1.compare(s2)>0){
        cout << "大于" << endl;
    }else{
        cout << "小于" << endl;
    }
}


int main() {
    test1();
}