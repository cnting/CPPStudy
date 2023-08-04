#include "iostream"
#include "algorithm"
#include "vector"

using namespace std;
/**
 * adjacent_find：查找相邻重复元素
 * 如果找到，返回第一个元素位置的迭代器，否则返回end()
 */

//查找内置数据类型
void test1() {
    vector<int> v;
    v.push_back(0);
    v.push_back(2);
    v.push_back(0);
    v.push_back(3);
    v.push_back(1);
    v.push_back(4);
    v.push_back(3);  //返回这个位置
    v.push_back(3);
    //找相邻重复元素
    vector<int>::iterator it = adjacent_find(v.begin(), v.end());
    if (it == v.end()) {
        cout << "不存在" << endl;
    } else {
        cout << "存在:" << *it << endl;
    }
}

int main() {
    test1();
}
