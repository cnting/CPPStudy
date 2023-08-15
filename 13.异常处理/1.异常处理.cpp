#include "iostream"

using namespace std;

/**
 *C++中的异常，Java层是没法try catch住的，只能C++中解决
 *
* C++中有一套异常体系，可以抛任何数据类型
* try{}catch(数据类型 变量名){}
*/

class Exception {
public:
    Exception(string msg) {
        this->msg = msg;
    }

    const char *what() {
        return this->msg.c_str();
    }

    string msg;
};

void test1() {
    try {
        int i = 0;
        if (i == 0) {
//            throw i;  //可以抛int类型
            throw Exception("出错啦");
        }
    }catch (int number) {
        cout << "捕捉到异常:" << number << endl;
    }catch (Exception exception) {
        cout << "捕捉到异常:" << exception.what() << endl;
    }catch (...) {  //捕捉任意类型
        cout << "捕捉到其他异常" << endl;
    }
}


int main() {
    test1();
}