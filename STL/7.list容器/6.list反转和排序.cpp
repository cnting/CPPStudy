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
    l1.push_back(20);
    l1.push_back(10);
    l1.push_back(50);
    l1.push_back(40);
    l1.push_back(30);
    print(l1);

    l1.reverse();
    print(l1);

    //所有不支持随机访问迭代器的容器，不可以用标准算法sort
    //不支持随机访问迭代器的容器，内部会提供对应的一些算法
//    sort(l1.begin(), l1.end()); //报错
    l1.sort();
    print(l1);

}


int main() {
    test1();
}