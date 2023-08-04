#pragma once

#include "iostream"

using namespace std;

#include "map"
#include "globalFile.h"
#include "fstream"

class OrderFile {
public:
    OrderFile();

    //更新预约记录
    void updateOrder();

    int m_Size = 0;

    map<int, map<string, string>> m_orderData;
};