#include <iostream>
using namespace std;
class AbstractCalculator
{
public:
    virtual int getResult()
    {
        return 0;
    }
    int num1;
    int num2;
};

class AddCalculator : public AbstractCalculator
{
public:
    int getResult()
    {
        return num1 + num2;
    }
};

class SubCalculator : public AbstractCalculator
{
public:
    int getResult()
    {
        return num1 - num2;
    }
};

class MulCalculator : public AbstractCalculator
{
public:
    int getResult()
    {
        return num1 * num2;
    }
};

void test1()
{
    AbstractCalculator *abc = new AddCalculator;
    abc->num1 = 10;
    abc->num2 = 10;
    cout << abc->num1 << "+" << abc->num2 << "=" << abc->getResult() << endl;
    delete abc;
}

int main(int argc, char const *argv[])
{
    test1();
    return 0;
}
