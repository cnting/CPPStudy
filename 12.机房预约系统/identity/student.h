#pragma once

#include "iostream"

using namespace std;

#include "identity.h"
#include "../computerRoom.h"
#include "vector"

//学生类
class Student : public Identity {
public:
    Student();

    Student(int id, string name, string pwd);

    virtual void operatorMenu();

    //申请预约
    void applyOrder();

    //查看自身预约
    void showMyOrder();

    //查看所有预约
    void showAllOrder();

    //取消预约
    void cancelOrder();

    int m_Id;

    vector<ComputerRoom> vComputerRooms;
};
