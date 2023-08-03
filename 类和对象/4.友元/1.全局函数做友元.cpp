#include "iostream"

using namespace std;

class Building {
    //goodGay全局函数是Building好朋友，可以访问Building私有成员
    friend void goodGay(Building &building);

public:
    Building() {
        m_SittingRoom = "客厅";
        m_BedRoom = "卧室";
    }

    string m_SittingRoom;
private:
    string m_BedRoom;
};

//全局函数
void goodGay(Building &building) {
    cout << "全局函数正在访问:" << building.m_SittingRoom << endl;
    cout << "全局函数正在访问:" << building.m_BedRoom << endl;
}

void test1() {
    Building building;
    goodGay(building);
}

int main() {
    test1();
}
