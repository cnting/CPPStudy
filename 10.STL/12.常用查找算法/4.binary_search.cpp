#include "iostream"
#include "algorithm"
#include "vector"

using namespace std;
/**
 * binary_search：查找指定元素是否存在，返回bool
 * 这个方法在无序序列中不可用
 */

//查找内置数据类型
void test1() {
    vector<int> v;
    for (int i = 0; i < 10; i++) {
        v.push_back(i);
    }
    bool result = binary_search(v.begin(), v.end(), 9);
    cout << result << endl;
}

int main() {
    test1();
}
