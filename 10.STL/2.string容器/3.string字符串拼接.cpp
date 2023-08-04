#include "iostream"
#include "string"

using namespace std;

/**
 * string拼接函数原型
 * string& operator+=(const char* str);
 * string& operator+=(const char c);
 * string& operator+=(const string& str);
 * string& append(const char * s);
 * string& append(const char * s,int n);
 * string& append(const string& s);
 * string& append(const string& s,int pos,int n); //字符串s从pos开始n个字符连接到当前字符串末尾
 */
void test1() {
    string str1 = "我";
    str1 += "爱玩游戏";
    cout << "str1=" << str1 << endl;

    str1 += ":";
    cout << "str1=" << str1 << endl;

    string str2 = "LOL DNF";
    str1 += str2;
    cout << "str1=" << str1 << endl;

    string str3 = "I";
    str3.append(" love ");
    cout << "str3=" << str3 << endl;

    str3.append("game aaaa",4);
    cout << "str3=" << str3 << endl;

    str3.append(str2);
    cout << "str3=" << str3 << endl;

    str3.append(str2,0,3);
    cout << "str3=" << str3 << endl;
}

int main() {
    test1();
}