#include "iostream"
#include "vector"
#include "algorithm"
#include "ctime"

using namespace std;

void print(int val) {
    cout << val << " ";
}

void test() {
    vector<int> v1;
    for (int i = 0; i < 10; i++) {
        v1.push_back(i);
    }
    for_each(v1.begin(), v1.end(), print);
    cout << endl;
    reverse(v1.begin(), v1.end());
    for_each(v1.begin(), v1.end(), print);
    cout << endl;
}

int main() {
    test();
}