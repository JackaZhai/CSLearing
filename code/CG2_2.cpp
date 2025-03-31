#include <iostream>
using namespace std;

enum CPU_Rank {P1=1, P2, P3, P4, P5, P6, P7};

class CPU {
private:
    CPU_Rank rank;
    int frequency;
    float voltage;
public:
    CPU(CPU_Rank r) {
        rank = r;
        frequency = 0;
        voltage = 0.0;
        cout << "构造了一个CPU!" << endl;
    }
    ~CPU() {
        cout << "析构了一个CPU!" << endl;
    }
    CPU_Rank GetRank() const { return rank; }

    void run() { 
        cout << "CPU开始运行!" << endl;
        cout << "等级为:" << GetRank() << endl;
     }
    void stop() { cout << "CPU停止运行!" << endl; }
};

int main() {
    int r1, r2;
    cin >> r1 >> r2;
    
    CPU cpu1((CPU_Rank(r1))), cpu2((CPU_Rank(r2)));
    
    cpu1.run();
    
    cpu1.stop();
    
    cpu2.run();
    cpu2.stop();
    
    return 0;
}