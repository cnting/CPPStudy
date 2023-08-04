#pragma once

#include "iostream"

using namespace std;

#include "identity.h"

class Teacher : public Identity {
public:
    Teacher();

    Teacher(int id, string name, string pwd);

    virtual void operatorMenu();

    //查看所有学生预约
    void showAllOrder();

    //审核预约
    void validOrder();

    //职工号
    int m_EmpId;

};
