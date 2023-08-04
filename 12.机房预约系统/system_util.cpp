#include "iostream"
#include "system_util.h"

using namespace std;


void myPause() {
    cout << endl;
    cout << "按任意键后继续..." << endl;
    getchar();
    cout << endl;
}

void myClear() {
    //todo 这个没效果
    system("clear");
}