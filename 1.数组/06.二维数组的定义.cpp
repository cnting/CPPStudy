#include "iostream"

using namespace std;

/*
 * 定义方式：
 * 1. 数据类型 数组名[行数][列数];
 * 2. 数据类型 数组名[行数][列数] = {{数据1,数据2},{数据3，数据4}};
 * 3. 数据类型 数组名[行数][列数] = {数据1,数据2,数据3，数据4};
 * 4. 数据类型 数组名[][列数] = {数据1,数据2,数据3，数据4};
 */
int main() {
    int arr[2][3];
    arr[0][0] = 1;
    arr[0][1] = 2;
    arr[0][2] = 3;
    arr[1][0] = 4;
    arr[1][1] = 5;
    arr[1][2] = 6;

    int arr2[2][3] = {
            {1, 2, 3},
            {4, 5, 6}
    };
    int arr3[2][3] = {
            1, 2, 3, 4, 5, 6
    };
    int arr4[][3] = {1, 2, 3, 4, 5, 6};
}