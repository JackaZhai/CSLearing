#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    int size = 2 * N - 1;
    int matrix[20][20]; // 最大边长为17

    for (int layer = 0; layer < N; layer++) {
        int num = layer + 1;
        for (int i = layer; i < size - layer; i++) {
            for (int j = layer; j < size - layer; j++) {
                matrix[i][j] = num;
            }
        }
    }

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << matrix[i][j];
        }
        cout << endl;
    }

    return 0;
}