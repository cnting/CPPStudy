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
    v.push_back(30);
    v.push_back(20);
    v.push_back(24);
    v.push_back(13);
    sort(v.begin(), v.end());
    for_each(v.begin(), v.end(), print);
    cout << endl;

    sort(v.begin(), v.end(), greater<int>());
    for_each(v.begin(), v.end(), print);
}

int main() {
    test();
}