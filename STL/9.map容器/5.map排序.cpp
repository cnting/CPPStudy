#include "iostream"
#include "map"

using namespace std;

class MyCompare {
public:
    //这后面要加const，看这里https://blog.csdn.net/sunnysat/article/details/118664613
    bool operator()(int v1, int v2) const{
        return v1 > v2;
    }
};

void test1() {
    map<int, int, MyCompare> m;
    m.insert(make_pair(1, 10));
    m.insert(make_pair(2, 20));
    m.insert(make_pair(3, 30));
    m.insert(make_pair(4, 40));
    m.insert(make_pair(5, 50));

    for (map<int, int, MyCompare>::iterator it = m.begin(); it != m.end(); it++) {
        cout << it->first << " " << it->second << endl;
    }
    cout << endl;
}

int main() {
    test1();
};