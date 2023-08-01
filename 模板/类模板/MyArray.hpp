#pragma once

#include "iostream"

using namespace std;

template<class T>
class MyArray {
public:
    MyArray(int capacity) {
//        cout << "MyArray有参构造" << endl;
        this->m_Capacity = capacity;
        this->m_Size = 0;
        this->pAddress = new T[m_Capacity];
    }

    //拷贝构造，防止浅拷贝
    MyArray(const MyArray &arr) {
//        cout << "MyArray拷贝构造" << endl;
        this->m_Capacity = arr.m_Capacity;
        this->m_Size = arr.m_Size;
        //深拷贝
        this->pAddress = new T[arr.m_Capacity];
        for (int i = 0; i < this->m_Size; i++) {
            this->pAddress[i] = arr.pAddress[i];
        }
    }

    //防止浅拷贝问题
    MyArray &operator=(const MyArray &arr) {
//        cout << "MyArray operator=" << endl;
        //先判断原来堆区是否有数据，如果有先释放
        if (this->pAddress != NULL) {
            delete[] this->pAddress;
            this->pAddress = NULL;
            this->m_Capacity = 0;
            this->m_Size = 0;
        }

        //深拷贝
        this->m_Capacity = arr.m_Capacity;
        this->m_Size = arr.m_Size;
        //深拷贝
        this->pAddress = new T[arr.m_Capacity];
        for (int i = 0; i < this->m_Size; i++) {
            this->pAddress[i] = arr.pAddress[i];
        }

        return *this;
    }

    //尾插法
    void Push_Back(const T &item) {
        if (m_Size >= m_Capacity) {
            return;
        }
        pAddress[m_Size] = item;
        m_Size++;
    }

    //尾删法
    void Pop_Back() {
        if (m_Size == 0) {
            return;
        }
        m_Size--;
    }

    //通过下标方式访问数组中的元素，&是为了让返回值可以作为左值存在
    T &operator[](int index) {
        return pAddress[index];
    }

    int getCapacity() {
        return this->m_Capacity;
    }

    int getSize() {
        return this->m_Size;
    }

    //析构
    ~MyArray() {
        if (this->pAddress != NULL) {
//            cout << "MyArray析构" << endl;
            delete[] this->pAddress;
            this->pAddress = NULL;
        }
    }

private:
    T *pAddress;
    int m_Capacity;
    int m_Size;
};