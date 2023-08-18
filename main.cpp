#include <iostream>
#include "15.算法/1.LinkedList.hpp"

using namespace std;

int main() {
    LinkedList<int>* list = new LinkedList<int>();
    list->add(1);
    list->add(2);
    list->add(3);
    list->add(4);
    list->add(5);

    cout << list->size << endl;

    list->add(2, 10);
    cout << list->get(2) << endl;
    cout << list->get(3) << endl;
    cout << list->size << endl;

    cout <<"删除2位置："<<list->remove(2) << endl;
    cout << list->size << endl;

    cout <<"删除2位置："<<list->remove(2) << endl;
    cout << list->size << endl;

    delete(list) ;

    return 0;
}
