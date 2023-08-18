#include <iostream>
#include "1.LinkedList.hpp"
#include "2.sort.cpp"
#include "3.ArrayStack.hpp"
#include "4.LinkStack.hpp"
#include "5.汉诺塔.cpp"
#include "6.ArrayQueue.hpp"
#include "7.BST.hpp"
#include "8.PriorityQueue.hpp"
#include "ArrayUtil.cpp"
#include "stack"

using namespace std;

/**
 * 手写LinkedList
 */
void test1() {
    LinkedList<int> *list = new LinkedList<int>();
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

    cout << "删除2位置：" << list->remove(2) << endl;
    cout << list->size << endl;

    cout << "删除2位置：" << list->remove(2) << endl;
    cout << list->size << endl;

    delete (list);
}

/**
 * 排序
 */
void test2() {
    int len = 10000;
    int *arr = ArrayUtil::create_random_array(len, 0, 100);
    int *arr1 = ArrayUtil::copy_random_array(arr, len);
    int *arr2 = ArrayUtil::copy_random_array(arr, len);
    int *arr3 = ArrayUtil::copy_random_array(arr, len);
    int *arr4 = ArrayUtil::copy_random_array(arr, len);
    int *arr5 = ArrayUtil::copy_random_array(arr, len);
    ArrayUtil::sort_array("bubbleSort", bubbleSort, arr, len);
    ArrayUtil::sort_array("selectSort", selectSort, arr1, len);
    ArrayUtil::sort_array("insertSort", insertSort, arr2, len);
    ArrayUtil::sort_array("mergeSort", mergeSort, arr3, len);
    ArrayUtil::sort_array("quickSort", quickSort, arr4, len);
    ArrayUtil::sort_array("heapSort", heapSort, arr5, len);


    delete[] arr;
    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
    delete[] arr4;
    delete[] arr5;
}

/**
 * 数组实现栈
 */
void test3() {
    ArrayStack<int> stack;
    stack.push(10);
    stack.push(9);
    stack.push(8);
    stack.push(7);

    cout << "stack size:" << stack.size() << endl;
    while (!stack.isEmpty()) {
        cout << stack.pop() << endl;
    }
    cout << "stack size:" << stack.size() << endl;
}

/**
 * 链表实现栈
 */
void test4() {
    LinkStack<int> stack;
    stack.push(10);
    stack.push(9);
    stack.push(8);
    stack.push(7);
    cout << "stack size:" << stack.size() << endl;

    cout << "peek:" << stack.peek() << endl;

    while (!stack.isEmpty()) {
        cout << stack.pop() << endl;
    }
    cout << "stack size:" << stack.size() << endl;
}

/**
 * 汉诺塔
 */
void test5() {
    hannuota(3, 'A', 'B', 'C');
}

void test6() {
    int number = 0x0001 & 1234567;
    //&的话要转成二进制
    //0x0001是十六进制 -> 0000 0000 0000 0001，前面都是0了，所以只用看最后一位
    //1234567是十进制 转二进制 最后一位肯定是1
    //所以得到答案是1
    cout << number << endl;
}

/**
 * 十进制转二进制
 */
void test7() {
    int number = 17;
    stack<int> s;
    while (number > 0) {
        s.push(number % 2);
        number /= 2;
    }
    while (!s.empty()) {
        cout << s.top();
        s.pop();
    }
    cout << endl;

    //负数转二进制
    //1.先取整数转二进制 0000 0101
    //2.再取反         1111 1010
    //3.再加1          1111 1011
    number = -5;

}

/**
 * 数组实现队列
 */
void test8() {
    ArrayQueue<int> q(2);
//    for (int i = 0; i < 5; i++) {
//        q.push(i);
//    }
//    while (!q.isEmpty()) {
//        cout << q.pop() << " ";
//    }

    q.push(1);
    q.push(2);
    q.push(3);
    q.pop();
    q.pop();
    q.push(4);
    q.push(5);
    q.push(6);
    q.push(7);
}

/**
 * 优先级队列（堆）
 */
void test9() {
    int n = 10;
    PriorityQueue<int> q(n);
    for (int i = 0; i < n; i++) {
        q.push(rand() % 100);
    }
    cout << "==========" << endl;
    while (!q.isEmpty()) {
        cout << q.pop() << endl;
    }
}

void visit(int key, int value) {
    cout << "key:" << key << ",value:" << value << endl;
}

void test10() {
    BST<int, int> *bst = new BST<int, int>();
    bst->put(2, 2);
    bst->put(-11, -11);
    bst->put(-13, -13);
    bst->put(0, 0);
    bst->put(8, 8);
    bst->put(3, 3);
    bst->put(7, 7);
    bst->inOrderTraverse(visit);

    cout << endl;
    cout << "contains(100):" << bst->contains(100) << endl;
    cout << "contains(7):" << bst->contains(7) << endl;
    cout << endl;

    int del = 7;
    cout << "删除" << del << ":" << endl;
    bst->remove(del);
    bst->inOrderTraverse(visit);

    cout << endl;
    cout << bst->get(8) << endl;

}

int main() {
    test10();

    return 0;
}