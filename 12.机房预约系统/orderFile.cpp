//
// Created by cnting on 2023/8/4.
//

#include "orderFile.h"

OrderFile::OrderFile() {
    ifstream ifs;
    ifs.open(ORDER_FILE, ios::in);
    string arr[6];
    m_Size = 0;
    while (ifs >> arr[0] && ifs >> arr[1]
           && ifs >> arr[2] && ifs >> arr[3]
           && ifs >> arr[4] && ifs >> arr[5]) {
        map<string, string> m;
        for (const string &s: arr) {
            int pos = s.find(":");
            if (pos != -1) {
                string key = s.substr(0, pos);
                string value = s.substr(pos + 1, s.size() - pos - 1);
                m.insert(make_pair(key, value));
            }
        }
        m_orderData.insert(make_pair(m_Size++, m));
    }
    ifs.close();
}

//更新预约记录
void OrderFile::updateOrder() {
    if (m_Size == 0) {
        return;
    }
    ofstream ofs(ORDER_FILE, ios::out | ios::trunc);
    for (int i = 0; i < m_Size; i++) {
        ofs << "date:" << m_orderData[i]["date"] << " ";
        ofs << "interval:" << m_orderData[i]["interval"] << " ";
        ofs << "stuId:" << m_orderData[i]["stuId"] << " ";
        ofs << "stuName:" << m_orderData[i]["stuName"] << " ";
        ofs << "roomId:" << m_orderData[i]["roomId"] << " ";
        ofs << "status:" << m_orderData[i]["status"] << " ";
    }
    ofs.close();
}