#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

/**
 * transform 搬运容器到另一个容器中
 */

class Transform {
public:
    int operator()(int v) {
        return v + 1000;
    }
};

class MyPrint {
public:
    void operator()(int v) {
        cout << v << " ";
    }
};

void test() {
    vector<int> v;
    for (int i = 0; i < 10; i++) {
        v.push_back(i);
    }
    vector<int> vTarget;
    //注意要扩容
    vTarget.resize(v.size());
    transform(v.begin(), v.end(), vTarget.begin(), Transform());

    for_each(vTarget.begin(), vTarget.end(), MyPrint());
    cout << endl;
}

int main() {
    test();
}
