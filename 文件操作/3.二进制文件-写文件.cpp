#include <ostream>
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
    ofstream ofs;
    ofs.open("person.txt", ios::out | ios::binary);

    Person p = {"张三", 18};
    ofs.write((const char *)&p, sizeof(Person));

    ofs.close();
}

int main(int argc, char const *argv[])
{
    test1();
    return 0;
}
