#include <iostream>
#include <string>
using namespace std;

struct Student
{
    string name;
    int age;
    int score;
};
//值传递
void print1(Student t)
{
    cout << t.name << "," << t.age << "," << t.score << endl;
    t.age = 100;
}
//地址传递
void print2(Student *t)
{
    cout << t->name << "," << t->age << "," << t->score << endl;
    t->age = 200;
}

int main(int argc, char const *argv[])
{

    Student t = {"张同学", 15, 100};
    print1(t);
    print2(&t);
    cout << t.name << "," << t.age << "," << t.score << endl;
    return 0;
}
