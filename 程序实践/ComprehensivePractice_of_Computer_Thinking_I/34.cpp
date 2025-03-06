
#include <iostream>
#include <string>
using namespace std;

int main() {
    string input;
    getline(cin, input);

    int len = input.length();
    int decimalPos = -1; // 小数点位置
    string digits = "";  // 去掉小数点的数字部分

    // 去掉小数点，记录小数点位置
    for (int i = 0; i < len; i++) {
        if (input[i] == '.') {
            decimalPos = i;
        } else {
            digits += input[i];
        }
    }

    // 找到第一个非零数字的位置
    int firstNonZero = -1;
    for (int i = 0; i < digits.length(); i++) {
        if (digits[i] != '0') {
            firstNonZero = i;
            break;
        }
    }

    // 如果全是0
    if (firstNonZero == -1) {
        cout << "0e0" << endl;
        return 0;
    }

    // 去掉末尾的无效零
    int lastNonZero = digits.length() - 1;
    while (digits[lastNonZero] == '0') {
        lastNonZero--;
    }

    string mantissa = digits.substr(firstNonZero, lastNonZero - firstNonZero + 1);

    int exponent = 0;
    if (decimalPos == -1) {
        // 没有小数点
        exponent = digits.length() - firstNonZero - 1;
    } else {
        exponent = decimalPos - firstNonZero - 1;
    }

    // 构造底数部分
    if (mantissa.length() == 1) {
        cout << mantissa << "e" << exponent << endl;
    } else {
        cout << mantissa[0] << "." << mantissa.substr(1) << "e" << exponent << endl;
    }

    return 0;
}