#include <iostream>
using namespace std;
class CPU
{
public:
    virtual void calculate() = 0;
    // virtual ~CPU(){}
};
class GPU
{
public:
    virtual void display() = 0;
    // virtual ~GPU(){}
};
class Memory
{
public:
    virtual void storage() = 0;
    // virtual ~Memory(){}
};

class Computer
{
public:
    Computer(CPU *cpu, GPU *gpu, Memory *memory)
    {
        m_cpu = cpu;
        m_gpu = gpu;
        m_memory = memory;
    }
    ~Computer()
    {
        if (m_cpu != NULL)
        {
            delete m_cpu;
            m_cpu = NULL;
        }
        if (m_gpu != NULL)
        {
            delete m_gpu;
            m_gpu = NULL;
        }
        if (m_memory != NULL)
        {
            delete m_memory;
            m_memory = NULL;
        }
    }

    void work()
    {
        m_cpu->calculate();
        m_gpu->display();
        m_memory->storage();
    }

private:
    CPU *m_cpu;
    GPU *m_gpu;
    Memory *m_memory;
};

class IntelCPU : public CPU
{
public:
    void calculate()
    {
        cout << "Intel CPU 开始工作了" << endl;
    }
};

class IntelGPU : public GPU
{
public:
    void display()
    {
        cout << "Intel GPU 开始工作了" << endl;
    }
};

class IntelMemory : public Memory
{
public:
    void storage()
    {
        cout << "Intel Memory 开始工作了" << endl;
    }
};

class LevonoCPU : public CPU
{
public:
    void calculate()
    {
        cout << "Levono CPU 开始工作了" << endl;
    }
};

class LevonoGPU : public GPU
{
public:
    void display()
    {
        cout << "Levono GPU 开始工作了" << endl;
    }
};

class LevonoMemory : public Memory
{
public:
    void storage()
    {
        cout << "Levono Memory 开始工作了" << endl;
    }
};

void test1()
{
    CPU *intelCPU = new IntelCPU;
    GPU *intelGPU = new IntelGPU;
    Memory *intelMemory = new IntelMemory;
    Computer *computer1 = new Computer(intelCPU, intelGPU, intelMemory);
    computer1->work();
    delete computer1;
}

int main(int argc, char const *argv[])
{
    test1();
    return 0;
}
