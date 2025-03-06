#include <iostream>
using namespace std;

int main() {
    cout << "Please input a line of words:" << endl;
    
    char ch;
    string word = "";
    bool inWord = false;
    
    while (cin.get(ch)) {
        if (ch == '.') {
            if (inWord) {
                cout << word << ": " << word.length() << endl;
            }
            break;
        } else if (ch == ' ') {
            if (inWord) {
                cout << word << ": " << word.length() << endl;
                word = "";
                inWord = false;
            }
        } else {
            word += ch;
            inWord = true;
        }
    }
    
    return 0;
}