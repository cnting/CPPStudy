#include "iostream"
#include "speechManager.h"

using namespace std;

int main() {
    //随机数种子
    srand((unsigned int) time(NULL));

    SpeechManager speechManager;

    int choice = 0; //用来存储用户的选项
    while (true) {
        speechManager.showMenu();
        cout << "请输入你的选择:" << endl;
        //todo 判断输入是否是数字
        cin >> choice;

        switch (choice) {
            case 1://开始比赛
                speechManager.startSpeech();
                break;
            case 2://查看比赛记录
                speechManager.showRecord();
                break;
            case 3://清空比赛记录
                speechManager.clearRecord();
                break;
            case 0:
                speechManager.exitSystem();
                break;
            default:
                system("clear");//清屏
                break;
        }
    }

    return 0;
}
