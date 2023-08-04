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
    v.push_back(30);

    vector<int> v2;
    v2.push_back(1000);
    v2.push_back(2000);
    v2.push_back(3000);

    cout << "交换前" << endl;
    for_each(v.begin(), v.end(), print);
    cout << endl;
    for_each(v2.begin(), v2.end(), print);
    cout << endl;

    swap(v, v2);
    cout << "交换后" << endl;
    for_each(v.begin(), v.end(), print);
    cout << endl;
    for_each(v2.begin(), v2.end(), print);
}

int main() {
    test();
}