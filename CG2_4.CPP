#include <iostream>

using namespace std;

// 定义日期类
class date {
private:
    int year, month, day;
    
public:
    // 进行合法性检查
    bool isRunYear(int y) {
        return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
    }
    
    int getDaysInMonth(int y, int m) {
        if (m == 4 || m == 6 || m == 9 || m == 11) {
            return 30;
        } else if (m == 2) {
            if (isRunYear(y)) {
                return 29;
            } else {
                return 28;
            }
        } else {
            return 31;
        }
    }
    
    bool isBadDate(int y, int m, int d) {
        if (m < 1 || m > 12) return false;
        if (d < 1 || d > getDaysInMonth(y, m)) return false;
        return true;
    }

    date() {
        year = 2025;
        month = 1;
        day = 1;
    }

    date(int y, int m, int d) {
        if (isBadDate(y, m, d)) {
            year = y;
            month = m;
            day = d;
        } else {
            cout << "无效日期，使用默认值" << endl;
            year = 2025;
            month = 1;
            day = 1;
        }
    } 
    
    // 拷贝构造函数
    date(const date& d) {
        year = d.year;
        month = d.month;
        day = d.day;
    }
    
    bool setYear(int y) {
        if (y >= 2024 ) {
            year = y;
            return true;
        }
        return false;
    }
    
    bool setMonth(int m) {
        if (m >= 1 && m <= 12) {
            month = m;
            return true;
        }
        return false;
    }
    
    bool setDay(int d) {
        int maxDays = getDaysInMonth(year, month);
        if (d >= 1 && d <= maxDays) {
            day = d;
            return true;
        }
        return false;
    }
    
    bool setDate(int y, int m, int d) {
        if (isBadDate(y, m, d)) {
            year = y;
            month = m;
            day = d;
            return true;
        }
        return false;
    }
    
    int getYear() const { return year; }
    int getMonth() const { return month; }
    int getDay() const { return day; }
    
    void display() const {
        cout << year << "年" << month << "月" << day << "日" << endl;
    }
    
    void displayF() const {
        cout << year << "-";
        if (month < 10) cout << "0";
        cout << month << "-";
        if (day < 10) cout << "0";
        cout << day << endl;
    }
};

int main() {
    date date1;
    cout << "默认日期：";
    date1.display();
    
    date date2(2025, 3, 15);
    cout << "指定日期：";
    date2.display();
    
    date date3(2025, 2, 30);
    cout << "尝试创建无效日期后：";
    date3.display();
    
    date date4 = date2;
    cout << "拷贝日期：";
    date4.display();
    
    date date5;
    if(date5.setYear(2025))
        cout << "年份设置成功" << endl;
    if(date5.setMonth(2))
        cout << "月份设置成功" << endl;
    if(date5.setDay(29))
        cout << "日期设置成功" << endl;
    cout << "修改后的日期：";
    date5.displayF();
    
    if(!date5.setMonth(13))
        cout << "无效月份" << endl;
    if(!date5.setDay(30))
        cout << "无效日期" << endl;
    
    date5.setDate(2025, 12, 31);
    cout << "最终日期：";
    date5.displayF();
    
    return 0;
}