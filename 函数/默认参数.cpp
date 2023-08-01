#include <iostream>
using namespace std;
void func(int a, int)
{
    cout << "this is func" << endl;
}

int main(int argc, char const *argv[])
{
    func(10, 10);
    return 0;
}
