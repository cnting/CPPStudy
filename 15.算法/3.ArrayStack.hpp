#include <cstdio>
#include <cstdlib>
#include <cassert>

/**
 * 用数组实现栈
 */
template<class E>
class ArrayStack {
public:
    void push(E e);

    E pop();

    E peek();

    int size();

    bool isEmpty();

    ~ArrayStack();

private:
    //栈顶元素位置
    int elementCount = 0;
    E *array = NULL;
    int capacity = 0;

    void ensureCapacityInternal(int minCapacity);

    void grow(int minCapacity);

    void removeElementAt(int index);
};

template<class E>
int ArrayStack<E>::size() {
    return elementCount;
}

template<class E>
void ArrayStack<E>::push(E e) {
    ensureCapacityInternal(elementCount + 1);
    array[elementCount] = e;
    elementCount++;
}

template<class E>
E ArrayStack<E>::peek() {
    int s = size();
    assert(s > 0);
    return array[s - 1];
}

template<class E>
E ArrayStack<E>::pop() {
    E e = peek();
    removeElementAt(elementCount - 1);
    return e;
}

template<class E>
bool ArrayStack<E>::isEmpty() {
    return elementCount == 0;
}

template<class E>
void ArrayStack<E>::ensureCapacityInternal(int minCapacity) {
    if (this->array == NULL) {
        minCapacity = 10;
    }
    if (capacity < minCapacity) {
        grow(minCapacity);
    }
}

template<class E>
void ArrayStack<E>::grow(int minCapacity) {
    int new_len = capacity + (capacity >> 1);
    if (minCapacity > new_len) {
        new_len = minCapacity;
    }
    E *new_arr = (E *) malloc(sizeof(E) * new_len);
    if (this->array) {
        //最后一个参数是要拷贝的字节数
        memcpy(new_arr, array, sizeof(E) * elementCount);
        free(array);
    }
    this->array = new_arr;
    this->capacity = new_len;
}

template<class E>
void ArrayStack<E>::removeElementAt(int index) {
    assert(index >= 0 && index < elementCount);
    int numMoved = elementCount - index - 1;
    for (int i = 0; i < numMoved; i++) {
        array[index + 1] = array[index + i + 1];
    }
    this->elementCount -= 1;
    array[elementCount] = NULL;
}

template<class E>
ArrayStack<E>::~ArrayStack() {
    if (array) {
        free(array);
        array = NULL;
    }
}

