#include <iostream>
using namespace std;
class AbstractDrinking
{
public:
    // 煮水
    virtual void boil() = 0;
    // 冲泡
    virtual void brew() = 0;

    // 倒入杯中
    virtual void pourInCup() = 0;

    // 加入辅料
    virtual void putSomething() = 0;

    // 制作饮品
    void makeDrink()
    {
        boil();
        brew();
        pourInCup();
        putSomething();
    }
};

class Coffee : public AbstractDrinking
{
    // 煮水
    void boil()
    {
        cout << "煮农夫山泉" << endl;
    };
    // 冲泡
    void brew()
    {
        cout << "冲泡咖啡" << endl;
    };

    // 倒入杯中
    void pourInCup()
    {
        cout << "倒入杯中" << endl;
    };

    // 加入辅料
    void putSomething()
    {
        cout << "加入糖和牛奶" << endl;
    };
};

class Tea : public AbstractDrinking
{
    // 煮水
    void boil()
    {
        cout << "煮开水" << endl;
    };
    // 冲泡
    void brew()
    {
        cout << "冲泡茶叶" << endl;
    };

    // 倒入杯中
    void pourInCup()
    {
        cout << "倒入杯中" << endl;
    };

    // 加入辅料
    void putSomething()
    {
        cout << "加入枸杞" << endl;
    };
};
void doWork(AbstractDrinking *abs)
{
    abs->makeDrink();
    delete abs;
}
void test1()
{
    doWork(new Coffee);

    cout << endl;
    doWork(new Tea);
}

int main(int argc, char const *argv[])
{
    test1();
    return 0;
}
