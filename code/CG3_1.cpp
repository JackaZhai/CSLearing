#include <iostream>
#include <cstring>

using namespace std;

class Date {
private:
    int year;
    int month;
    int day;
public:

    Date(int y = 0, int m = 0, int d = 0) {
        year = y;
        month = m;
        day = d;
    }

    ~Date() {
        
    }

    inline void setDate(int y, int m, int d) {
        year = y;
        month = m;
        day = d;
    }
    
    inline void print() const {
        cout << year << "年" << month << "月" << day << "日";
    }
};

class People {
private:
    char name[11];
    char number[7];
    char sex[3];
    Date birthday;
    char id[19];
    
public:
    People() {
        name[0] = '0';
        number[0] = '0';
        sex[0] = '0';
        birthday.setDate(0, 0, 0);
        id[0] = '0';
    }
    
    ~People() {
    }
    
    People(const People& p) {
        strcpy(name, p.name);
        strcpy(number, p.number);
        strcpy(sex, p.sex);
        birthday = p.birthday; 
        strcpy(id, p.id);
    }
    
    void input() {
        cout << "姓名：";
        cin >> name;
        
        cout << "编号：";
        cin >> number;
        
        cout << "性别(男/女)：";
        cin >> sex;
        
        int year, month, day;
        cout << "出生日期（年 月 日）：";
        cin >> year >> month >> day;
        birthday.setDate(year, month, day);
        
        cout << "身份证号：";
        cin >> id;
    }
    
    inline void display() const {
        cout << "姓名：" << name << endl;
        cout << "编号：" << number << endl;
        cout << "性别：" << sex << endl;
        cout << "出生日期：";
        birthday.print();
        cout << endl;
        cout << "身份证号：" << id << endl;
    }
};

int main() {
    int n;
    cout << "员工人数：";
    cin >> n;
    
    People* staff = new People[n];
    
    for (int i = 0; i < n; i++) {
        staff[i].input();
    }
    cout << endl;
    
    People firstCopy(staff[0]);
    
    firstCopy.display();
    
    for (int i = 0; i < n; i++) {
        staff[i].display();
    }
    
    delete[] staff;
    
    return 0;
}