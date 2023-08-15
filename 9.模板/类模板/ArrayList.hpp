//
// Created by cnting on 2023/8/13.
//

#include <cstdlib>

#ifndef CPPSTUDY_ARRAYLIST_HPP
#define CPPSTUDY_ARRAYLIST_HPP

template<class E>
class ArrayList {
private:
    E *array;
    int m_Capacity;
    int m_Size;
public:
    ArrayList();

    ArrayList(int len);

    ArrayList(const ArrayList &p);

    void add(E e);

    E remove(int index);

    E get(int index);

    int size();

    ~ArrayList();

private:
    void ensureCapacityInternal(int capacity);

    void grow(int capacity);
};


#endif //CPPSTUDY_ARRAYLIST_HPP

template<class E>
ArrayList<E>::ArrayList() {

}

template<class E>
ArrayList<E>::ArrayList(int len) {
    if (len < 0) {
        return;
    }
    this->m_Capacity = len;
    this->array = (E *) malloc(sizeof(E) * len);
}

template<class E>
ArrayList<E>::ArrayList(const ArrayList<E> &p) {
    if (this->array) {
        free(array);
        array = NULL;
    }
    this->m_Capacity = p.m_Capacity;
    this->m_Size = p.m_Size;
    this->array = (E *) malloc(sizeof(E) * m_Capacity);
    memcpy(array, p.array, sizeof(E) * m_Capacity);
}

template<class E>
ArrayList<E>::~ArrayList() {
    if (array) {
        free(array);
        this->array = NULL;
    }
}

template<class E>
void ArrayList<E>::grow(int capacity) {
    int new_len = m_Capacity + (m_Capacity >> 1);
    if (capacity > new_len) {
        new_len = capacity;
    }
    E *new_arr = (E *) malloc(sizeof(E) * new_len);
    if (this->array) {
        //最后一个参数是要拷贝的字节数
        memcpy(new_arr, array, sizeof(E) * m_Size);
        free(array);
    }
    this->array = new_arr;
    this->m_Capacity = new_len;
    cout << "grow():" << new_len << endl;
}

template<class E>
void ArrayList<E>::ensureCapacityInternal(int capacity) {
    if (this->array == NULL) {
        capacity = 10;
    }
    if (capacity - m_Capacity > 0) {
        grow(capacity);
    }
}

template<class E>
void ArrayList<E>::add(E e) {
    ensureCapacityInternal(m_Size + 1);
    this->array[m_Size++] = e;
}

template<class E>
E ArrayList<E>::remove(int index) {
    E oldValue = get(index);
    int numMoved = this->m_Size - index - 1;
    for (int i = 0; i < numMoved; i++) {
        array[index + 1] = array[index + i + 1];
    }
    this->m_Size -= 1;
    return oldValue;
}

template<class E>
E ArrayList<E>::get(int index) {
    return array[index];
}

template<class E>
int ArrayList<E>::size() {
    return m_Size;
}