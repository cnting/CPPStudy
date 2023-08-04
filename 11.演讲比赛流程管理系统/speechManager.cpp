
#include "speechManager.h"
#include "deque"
#include "numeric"
#include "fstream"

void myPause() {
    cout << "按任意键后继续..." << endl;
    getchar();
}

void myClear() {
    //todo 这个没效果
    system("clear");
}

SpeechManager::SpeechManager() {
    initSpeech();
    createSpeaker();
    loadRecord();
}

void SpeechManager::showMenu() {
    cout << "**********************" << endl;
    cout << "****欢迎参加演讲比赛****" << endl;
    cout << "****1.开始演讲比赛*****" << endl;
    cout << "****2.查看往届比赛******" << endl;
    cout << "****3.清空比赛记录******" << endl;
    cout << "****0.退出比赛程序*******" << endl;
    cout << "**********************" << endl;
    cout << endl;
}

//退出系统
void SpeechManager::exitSystem() {
    cout << "欢迎下次使用" << endl;
    exit(0);
}

SpeechManager::~SpeechManager() {}

void SpeechManager::initSpeech() {
    v1.clear();
    v2.clear();
    vVictory.clear();
    m_Speaker.clear();
    index = 1;
    m_Record.clear();
}

void SpeechManager::createSpeaker() {
    string nameSeed = "ABCDEFGHIJKL";
    for (int i = 0; i < nameSeed.size(); i++) {
        string name = "选手";
        name += nameSeed[i];
        Speaker speaker;
        speaker.m_Name = name;
        for (int j = 0; j < 2; j++) {
            speaker.m_Score[j] = 0;
        }
        int id = i + 10001;
        v1.push_back(id);
        m_Speaker.insert(make_pair(id, speaker));
    }

}

void SpeechManager::startSpeech() {
    //第一轮比赛
    //1.抽签
    speechDraw();
    //2.比赛
    speechContest();
    //3.显示晋级结果
    showScore();
    //第二轮比赛
    index++;
    //1.抽签
    speechDraw();
    //2.比赛
    speechContest();
    //3.显示最终结果
    showScore();
    //4.保存分数到文件中
    saveRecord();

    //重置比赛，获取记录
    initSpeech();
    createSpeaker();
    loadRecord();

    cout << "本届比赛完毕!" << endl;
    myPause();
    myClear();
}

//抽签
void SpeechManager::speechDraw() {
    cout << "-------第 《" << index << "》" << "轮比赛选手正在抽签---------" << endl;
    cout << "抽签后演讲顺序如下：" << endl;
    if (this->index == 1) {
        //第一轮比赛
        random_shuffle(v1.begin(), v1.end());
        for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++) {
            cout << *it << " ";
        }
        cout << endl;
    } else {
        //第二轮比赛
        random_shuffle(v2.begin(), v2.end());
        for (vector<int>::iterator it = v2.begin(); it != v2.end(); it++) {
            cout << *it << " ";
        }
        cout << endl;
    }
    cout << "-----------------" << endl;
    myPause();
}

//比赛
void SpeechManager::speechContest() {
    cout << "--------第 《" << index << "》" << "轮比赛正式开始--------" << endl;

    //存放小组成绩
    multimap<double, int, greater<double>> groupScore;

    //记录人员个数
    int num = 0;

    //比赛选手的容器
    vector<int> v_Src = index == 1 ? v1 : v2;

    //遍历所有选手进行比赛
    for (vector<int>::iterator it = v_Src.begin(); it != v_Src.end(); it++) {
        num++;
        //评委打分
        deque<double> d;
        for (int i = 0; i < 10; i++) {
            //rand() % 401，范围[0,401)
            //rand() % 401 + 600，范围[600,1000)
            //(rand() % 401 + 600 )/ 10.f，范围[60,100)并且有小数
            double score = (rand() % 401 + 600) / 10.f;
            d.push_back(score);
        }
        //降序排
        sort(d.begin(), d.end(), greater<double>());
        //去除最高分
        d.pop_front();
        //去除最低分
        d.pop_back();
        //总分
        double sum = accumulate(d.begin(), d.end(), 0.0f);
        //平均分
        double avg = sum / (double) d.size();
        //保存分数
        this->m_Speaker[*it].m_Score[index - 1] = avg;

        //6人一组取前三名，groupScore这个容器是按成绩从大到小排
        groupScore.insert(make_pair(avg, *it));
        if (num % 6 == 0) {
            cout << "第" << num / 6 << "小组比赛名次如下：" << endl;
            for (multimap<double, int, greater<double>>::iterator it = groupScore.begin();
                 it != groupScore.end(); it++) {
                cout << "编号：" << it->second
                     << " 姓名：" << m_Speaker[it->second].m_Name
                     << " 成绩：" << m_Speaker[it->second].m_Score[index - 1]
                     << endl;
            }
            //取走前三名
            int count = 0;
            for (multimap<double, int, greater<double>>::iterator it = groupScore.begin();
                 it != groupScore.end() && count < 3; it++, count++) {
                if (index == 1) {
                    v2.push_back(it->second);
                } else {
                    vVictory.push_back(it->second);
                }
            }
            groupScore.clear();
            cout << endl;
        }
    }

    cout << "-------第 《" << index << "》" << "轮比赛完毕--------" << endl;

    myPause();
}

//显示分数
void SpeechManager::showScore() {
    cout << "--------第 《" << index << "》" << "轮比赛结果如下---------" << endl;
    vector<int> v = index == 1 ? v2 : vVictory;
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
        cout << "选手编号:" << *it << " 姓名：" << m_Speaker[*it].m_Name << " 得分" << m_Speaker[*it].m_Score[index - 1]
             << endl;
    }
    cout << endl;
    myPause();
//    myClear();
//    showMenu();
}

//保存记录
void SpeechManager::saveRecord() {
    ofstream ofs;
    ofs.open("speech.csv", ios::out | ios::app); //用追加的方式写文件
    for (vector<int>::iterator it = vVictory.begin(); it != vVictory.end(); it++) {
        ofs << *it << "," << m_Speaker[*it].m_Score[1] << ",";
    }
    ofs << endl;
    ofs.close();
    this->fileIsEmpty = false;
    cout << "记录已经保存" << endl;
}

//读取记录
void SpeechManager::loadRecord() {
    ifstream ifs("speech.csv", ios::in);
    if (!ifs.is_open()) {
        this->fileIsEmpty = true;
        cout << "文件不存在" << endl;
        return;
    }
    //文件清空的情况
    char ch;
    ifs >> ch;
    if (ifs.eof()) {
        cout << "文件为空" << endl;
        this->fileIsEmpty = true;
        ifs.close();
        return;
    }
    //文件不为空
    this->fileIsEmpty = false;
    //将上面读取的单个字符放回来
    ifs.putback(ch);
    string data;
    int i = 0;
    while (ifs >> data) {
        //C++没有split
        int pos = -1;
        int start = 0;
        vector<string> v;
        while (true) {
            pos = data.find(",", start);
            if (pos == -1) {
                //没找到
                break;
            } else {
                string temp = data.substr(start, pos - start);
                v.push_back(temp);
                start = pos + 1;
            }
        }
        m_Record.insert(make_pair(i++, v));
    }
    ifs.close();
}

void SpeechManager::showRecord() {
    if (this->fileIsEmpty) {
        cout << "记录不存在" << endl;
    } else {
        for (int i = 0; i < this->m_Record.size(); i++) {
            cout << "第" << i + 1 << "届"
                 << " 冠军编号:" << this->m_Record[i][0] << " 得分:" << this->m_Record[i][1]
                 << " 季军编号:" << this->m_Record[i][2] << " 得分:" << this->m_Record[i][3]
                 << " 亚军编号:" << this->m_Record[i][4] << " 得分:" << this->m_Record[i][5]
                 << endl;
        }
    }

    myPause();
    myClear();
}

void SpeechManager::clearRecord() {
    cout << "是否确定清空文件?" << endl;
    cout << "1.是" << endl;
    cout << "2.否" << endl;
    int select = 0;
    cin >> select;
    if (select == 1) {
        //确认清空
        ofstream ofs("speech.csv", ios::trunc);
        ofs.close();

        initSpeech();
        createSpeaker();
        loadRecord();

        cout << "清空成功" << endl;
    }
    myPause();
    myClear();
}