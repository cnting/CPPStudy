#include "iostream"
#include "vector"
#include "deque"
#include "algorithm"
#include "ctime"

using namespace std;

class Person {
public:
    Person(string name, int score) {
        this->m_Name = name;
        this->m_Score = score;
    }

    string m_Name;
    int m_Score;
};

void createPerson(vector<Person> &v) {
    string nameSeed = "ABCDE";
    for (int i = 0; i < 5; i++) {
        string name = "选手";
        name += nameSeed[i];
        int score = 0;
        Person p(name, score);
        v.push_back(p);
    }
}

void setScore(vector<Person> &v) {
    for (auto it = v.begin(); it != v.end(); it++) {
        deque<int> d;
        for (int i = 0; i < 10; i++) {
            int score = rand() % 41 + 60;
            d.push_back(score);
        }
        std::sort(d.begin(), d.end());
        d.pop_back();
        d.pop_front();

        int sum = 0;
        for (auto dit = d.begin(); dit != d.end(); dit++) {
            sum += *dit;
        }
        it->m_Score = sum / d.size();
    }
}

void showScore(vector<Person> &v) {
    for (auto it = v.begin(); it != v.end(); it++) {
        cout << "姓名：" << it->m_Name << ",分数:" << it->m_Score << endl;
    }
}

int main() {
    //随机数种子
    srand((unsigned int) time(NULL));
    vector<Person> v;
    createPerson(v);
    setScore(v);
    showScore(v);
}