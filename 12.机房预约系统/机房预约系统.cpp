#include "iostream"
#include "identity/identity.h"
#include "fstream"
#include "globalFile.h"
#include "identity/student.h"
#include "identity/teacher.h"
#include "identity/manager.h"
#include "system_util.h"

using namespace std;

//进入管理员子菜单
void managerMenu(Identity *&manager) {
    while (true) {
        manager->operatorMenu();
        auto *man = (Manager *) manager;
        int select = 0;
        cin >> select;
        if (select == 1) {
            //添加账号
            man->addPerson();
        } else if (select == 2) {
            //查看账号
            man->showPerson();
        } else if (select == 3) {
            //查看机房
            man->showComputer();
        } else if (select == 4) {
            //清空预约
            man->clearFile();
        } else {
            delete man;
            cout << "注销成功" << endl;
            myPause();
            myClear();
            return;
        }
    }
}

//进入学生子菜单
void studentMenu(Identity *&student) {
    while (true) {
        student->operatorMenu();
        auto *man = (Student *) student;
        int select = 0;
        cin >> select;
        if (select == 1) {
            //申请预约
            man->applyOrder();
        } else if (select == 2) {
            //查看自身预约
            man->showMyOrder();
        } else if (select == 3) {
            //查看所有预约
            man->showAllOrder();
        } else if (select == 4) {
            //取消预约
            man->cancelOrder();
        } else {
            delete man;
            cout << "注销成功" << endl;
            myPause();
            myClear();
            return;
        }
    }
}

//进入学生子菜单
void teacherMenu(Identity *&teacher) {
    while (true) {
        teacher->operatorMenu();
        auto *man = (Teacher *) teacher;
        int select = 0;
        cin >> select;
        if (select == 1) {
            //查看所有预约
            man->showAllOrder();
        } else if (select == 2) {
            //审核预约
            man->validOrder();
        } else {
            delete man;
            cout << "注销成功" << endl;
            myPause();
            myClear();
            return;
        }
    }
}

//确认文件存在
void checkFileExist() {
    string arr[] = {STUDENT_FILE, TEACHER_FILE, ADMIN_FILE, COMPUTER_FILE, ORDER_FILE};
    for (string name: arr) {
        ofstream ofs;
        ofs.open(name, ios::out | ios::app);
        ofs.close();
    }
}

//登录
void LoginIn(string fileName, int type) {
    //父类指针，用于指向子类对象
    Identity *person;

    //读文件
    ifstream ifs;
    ifs.open(fileName, ios::in);

    if (!ifs.is_open()) {
        cout << "文件不存在" << endl;
        ifs.close();
        return;
    }

    int id = 0;
    string name;
    string pwd;

    if (type == 1) {
        cout << "请输入你的学号" << endl;
        cin >> id;
    } else if (type == 2) {
        cout << "请输入你的职工号" << endl;
        cin >> id;
    }
    cout << "请输入用户名" << endl;
    cin >> name;

    cout << "请输入密码" << endl;
    cin >> pwd;

    if (type == 1) {
        int fId;
        string fName;
        string fPwd;
        while (ifs >> fId && ifs >> fName && ifs >> fPwd) {
            if (fId == id && fName == name && fPwd == pwd) {
                cout << "学生验证登录成功!" << endl;
                myPause();
                myClear();
                person = new Student(id, name, pwd);
                studentMenu(person);
                return;
            }
        }
    } else if (type == 2) {
        int fId;
        string fName;
        string fPwd;
        while (ifs >> fId && ifs >> fName && ifs >> fPwd) {
            if (fId == id && fName == name && fPwd == pwd) {
                cout << "教师验证登录成功!" << endl;
                myPause();
                myClear();
                person = new Teacher(id, name, pwd);
                teacherMenu(person);
                return;
            }
        }
    } else if (type == 3) {
        string fName;
        string fPwd;
        while (ifs >> fName && ifs >> fPwd) {
            if (fName == name && fPwd == pwd) {
                cout << "管理员验证登录成功!" << endl;
                myPause();
                myClear();
                person = new Manager(name, pwd);
                managerMenu(person);
                return;
            }
        }
    }
    cout << "验证登录失败" << endl;
}

int main() {
    checkFileExist();
    int select = 0;
    while (true) {
        cout << "********欢迎来到机房预约系统**********" << endl;
        cout << endl << "请输入你的身份：" << endl;
        cout << "\t\t----------------------\n";
        cout << "\t\t|      1.学生代表      |\n";
        cout << "\t\t|      2.老   师      |\n";
        cout << "\t\t|      3.管 理 员      |\n";
        cout << "\t\t|      0.退   出       |\n";
        cout << "\t\t----------------------\n";
        cout << "输入你的选择：";

        cin >> select;

        switch (select) {
            case 1://学生
                LoginIn(STUDENT_FILE, 1);
                break;
            case 2://老师
                LoginIn(TEACHER_FILE, 2);
                break;
            case 3://管理员
                LoginIn(ADMIN_FILE, 3);
                break;
            case 0://退出
                cout << "欢迎下次使用" << endl;
                return 0;
            default:
                cout << "输入有误" << endl;
                break;
        }
    }
}