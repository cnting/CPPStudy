#include "iostream"
#include "string"

using namespace std;

void test1() {
    string s1 = "hello";
    for (int i = 0; i < s1.size(); i++) {
        cout << s1[i] << " ";
    }
    cout << endl;
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