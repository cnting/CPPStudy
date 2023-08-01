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
    // 初始化方式1
    Student s1;
    s1.name = "张三";
    s1.age = 18;
    s1.score = 100;

    // 初始化方式2
    struct Student s2 = {"李四", 19, 99};

    return 0;
}
