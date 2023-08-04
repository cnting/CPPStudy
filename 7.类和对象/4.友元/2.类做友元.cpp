#include "iostream"

using namespace std;

class Building;

class GoodGay {
public:
    GoodGay();

    void visit();

    Building *building;
};

class Building {
    //GoodGay类是本类好朋友，可以访问本类私有成员
    friend class GoodGay;

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
    cout << building->m_SittingRoom << endl;
    cout << building->m_BedRoom << endl;
}

void test1() {
    GoodGay goodGay;
    goodGay.visit();
}

int main() {
    test1();
}
