#include <iostream>

using namespace std;

void test1(){
    //bool类型0表示false，非0表示true，所以传入-100也为true
    bool flag = -100;
    std::cout << flag << std::endl;
    if (flag) {
        cout << "为true" << endl;
    }else{
        cout << "为false" << endl;
    }
}

int main() {
    test1();
    return 0;
}