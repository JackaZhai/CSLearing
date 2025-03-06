#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, num;
    cin >> N;
    vector<int> evenNumbers;
    for (int i = 0; i < N; i++) {
        cin >> num;
        if (num % 2 == 0) {
            evenNumbers.push_back(num);
        }
    }

    sort(evenNumbers.begin(), evenNumbers.end(), greater<int>());

    for (int i = 0; i < evenNumbers.size(); i++) {
        cout << evenNumbers[i];
        if (i != evenNumbers.size() - 1) {
            cout << " ";
        }
    }
    cout << endl;

    return 0;
}