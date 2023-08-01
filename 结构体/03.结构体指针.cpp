#include <iostream>
#include <string>
using namespace std;

struct Student
{
    string name;
    int age;
    int score;
};

struct Teacher
{
    int id;
    string name;
    int age;
    struct Student stu;
};

int main(int argc, char const *argv[])
{

    Teacher t = {1, "张老师", 35, {"张同学", 15, 100}};
    Teacher *p = &t;
    cout << p->name << "," << p->age << "," << p->stu.age;
    return 0;
}
