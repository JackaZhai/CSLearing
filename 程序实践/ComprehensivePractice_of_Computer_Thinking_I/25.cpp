#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    int board[9][9];
    bool toBeCleared[9][9] = {false};
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }
    
    // 检查行
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m - 2; j++) {
            if (board[i][j] == board[i][j+1] && board[i][j+1] == board[i][j+2]) {
                toBeCleared[i][j] = toBeCleared[i][j+1] = toBeCleared[i][j+2] = true;
                int k = j + 3;
                while (k < m && board[i][k] == board[i][j]) {
                    toBeCleared[i][k] = true;
                    k++;
                }
                j = k - 1;
            }
        }
    }
    
    // 检查列
    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n - 2; i++) {
            if (board[i][j] == board[i+1][j] && board[i+1][j] == board[i+2][j]) {
                toBeCleared[i][j] = toBeCleared[i+1][j] = toBeCleared[i+2][j] = true;
                int k = i + 3;
                while (k < n && board[k][j] == board[i][j]) {
                    toBeCleared[k][j] = true;
                    k++;
                }
                i = k - 1;
            }
        }
    }
    
    // 输出结果
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (toBeCleared[i][j]) {
                cout << "0 ";
            } else {
                cout << board[i][j] << " ";
            }
        }
        cout << endl;
    }
    
    return 0;
}