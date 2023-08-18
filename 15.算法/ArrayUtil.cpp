#include "stdlib.h"

namespace ArrayUtil {
    int *create_random_array(int length, int low, int high) {
        int *arr = new int[length];
        for (int i = 0; i < length; i++) {
            arr[i] = rand() % (high - low) + low;
        }
        return arr;
    }

    void print_array(int *arr, int len) {
        for (int i = 0; i < len; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void sort_array(char *sortName, void (*sort)(int *, int), int *arr, int len) {
        size_t start_time = clock();
        sort(arr, len);
        size_t end_time = clock();
        double time = double(end_time - start_time) / CLOCKS_PER_SEC;
        cout << sortName << "的执行时间：" << time << endl;

        //检测排序是否正确
        for (int i = 0; i < len - 1; i++) {
            assert(arr[i] <= arr[i + 1]);
        }
    }

    int *copy_random_array(int *arr, int len) {
        int *copy_arr = new int[len];
        memcpy(copy_arr, arr, sizeof(int) * len);
        return copy_arr;
    }

}
