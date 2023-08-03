#include "iostream"
#include "string"

using namespace std;

void test1() {
    string str = "hello";
    str.insert(1, "111");

    str.erase(1, 3);
}


int main() {
    test1();
}