#include "iostream"
#include "algorithm"
#include "vector"

using namespace std;

/**
 * 预留空间，可以减少vector在动态扩展容量时的扩展次数
 * reserve(int len) //容器预留len个元素长度，预留位置不初始化，元素不可访问
 */
void print(vector<int> &v) {
    for (auto it = v.begin(); it < v.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}

void test1() {
    vector<int> v1;

    //利用reserve预留空间
    v1.reserve(100000);

    int num = 0;  //统计开辟次数
    int *p = NULL;
    for (int i = 0; i < 100000; i++) {
        v1.push_back(i);
        if (p != &v1[0]) {
            p = &v1[0];
            num++;
        }
    }
    cout << "分配次数:" << num << endl;
}

int main() {
    test1();
}