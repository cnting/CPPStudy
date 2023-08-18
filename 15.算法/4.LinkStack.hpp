#include <cstdio>
#include <cassert>

//template<class E>
//class Node {
//    Node *next;
//    Node *pre;
//    E value;
//public:
//    Node(Node *pre, E value, Node<E> *next) {
//        this->pre = pre;
//        this->value = value;
//        this->next = next;
//    }
//};

template<class E>
class LinkStack {
public:
    void push(E e);

    E pop();

    E peek();

    int size();

    bool isEmpty();

    ~LinkStack();

private:
    int elementCount = 0;
    Node<E> *head;
    Node<E> *top;
};

template<class E>
void LinkStack<E>::push(E e) {
    Node<E> *t = top;
    Node<E> *new_node = new Node<E>(t, e, NULL);
    top = new_node;
    if (head) {
        t->next = new_node;
    } else {
        head = new_node;
    }
    elementCount++;
}

template<class E>
E LinkStack<E>::pop() {
    assert(elementCount > 0);
    E value = top->value;
    Node<E> *t = top->pre;
    delete top;
    top = t;
    elementCount--;
    if (elementCount == 0) {
        head = NULL;
    }
    return value;
}

template<class E>
E LinkStack<E>::peek() {
    assert(elementCount > 0);
    return top->value;
}

template<class E>
int LinkStack<E>::size() {
    return elementCount;
}

template<class E>
bool LinkStack<E>::isEmpty() {
    return elementCount == 0;
}

template<class E>
LinkStack<E>::~LinkStack() {
    Node<E> *node = head;
    while (node) {
        Node<E> *next = node->next;
        delete node;
        node = next;
    }
    head = NULL;
    top = NULL;
}
