#include "iostream"

using namespace std;

class Student {
public:
    Student() {
        cout << "Student构造函数" << endl;
    }

    ~Student() {
        cout << "Student析构函数" << endl;
    }

    char *name;
    int age;

};

void test1() {
    cout << "创建stu1" << endl;
    //在栈上开辟内存
    Student stu1;

    cout << endl << "创建stu2" << endl;

    //malloc在堆上开辟内存，
    //malloc/free 不会调用构造函数和析构函数
    Student *stu2 = static_cast<Student *>(malloc(sizeof(Student)));
    free(stu2);

    cout << endl << "创建stu3" << endl;

    //new在堆上开辟内存
    //new/delete 会调用构造函数和析构函数
    Student *stu3 = new Student();
    delete stu3;
}

int main() {
    test1();
}
