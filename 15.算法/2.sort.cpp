#include "iostream"

using namespace std;

void bubbleSort(int *arr, int len) {
    for (int i = 0; i < len; i++) {
        bool hasChange = false;
        for (int j = 0; j < len - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                hasChange = true;
            }
        }
        if (!hasChange) break;
    }
}


void selectSort(int *arr, int len) {
    for (int i = 0; i < len; i++) {
        int minPos = i;
        for (int j = i + 1; j < len; j++) {
            if (arr[minPos] > arr[j]) {
                minPos = j;
            }
        }
        if (i != minPos) {
            swap(arr[i], arr[minPos]);
        }
    }
}

void insertSort(int *arr, int len) {
    for (int i = 1; i < len; i++) {
        int value = arr[i];
        int j = i - 1;
        for (; j >= 0; j--) {
            if (arr[j] > value) {
                arr[j + 1] = arr[j];
            } else {
                break;
            }
        }
        arr[j + 1] = value;
    }
}

void merge(int *arr, int start, int mid, int end) {
    int tempArr[end - start + 1];
    int i = start;
    int j = mid + 1;
    int k = 0;
    while (i <= mid && j <= end) {
        if (arr[i] < arr[j]) {
            tempArr[k++] = arr[i++];
        } else {
            tempArr[k++] = arr[j++];
        }
    }
    if (i <= mid) {
        j = i;
        end = mid;
    }
    while (j <= end) {
        tempArr[k++] = arr[j++];
    }
    for (i = 0; i < k; i++) {
        arr[start + i] = tempArr[i];
    }
}

void mergeSort(int *arr, int start, int end) {
    if (start >= end) return;
    int mid = (start + end) / 2;
    mergeSort(arr, start, mid);
    mergeSort(arr, mid + 1, end);
    merge(arr, start, mid, end);
}

void mergeSort(int *arr, int len) {
    mergeSort(arr, 0, len - 1);
}

pair<int, int> partition(int *arr, int start, int end) {
    //小于区域的右边界
    int less = start - 1;
    //大于区域的左边界
    int more = end;
    while (start < more) {
        if (arr[start] < arr[end]) {
            swap(arr[++less], arr[start++]);
        } else if (arr[start] > arr[end]) {
            swap(arr[--more], arr[start]);
        } else {
            start++;
        }
    }
    //more是大于区域的左边界，交换后就变成等于区域的右边界
    swap(arr[more], arr[end]);
    //返回等于区域的左右边界
    return make_pair(less + 1, more);
}

void quickSort(int *arr, int start, int end) {
    if (start >= end) return;
    srand(std::time(nullptr));
    int random = start + rand() % (end - start + 1);
    swap(arr[end], arr[random]);

    pair<int, int> q = partition(arr, start, end);

    quickSort(arr, start, q.first - 1);
    quickSort(arr, q.second + 1, end);
}

void quickSort(int *arr, int len) {
    quickSort(arr, 0, len - 1);
}


void adjustHeap(int *array, int k, int n) {
    while (k * 2 + 1 < n) {
        int max = 2 * k + 1;
        if (max + 1 < n && array[max + 1] > array[max]) {
            max = max + 1;
        }
        if (array[k] > array[max]) {
            break;
        }
        swap(array[k], array[max]);
        k = max;
    }
}

/**
 * 堆排序
 */
void heapSort(int *arr, int len) {
    for (int i = len / 2 - 1; i >= 0; i--) {
        adjustHeap(arr, i, len);
    }
    for (int i = len - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        adjustHeap(arr, 0, i);
    }
}
