#pragma once

#include "iostream"

using namespace std;

#include "identity.h"
#include "teacher.h"
#include "student.h"
#include "vector"
#include "../computerRoom.h"

//管理员
class Manager : public Identity {
public:
    Manager();

    Manager(string name, string pwd);

    virtual void operatorMenu();

    //添加账号
    void addPerson();

    //查看账号
    void showPerson();

    //查看机房信息
    void showComputer();

    //清空所有预约记录
    void clearFile();

    //初始化容器
    void initVector();

    //添加账号去重
    bool checkRepeat(int id, int type);

    vector<Student> vStudents;
    vector<Teacher> vTeachers;

    vector<ComputerRoom> vComputerRooms;
};
