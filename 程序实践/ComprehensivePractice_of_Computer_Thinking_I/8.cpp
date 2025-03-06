#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool isPalindrome(const string& s) {
    return equal(s.begin(), s.end(), s.rbegin());
}

string toBase(int n, int base) {
    string result;
    while (n > 0) {
        result += '0' + n % base;
        n /= base;
    }
    reverse(result.begin(), result.end());
    return result;
}

int main() {
    int n = 11;
    while (true) {
        string dec = to_string(n);
        string bin = toBase(n, 2);
        string oct = toBase(n, 8);
        if (isPalindrome(dec) && isPalindrome(bin) && isPalindrome(oct)) {
            cout << n << endl;
            break;
        }
        n++;
    }
    return 0;
}