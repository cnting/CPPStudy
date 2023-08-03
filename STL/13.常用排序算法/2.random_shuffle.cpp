#include "iostream"
#include "vector"
#include "algorithm"
#include "ctime"
using namespace std;

void print(int val) {
    cout << val << " ";
}

void test() {
    //按时间生成随机种子，但我试了没用
    srand((unsigned int)time(NULL));

    vector<int> v;
    for(int i = 0;i<10;i++){
        v.push_back(i);
    }
    random_shuffle(v.begin(), v.end());
    for_each(v.begin(), v.end(), print);
    cout << endl;
}

int main() {
    test();
}