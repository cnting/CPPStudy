#include <iostream>
#include <string>
using namespace std;

struct Student
{
    string name;
    int age;
    int score;
};

int main(int argc, char const *argv[])
{

    Student arr[3] = {
        {"张三", 12, 11},
        {"李四", 12, 11},
        {"王五", 12, 11},
    };

    arr[2].name = "赵六";

    for(int i = 0;i<3;i++){
        cout << arr[i].name << endl;
    }
    return 0;
}
