#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

void print(int val) {
    cout << val << " ";
}

class ReplaceIf {
public:
    bool operator()(int val) {
        return val > 20;
    }
};

void test() {
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(20);
    v.push_back(20);
    v.push_back(30);
    v.push_back(30);
    v.push_back(30);
    v.push_back(30);

    replace_if(v.begin(), v.end(), ReplaceIf(), 40);
    for_each(v.begin(), v.end(), print);
}

int main() {
    test();
}