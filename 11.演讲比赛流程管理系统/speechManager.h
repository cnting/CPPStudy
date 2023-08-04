#pragma once

#include "iostream"
#include "vector"
#include "map"
#include "speaker.h"

using namespace std;

//设计演讲比赛管理类
class SpeechManager {
public:
    SpeechManager();

    void showMenu();

    void exitSystem();

    ~SpeechManager();

    void initSpeech();

    //创建选手
    void createSpeaker();

    //开始比赛
    void startSpeech();

    //抽签
    void speechDraw();

    //比赛
    void speechContest();

    //显示比赛结果
    void showScore();

    //保存记录
    void saveRecord();

    //读取记录
    void loadRecord();

    //显示记录
    void showRecord();

    //清空记录
    void clearRecord();

    //第一轮比赛选手编号
    vector<int> v1;
    //第二轮比赛选手编号
    vector<int> v2;
    //胜出前三名选手编号
    vector<int> vVictory;
    //存放编号对应的选手
    map<int, Speaker> m_Speaker;
    //存放比赛轮数
    int index;
    //文件是否为空
    bool fileIsEmpty;
    //往届记录
    map<int, vector<string>> m_Record;
};
