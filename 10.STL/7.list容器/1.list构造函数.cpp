#include "iostream"
#include "list"

using namespace std;

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
    print(l1);

    list<int> l2(l2.begin(), l2.end());

    list<int> l3(l2);

    list<int> l4(10, 1000);

}

int main() {

}