#include "iostream"
#include "queue"

using namespace std;

class Person {
public:
    Person(string name, int age) {
        this->m_Name = name;
        this->m_Age = age;
    }

    string m_Name;
    int m_Age;
};

void test() {
    queue<Person> q;
    q.push(Person("1", 1));
    q.push(Person("2", 2));
    q.push(Person("3", 3));
    q.push(Person("4", 4));

    while (!q.empty()) {
        cout << "队头：" << q.front().m_Name << endl;
        cout << "队尾：" << q.back().m_Name << endl;
        q.pop();
    }
}

/**
 * 优先级队列
 */
void test2() {
    priority_queue<int, vector<int>, greater<int>> q;
    q.push(12);
    q.push(44);
    q.push(33);
    q.push(10);
    q.push(50);
    cout << q.top() << endl;
}

int main() {
//    test();
    test2();
}