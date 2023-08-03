#include "iostream"
#include "vector"
#include "map"

#define CEHUA 0
#define MEISHU 1
#define YANFA 2

using namespace std;

class Worker {
public:
    string m_Name;
    int m_Salary;
};

void createWorker(vector<Worker> &workers) {
    string nameSeed = "ABCDEFGHIJ";
    for (int i = 0; i < 10; i++) {
        Worker worker;
        worker.m_Name = "员工";
        worker.m_Name += nameSeed[i];
        worker.m_Salary = rand() % 10000 + 10000;
        workers.push_back(worker);
    }
}

void setGroup(vector<Worker> &v, multimap<int, Worker> &m) {
    for (auto it = v.begin(); it != v.end(); it++) {
        int deptId = rand() % 3;  //产生0~2的随机数
        m.insert(make_pair(deptId, *it));
    }
}

void showWorkerByGroup(multimap<int, Worker> &m) {
    cout << "策划部分:" << endl;
    multimap<int, Worker>::iterator pos = m.find(CEHUA);
    int num = m.count(CEHUA);
    int index = 0;
    for (; pos != m.end() && index < num; pos++, index++) {
        cout << "姓名：" << pos->second.m_Name << ",工资:" << pos->second.m_Salary << endl;
    }

    cout << "美术:" << endl;
    pos = m.find(MEISHU);
    num = m.count(MEISHU);
    index = 0;
    for (; pos != m.end() && index < num; pos++, index++) {
        cout << "姓名：" << pos->second.m_Name << ",工资:" << pos->second.m_Salary << endl;
    }

    cout << "研发:" << endl;
    pos = m.find(YANFA);
    num = m.count(YANFA);
    index = 0;
    for (; pos != m.end() && index < num; pos++, index++) {
        cout << "姓名：" << pos->second.m_Name << ",工资:" << pos->second.m_Salary << endl;
    }
}

int main() {
    vector<Worker> workers;
    //创建员工
    createWorker(workers);

    //插入到不同部门
    multimap<int, Worker> m;
    setGroup(workers, m);

    //分组显示员工
    showWorkerByGroup(m);

}
