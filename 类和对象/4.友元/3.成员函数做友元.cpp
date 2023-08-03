#include "iostream"

using namespace std;

class Building;

class GoodGay {
public:
    GoodGay();

    //可以访问Building中私有成员
    void visit();

    //不可以访问Building中私有成员
    void visit2();

    Building *building;
};

class Building {
    friend void GoodGay::visit();

public:
    Building();

    string m_SittingRoom;
private:
    string m_BedRoom;
};

//类外写成员函数
Building::Building() {
    m_SittingRoom = "客厅";
    m_BedRoom = "卧室";
}

GoodGay::GoodGay() {
    building = new Building();
}

void GoodGay::visit() {
    cout << "visit() 访问" << building->m_SittingRoom << endl;
    cout << "visit() 访问" << building->m_BedRoom << endl;
}

void GoodGay::visit2() {
    cout << "visit2() 访问" << building->m_SittingRoom << endl;
    //报错
//    cout << "visit2() 访问" << building->m_BedRoom << endl;
}

void test1() {
    GoodGay goodGay;
    goodGay.visit();
    goodGay.visit2();
}

int main() {
    test1();
}
