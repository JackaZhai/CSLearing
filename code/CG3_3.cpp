#include <iostream>
#include <cstring>

using namespace std;

class Student{
    private:
        int stuId;
        char name[20];
        int classId;
        static int stuCount;
    public:
        Student(int id = 0, const char* n = "未知", int c = 1001) {
            stuId = id;
            strcpy(name, n);
            stuCount++;
            classId = c;
        }
        
        ~Student(){
            stuCount--;
        }
        
        void Print() const {
            cout << "名字:" << name << endl;
            cout << "学号:" << stuId << endl;
            cout << "班级:" << classId << endl;
            cout << "班级人数:" << stuCount << endl;
        }

        
        friend void Output(Student s);
};

int Student::stuCount = 45;

void Output(Student s) {
    cout << "名字:" << s.name << endl;
    cout << "学号:" << s.stuId << endl;
    cout << "班级:" << s.classId << endl;
    cout << "班级人数:" << s.stuCount << endl;
}

int main() {
    char name1[20], name2[20];
    cin >> name1 >> name2;
    
    Student stu1(1, name1);
    Student stu2(2, name2);
    
    stu1.Print();
    cout << endl;
    
    Output(stu2);
    
    return 0;
}