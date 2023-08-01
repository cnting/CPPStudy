#include <iostream>
using namespace std;
#include <fstream>
#include <string>

class Person
{
public:
    // 写文件时字符串最好不要用string，而是用C风格的数组
    char m_Name[64];
    int m_Age;
};

void test1()
{
    ifstream ifs;
    ifs.open("person.txt", ios::in | ios::binary);
    if (!ifs.is_open())
    {
        cout << "打开失败" << endl;
        return;
    }

    Person p;
    ifs.read((char *)&p, sizeof(Person));

    cout << p.m_Name << " " << p.m_Age << endl;
    ifs.close();
}

int main(int argc, char const *argv[])
{
    test1();
    return 0;
}
