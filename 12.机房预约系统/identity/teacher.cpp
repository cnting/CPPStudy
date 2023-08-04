//
// Created by cnting on 2023/8/4.
//

#include "teacher.h"
#include "../orderFile.h"
#include "../system_util.h"
#include "vector"

Teacher::Teacher() {}

Teacher::Teacher(int id, string name, string pwd) {
    this->m_EmpId = id;
    this->m_Name = name;
    this->m_Password = pwd;
}

void Teacher::operatorMenu() {
    cout << "欢迎老师" << m_Name << "登录！" << endl;
    cout << "\t\t-----------------------" << endl;
    cout << "\t\t|      1.查看所有预约    |" << endl;
    cout << "\t\t|      2.审核预约       |" << endl;
    cout << "\t\t|      0.注销登录       |" << endl;
    cout << "\t\t-----------------------" << endl;
    cout << "请选择您的操作：" << endl;
}

//查看所有学生预约
void Teacher::showAllOrder() {
    OrderFile orderFile;
    if (orderFile.m_Size == 0) {
        cout << "无预约记录" << endl;
        myPause();
        myClear();
        return;
    }
    for (int i = 0; i < orderFile.m_Size; i++) {
        cout << "预约日期：周" << orderFile.m_orderData[i]["date"];
        cout << " 时间段：" << ((orderFile.m_orderData[i]["interval"] == "1") ? "上午" : "下午");
        cout << " 机房号：" << orderFile.m_orderData[i]["roomId"];
        cout << " 姓名：" << orderFile.m_orderData[i]["stuName"];
        string status = " 状态：";
        if (orderFile.m_orderData[i]["status"] == "1") {
            status += "审核中";
        } else if (orderFile.m_orderData[i]["status"] == "2") {
            status += "预约成功";
        } else if (orderFile.m_orderData[i]["status"] == "-1") {
            status += "预约失败，审核未通过";
        } else {
            status += "预约已取消";
        }
        cout << status << endl;
    }
}

//审核预约
void Teacher::validOrder() {
    OrderFile orderFile;
    if (orderFile.m_Size == 0) {
        cout << "无预约记录" << endl;
        myPause();
        myClear();
        return;
    }
    cout << "待审核的预约记录如下：" << endl;
    int index = 1;
    vector<int> v;
    for (int i = 0; i < orderFile.m_Size; i++) {
        if (orderFile.m_orderData[i]["status"] == "1") {
            v.push_back(i);
            cout << index++ << "、";
            cout << "预约日期：周" << orderFile.m_orderData[i]["date"];
            cout << " 时间段：" << ((orderFile.m_orderData[i]["interval"] == "1") ? "上午" : "下午");
            cout << " 机房号：" << orderFile.m_orderData[i]["roomId"];
            cout << " 姓名：" << orderFile.m_orderData[i]["stuName"];
            cout << endl;
        }
    }
    cout << "请输入待审核的记录，0表示返回" << endl;
    int select = 0;
    int ret = 0;
    while (true) {
        cin >> select;
        if (select >= 0 && select <= v.size()) {
            if (select == 0) {
                break;
            } else {
                cout << "请输入审核结果" << endl;
                cout << "1.通过" << endl;
                cout << "2.不通过" << endl;
                cin >> ret;
                if (ret == 1) {
                    orderFile.m_orderData[v[select - 1]]["status"] = "2";
                } else {
                    orderFile.m_orderData[v[select - 1]]["status"] = "-1";
                }
                orderFile.updateOrder();
                cout << "审核完毕" << endl;
                break;
            }
        } else {
            cout << "输入有误，请重新输入" << endl;
        }
    }
}
