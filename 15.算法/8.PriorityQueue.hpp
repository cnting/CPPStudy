#include <cstdio>
#include "iostream"

using namespace std;

template<class T>
class PriorityQueue {
private:
    int count;
    int index = 0;
    T *array = NULL;

    void shiftUp(int k) {
        if (k > 1 && array[k] > array[k / 2]) {
            swap(array[k], array[k / 2]);
            shiftUp(k / 2);
        }
    }

    void shiftDown(int k) {
        while (k * 2 <= index) {
            int max = 2 * k;
            if (max + 1 <= index && array[max + 1] > array[max]) {
                max = max + 1;
            }
            if (array[k] >= array[max]) {
                break;
            }
            swap(array[k], array[max]);
            k = max;
        }
    }

public:
    PriorityQueue(int count) {
        this->count = count;
        array = new T[count];
    }

    bool isEmpty() {
        return index == 0;
    }


    T pop() {
        if (isEmpty()) return NULL;
        T max = array[1];
        swap(array[1], array[index]);
        index--;
        shiftDown(1);
        return max;
    }

    void push(T e) {
        array[index + 1] = e;
        index++;
        shiftUp(index);

        for (int i = 1; i <= index; i++) {
            cout << array[i] << " ";
        }
        cout << endl;
    }
};
