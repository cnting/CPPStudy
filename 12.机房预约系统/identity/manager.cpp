//
// Created by cnting on 2023/8/4.
//

#include "manager.h"
#include "fstream"
#include "../globalFile.h"
#include "../system_util.h"

Manager::Manager() {}

Manager::Manager(string name, string pwd) {
    this->m_Name = name;
    this->m_Password = pwd;
    //获取所有老师、学生信息
    initVector();

    //初始化机房信息
    ifstream ifs;
    ifs.open(COMPUTER_FILE, ios::in);
    ComputerRoom room;
    while (ifs >> room.m_ComId && ifs >> room.m_MaxNum) {
        vComputerRooms.push_back(room);
    }
    ifs.close();
}

void Manager::operatorMenu() {
    cout << "欢迎管理员" << m_Name << "登录！" << endl;
    cout << "\t\t--------------------" << endl;
    cout << "\t\t|      1.添加账号    |" << endl;
    cout << "\t\t|      2.查看账号    |" << endl;
    cout << "\t\t|      3.查看机房    |" << endl;
    cout << "\t\t|      4.清空预约    |" << endl;
    cout << "\t\t|      0.注销登录    |" << endl;
    cout << "\t\t--------------------" << endl;
    cout << "请选择您的操作：" << endl;
}

//添加账号
void Manager::addPerson() {
    cout << "请输入添加账号类型：" << endl;
    cout << "1.添加学生" << endl;
    cout << "2.添加老师" << endl;

    string fileName;
    string tip;
    string errorTip;
    ofstream ofs;

    int select = 0;
    cin >> select;
    if (select == 1) {
        fileName = STUDENT_FILE;
        tip = "请输入学号：";
        errorTip = "学号重复，请重新输入";
    } else {
        fileName = TEACHER_FILE;
        tip = "请输入职工编号：";
        errorTip = "职工编号重复，请重新输入";
    }
    ofs.open(fileName, ios::out | ios::app);

    int id;
    string name;
    string pwd;

    cout << tip << endl;

    while (true) {
        cin >> id;
        bool ret = checkRepeat(id, select);
        if (ret) {
            cout << errorTip << endl;
        } else {
            break;
        }
    }
    cout << "请输入姓名：" << endl;
    cin >> name;

    cout << "请输入密码：" << endl;
    cin >> pwd;

    ofs << id << " " << name << " " << pwd << endl;
    cout << "添加成功" << endl;

    myPause();
    myClear();

    ofs.close();

    initVector();
}

void printStudent(Student &s) {
    cout << "学号：" << s.m_Id << "，姓名：" << s.m_Name << "，密码：" << s.m_Password << endl;
}

void printTeacher(Teacher &s) {
    cout << "职工编号：" << s.m_EmpId << "，姓名：" << s.m_Name << "，密码：" << s.m_Password << endl;
}

//查看账号
void Manager::showPerson() {
    cout << "请选择查看内容：" << endl;
    cout << "1.查看所有学生" << endl;
    cout << "2.查看所有老师" << endl;
    int select = 0;
    cin >> select;
    if (select == 1) {
        for_each(vStudents.begin(), vStudents.end(), printStudent);
    } else {
        for_each(vTeachers.begin(), vTeachers.end(), printTeacher);
    }
    myPause();
    myClear();
}

//查看机房信息
void Manager::showComputer() {
    cout << "机房信息如下：" << endl;
    for (auto &com: vComputerRooms) {
        cout << "机房编号：" << com.m_ComId << "，机房容量：" << com.m_MaxNum << endl;
    }
    myPause();
    myClear();
}

//清空所有预约记录
void Manager::clearFile() {
    ofstream ofs(ORDER_FILE, ios::trunc);
    ofs.close();
    cout << "清空成功！" << endl;
    myPause();
    myClear();
}

//初始化容器
void Manager::initVector() {
    vStudents.clear();
    vTeachers.clear();

    ifstream ifs;
    ifs.open(STUDENT_FILE, ios::in);
    if (!ifs.is_open()) {
        cout << "文件读取失败" << endl;
        return;
    }
    Student s;
    //读取时候遇到空格会停下来
    while (ifs >> s.m_Id && ifs >> s.m_Name && ifs >> s.m_Password) {
        vStudents.push_back(s);
    }
    cout << "当前学生数量为：" << vStudents.size() << endl;
    ifs.close();

    ifs.open(TEACHER_FILE, ios::in);
    if (!ifs.is_open()) {
        cout << "文件读取失败" << endl;
        return;
    }
    Teacher t;
    //读取时候遇到空格会停下来
    while (ifs >> t.m_EmpId && ifs >> t.m_Name && ifs >> t.m_Password) {
        vTeachers.push_back(t);
    }
    cout << "当前老师数量为：" << vTeachers.size() << endl;
    ifs.close();
}

//添加账号去重
bool Manager::checkRepeat(int id, int type) {
    if (type == 1) {
        for (auto &vStudent: vStudents) {
            if (vStudent.m_Id == id) return true;
        }
    } else {
        for (auto &vTeacher: vTeachers) {
            if (vTeacher.m_EmpId == id) return true;
        }
    }
    return false;
}