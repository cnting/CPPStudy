#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

//普通函数
void print1(int val) {
    cout << val << " ";
}

//仿函数
class print2 {
public:
    void operator()(int val) {
        cout << val << " ";
    }
};

void test() {
    vector<int> v;
    for (int i = 0; i < 10; i++) {
        v.push_back(i);
    }
    //普通函数传函数名
    for_each(v.begin(), v.end(), print1);
    cout << endl;

    //函数对象要加()
    for_each(v.begin(), v.end(), print2());
}

int main() {
    test();
}
