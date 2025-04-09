#include <iostream>
using namespace std;

class Score {
    private:
        int math;
        int eng;
    public:
        Score(int m = 0,int e = 0){
            math = m;
            eng = e;
        }
        void show(){
            cout << "数学成绩：" << math <<endl;
            cout<< "英语成绩：" << eng << endl;
        }
};

class Student {
    private:
        int stuid;
        Score mark;
    public:
        Student(int id = 0,int m = 0,int e = 0):stuid(id),mark(m,e){}
        void stushow(){
            cout << "学号：" << stuid << endl;
            mark.show();
        }
};

int main() {
    int id,m,e;
    cout << "学号：";
    cin >> id;

    cout << "数学成绩：";
    cin >> m;

    cout << "英语成绩：";
    cin >> e;
    cout<<endl;
    Student stu1(id,m,e);
    stu1.stushow();
    return 0;
}