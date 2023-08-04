//
// Created by cnting on 2023/8/4.
//

#include "student.h"
#include "../globalFile.h"
#include "../system_util.h"
#include "../orderFile.h"
#include "fstream"

Student::Student() {}

Student::Student(int id, string name, string pwd) {
    this->m_Id = id;
    this->m_Name = name;
    this->m_Password = pwd;

    //初始化机房信息
    ifstream ifs;
    ifs.open(COMPUTER_FILE, ios::in);
    ComputerRoom room;
    while (ifs >> room.m_ComId && ifs >> room.m_MaxNum) {
        vComputerRooms.push_back(room);
    }
    ifs.close();
}

void Student::operatorMenu() {
    cout << "欢迎学生" << m_Name << "登录！" << endl;
    cout << "\t\t-----------------------" << endl;
    cout << "\t\t|      1.申请预约       |" << endl;
    cout << "\t\t|      2.查看自身预约    |" << endl;
    cout << "\t\t|      3.查看所有预约    |" << endl;
    cout << "\t\t|      4.取消预约       |" << endl;
    cout << "\t\t|      0.注销登录       |" << endl;
    cout << "\t\t-----------------------" << endl;
    cout << "请选择您的操作：" << endl;
}

//申请预约
void Student::applyOrder() {
    cout << "机房开放时间为周一至周五" << endl;
    cout << "请输入申请预约的时间" << endl;
    cout << "1.周一" << endl;
    cout << "2.周二" << endl;
    cout << "3.周三" << endl;
    cout << "4.周四" << endl;
    cout << "5.周五" << endl;
    //日期
    int date = 0;
    //时间段
    int interval = 0;
    //机房编号
    int room = 0;
    while (true) {
        cin >> date;
        if (date >= 1 && date <= 5) {
            break;
        } else {
            cout << "输入有误，请重新输入" << endl;
        }
    }
    cout << "请输入申请预约时间段：" << endl;
    cout << "1.上午" << endl;
    cout << "2.下午" << endl;
    while (true) {
        cin >> interval;
        if (interval >= 1 && interval <= 2) {
            break;
        } else {
            cout << "输入有误，请重新输入" << endl;
        }
    }
    cout << "请选择机房：" << endl;
    for (int i = 0; i < vComputerRooms.size(); i++) {
        cout << vComputerRooms[i].m_ComId << "号机房容量为：" << vComputerRooms[i].m_MaxNum << endl;
    }
    while (true) {
        cin >> room;
        if (room >= 1 && room <= 3) {
            break;
        } else {
            cout << "输入有误，请重新输入" << endl;
        }
    }
    cout << "预约成功！审核中" << endl;
    ofstream ofs;
    ofs.open(ORDER_FILE, ios::app);
    ofs << "date:" << date << " ";
    ofs << "interval:" << interval << " ";
    ofs << "stuId:" << this->m_Id << " ";
    ofs << "stuName:" << this->m_Name << " ";
    ofs << "roomId:" << room << " ";
    ofs << "status:" << 1 << " ";
    ofs.close();
    myPause();
    myClear();
}

//查看自身预约
void Student::showMyOrder() {
    OrderFile orderFile;
    if (orderFile.m_Size == 0) {
        cout << "无预约记录" << endl;
        myPause();
        myClear();
        return;
    }
    for (int i = 0; i < orderFile.m_Size; i++) {
        //c_str() 转成c风格的字符串
        //atoi() 转成int类型
        string stuId = orderFile.m_orderData[i]["stuId"];
        if (to_string(this->m_Id) == stuId) {
            cout << "预约日期：周" << orderFile.m_orderData[i]["date"];
            cout << " 时间段：" << ((orderFile.m_orderData[i]["interval"] == "1") ? "上午" : "下午");
            cout << " 机房号：" << orderFile.m_orderData[i]["roomId"];
            string status = "状态：";
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
}

//查看所有预约
void Student::showAllOrder() {
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

//取消预约
void Student::cancelOrder() {
    OrderFile orderFile;
    if (orderFile.m_Size == 0) {
        cout << "无预约记录" << endl;
        myPause();
        myClear();
        return;
    }
    cout << "审核中或预约成功的记录可以取消，请输入取消的记录" << endl;
    int index = 1;
    vector<int> v;
    for (int i = 0; i < orderFile.m_Size; i++) {
        string stuId = orderFile.m_orderData[i]["stuId"];
        if (to_string(this->m_Id) == stuId) {
            string s = orderFile.m_orderData[i]["status"];
            if (s == "1" || s == "2") {
                v.push_back(i);
                cout << index++ << "、";
                cout << "预约日期：周" << orderFile.m_orderData[i]["date"];
                cout << " 时间段：" << ((orderFile.m_orderData[i]["interval"] == "1") ? "上午" : "下午");
                cout << " 机房号：" << orderFile.m_orderData[i]["roomId"];
                string status = "状态：";
                if (s == "1") {
                    status += "审核中";
                } else if (s == "2") {
                    status += "预约成功";
                }
                cout << status << endl;
            }
        }
    }
    cout << "请输入取消的记录，0代表返回" << endl;
    int select = 0;
    while (true) {
        cin >> select;
        if (select >= 0 && select <= v.size()) {
            if (select == 0) {
                break;
            } else {
                orderFile.m_orderData[v[select - 1]]["status"] = "0";
                orderFile.updateOrder();
                cout << "已取消预约" << endl;
                break;
            }
        } else {
            cout << "输入有误，请重新输入" << endl;
        }
    }
}