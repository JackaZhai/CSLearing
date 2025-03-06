#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void removeComments(const string& inputFile, const string& outputFile) {
    ifstream inFile(inputFile);
    ofstream outFile(outputFile);

    if (!inFile.is_open() || !outFile.is_open()) {
        cerr << "Error opening file!" << endl;
        return;
    }

    string line;
    bool inBlockComment = false;

    while (getline(inFile, line)) {
        string newLine;
        int i = 0;
        while (i < line.size()) {
            if (!inBlockComment && i + 1 < line.size() && line[i] == '/' && line[i + 1] == '*') {
                inBlockComment = true;
                i += 2;
            } else if (inBlockComment && i + 1 < line.size() && line[i] == '*' && line[i + 1] == '/') {
                inBlockComment = false;
                i += 2;
            } else if (!inBlockComment && i + 1 < line.size() && line[i] == '/' && line[i + 1] == '/') {
                break;
            } else if (!inBlockComment) {
                newLine += line[i];
                i++;
            } else {
                i++;
            }
        }
        if (!inBlockComment && !newLine.empty()) {
            outFile << newLine << endl;
        }
    }

    inFile.close();
    outFile.close();
}

int main() {
    removeComments("chap12_exercise5_t1.c", "chap12_exercise5_result.dat");
    return 0;
}