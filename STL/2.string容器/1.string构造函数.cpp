#include "iostream"
#include "string"

using namespace std;

/**
 * string()
 * string(const char * s)
 * string(const string& str)  拷贝构造
 * string(int n,char c)       n个字符c
 */
void test1() {
    //1.默认构造
    string s1;

    //2.
    const char *str = "hello world";
    string s2(str);

    //3
    string s3(s2);

    //4
    string(10, 'a');
}

int main() {

}