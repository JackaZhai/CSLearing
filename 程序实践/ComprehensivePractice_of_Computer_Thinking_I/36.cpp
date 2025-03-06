#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    int arr[100];
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    int max_length = 1;
    int current_length = 1;
    for (int i = 1; i < N; i++) {
        if (arr[i] > arr[i - 1]) {
            current_length++;
        } else {
            current_length = 1;
        }
        if (current_length > max_length) {
            max_length = current_length;
        }
    }
    cout << max_length << endl;
    return 0;
}