#include "iostream"
#include "list"

using namespace std;

/**
 * list不支持随机访问，不能通过[]或at()来访问元素
 * 因为list本质是链表，不是用连续线性空间存储数据，迭代器也是不支持随机访问的
 */
void print(const list<int> &l) {
    for (list<int>::const_iterator it = l.begin(); it != l.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}

void test1() {
    list<int> l1;
    l1.push_back(10);
    l1.push_back(20);
    l1.push_back(30);
    l1.push_back(40);

    cout << "第一个元素：" << l1.front() << endl;
    cout << "最后一个元素：" << l1.back() << endl;

    //验证迭代器是不支持随机访问的
    list<int>::iterator it = l1.begin();
    it++;  //可以，支持双向，支持一步步走
    it--;  //可以
//    it = it + 1;  //这个不行，不支持随机访问，因为如果支持，万一程序员是 it = it + 3，就跳着遍历了
}


int main() {
    test1();
}