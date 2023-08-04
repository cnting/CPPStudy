#include "iostream"
#include "stack"

using namespace std;

void test() {
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);

    while (!s.empty()) {
        s.pop();
    }
}

int main() {
    test();
}