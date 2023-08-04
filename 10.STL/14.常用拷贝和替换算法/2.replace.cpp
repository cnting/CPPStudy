#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

void print(int val) {
    cout << val << " ";
}

void test() {
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(20);
    v.push_back(20);
    v.push_back(30);

    replace(v.begin(), v.end(),20,40);
    for_each(v.begin(), v.end(), print);
}

int main() {
    test();
}