#include "iostream"

using namespace std;

//区别：
//struct默认权限是public
//class默认权限是private

class C1 {
    //默认是private
    int m_A;
};

struct C2 {
    //默认是public
    int m_A;
};

int main() {
    C1 c1;
//    c1.m_A = 100;  //报错

    C2 c2;
    c2.m_A = 100;  //可以访问

}