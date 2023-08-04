#include <iostream>

using namespace std;

//#include "person.h"  //这样引用会报错

//第一种解决方式，直接包含源文件（不常用）
//#include "person.cpp"

//第二种解决方式，将.h和.cpp中的内容写到一起，将后缀改成.hpp文件（推荐）
#include "person.hpp"

void test1() {
    Person<string, int> p("Tom", 20);
    p.showPerson();
}

int main(int argc, char const *argv[]) {
    test1();
    return 0;
}
