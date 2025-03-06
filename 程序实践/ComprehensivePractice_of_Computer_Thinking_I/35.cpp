#include <iostream>
using namespace std;

int main() {
    int m, n;
    cin >> m >> n;
    int matrix[100][100];
    int sum = 0;

    // 读取矩阵元素
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    // 计算边缘元素之和
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 || i == m -1 || j == 0 || j == n -1) {
                sum += matrix[i][j];
            }
        }
    }

    cout << sum << endl;

    return 0;
}