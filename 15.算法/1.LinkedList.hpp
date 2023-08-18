#include "iostream"
#include "string"

using namespace std;

template<class E>
struct Node {
    Node<E> *next;
    Node<E> *pre;
    E value;

public:
    Node(Node<E> *pre, E value, Node<E> *next) {
        this->pre = pre;
        this->value = value;
        this->next = next;
    }
};

template<class E>
class LinkedList {
public:
    Node<E> *head;
    Node<E> *tail;
    int size = 0;

    void add(E e);

    E get(int index);

    void add(int index, E e);

    E remove(int index);

    ~LinkedList();

private:

    void checkElementIndex(int index);

    void checkPositionIndex(int index);

    Node<E> *node(int index);

    void linkLast(E e);

    void linkBefore(E e, Node<E> *succ);

    E unlink(Node<E> *node);
};

template<class E>
void LinkedList<E>::add(E e) {
    linkLast(e);
}

template<class E>
void LinkedList<E>::add(int index, E e) {
    checkPositionIndex(index);
    if (index == size) {
        linkLast(e);
    } else {
        linkBefore(e, node(index));
    }
}

template<class E>
E LinkedList<E>::get(int index) {
    checkElementIndex(index);
    return node(index)->value;
}

template<class E>
Node<E> *LinkedList<E>::node(int index) {
    if (index < size >> 1) {
        Node<E> *x = head;
        for (int i = 0; i < index; i++) {
            x = x->next;
        }
        return x;
    } else {
        Node<E> *x = tail;
        for (int i = size - 1; i > index; i--) {
            x = x->pre;
        }
        return x;
    }
}

template<class E>
void LinkedList<E>::checkElementIndex(int index) {
    assert(index >= 0 && index < size);
}

template<class E>
void LinkedList<E>::checkPositionIndex(int index) {
    assert(index >= 0 && index <= size);
}


template<class E>
LinkedList<E>::~LinkedList() {
    Node<E> *node = head;
    while (node) {
        Node<E> *next = node->next;
        delete node;
        node = next;
    }
    head = NULL;
    tail = NULL;
}

template<class E>
void LinkedList<E>::linkLast(E e) {
    Node<E> *l = tail;
    Node<E> *new_node = new Node<E>(l, e, NULL);
    tail = new_node;
    if (head) {
        l->next = new_node;
    } else {
        head = new_node;
    }
    size++;
}

template<class E>
void LinkedList<E>::linkBefore(E e, Node<E> *succ) {
    Node<E> *pred = succ->pre;
    Node<E> *newNode = new Node<E>(pred, e, succ);
    succ->pre = newNode;
    if (pred) {
        pred->next = newNode;
    } else {
        head = newNode;
    }
    size++;
}

template<class E>
E LinkedList<E>::remove(int index) {
    checkElementIndex(index);
    return unlink(node(index));
}

template<class E>
E LinkedList<E>::unlink(Node<E> *node) {
    E element = node->value;
    Node<E> *pre = node->pre;
    Node<E> *next = node->next;
    if (pre) {
        pre->next = next;
        node->pre = NULL;
    } else {
        head = next;
    }
    if (next) {
        next->pre = pre;
        node->next = NULL;
    } else {
        tail = pre;
    }
    node->value = NULL;
    delete node;  //记得释放
    size--;
    return element;
}
