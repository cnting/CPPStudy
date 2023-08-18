
template<class E>
class ArrayQueue {
public:
    ArrayQueue();

    ArrayQueue(int size);

    ~ArrayQueue();

    bool isEmpty();

    E pop();

    void push(E e);

    E peek();

    int size();

private:
    int arraySize = 0;  //数组的大小
    //头索引
    int head = 0;
    //尾索引
    int tail = 0;
    E *array;

    void growArray();

    void copyElement(int *src, int srcStart, int *dest, int destStart, int len);
};

template<class E>
ArrayQueue<E>::ArrayQueue() :ArrayQueue(4) {

}

template<class E>
ArrayQueue<E>::ArrayQueue(int size) {
    //要变成2的幂次
    int init_size = 4;
    if (size >= 4) {
        init_size = size;
        init_size |= init_size >> 1;
        init_size |= init_size >> 2;
        init_size |= init_size >> 4;
        init_size |= init_size >> 8;
        init_size |= init_size >> 16;
        init_size++;
    }
    arraySize = init_size;
    array = (E *) malloc(sizeof(E) * arraySize);
}

template<class E>
ArrayQueue<E>::~ArrayQueue() {
    delete[] array;
}

template<class E>
bool ArrayQueue<E>::isEmpty() {
    return tail == head;
}


/**
 * size = 2^n，二进制表示为：第n位为1，低位全为0
 * size-1=2^n-1，二进制表示为：第n位为0，低位全为1
 * 如果head>0，位与后低位保持不变，高位为0，结果为head-1
 * 如果head=0，head-1=-1，转换二进制11111111，位与后，结果为size-1
 */
template<class E>
void ArrayQueue<E>::push(E e) {
    head = (head - 1) & (arraySize - 1);
    array[head] = e;

    cout << "push  head:" << head << ",tail:" << tail << endl;

    if (tail == head) {
        //扩容
        growArray();
    }
}

template<class E>
E ArrayQueue<E>::peek() {
    return array[(tail - 1) & (arraySize - 1)];
}

template<class E>
E ArrayQueue<E>::pop() {
    tail = (tail - 1) & (arraySize - 1);
    cout << "pop  head:" << head << ",tail:" << tail << endl;

    return array[tail];
}

template<class E>
int ArrayQueue<E>::size() {
    return (tail - head) & (arraySize - 1);
}

template<class E>
void ArrayQueue<E>::growArray() {
    int new_size = arraySize << 1;
    E *new_array = (E *) malloc(sizeof(E) * new_size);
    int r = arraySize - tail;
    copyElement(array, tail, new_array, 0, r);
    copyElement(array, 0, new_array, r, tail);

    free(array);
    array = new_array;
    head = 0;
    tail = arraySize;
    arraySize = new_size;
}

template<class E>
void ArrayQueue<E>::copyElement(int *src, int srcStart, int *dest, int destStart, int len) {
    for (int i = 0; i < len; i++) {
        dest[destStart + i] = src[srcStart + i];
    }

}
