#include <iostream>
#include <string>
using namespace std;

struct Student
{
    string name;
    int age;
    int score;
};
//将函数中形参改为指针，可以减少内存空间，而且不会复制新的副本出来
//但有个隐患，可以随意改传入参数的值，用const避免这种情况
void print2(const Student *t)
{
    cout << t->name << "," << t->age << "," << t->score << endl;
//    t->age = 200;  //会报错
}

int main()
{

    Student t = {"张同学", 15, 100};
    print2(&t);
    cout << t.name << "," << t.age << "," << t.score << endl;
    return 0;
}
