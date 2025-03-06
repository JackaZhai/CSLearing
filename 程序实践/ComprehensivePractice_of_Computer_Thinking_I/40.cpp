#include <iostream>
using namespace std;

// 判断是否为闰年
bool isLeapYear(int year) {
    if (year % 400 == 0)
        return true;
    else if (year % 100 == 0)
        return false;
    else if (year % 4 == 0)
        return true;
    else
        return false;
}

// 计算从公元1年1月1日到指定日期的总天数
int calculateDays(int year, int month, int day) {
    int totalDays = 0;
    // 累加年份的天数
    for (int y = 1; y < year; y++) {
        if (isLeapYear(y))
            totalDays += 366;
        else
            totalDays += 365;
    }
    // 每个月的天数
    int daysInMonth[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
    // 累加月份的天数
    for (int m = 1; m < month; m++) {
        if (m == 2 && isLeapYear(year))
            totalDays += 29;
        else
            totalDays += daysInMonth[m];
    }
    // 加上天数
    totalDays += day;
    return totalDays;
}

int main() {
    int startYear, startMonth, startDay;
    int endYear, endMonth, endDay;
    cin >> startYear >> startMonth >> startDay;
    cin >> endYear >> endMonth >> endDay;

    int days1 = calculateDays(startYear, startMonth, startDay);
    int days2 = calculateDays(endYear, endMonth, endDay);

    int result = days2 - days1;
    cout << result << endl;

    return 0;
}