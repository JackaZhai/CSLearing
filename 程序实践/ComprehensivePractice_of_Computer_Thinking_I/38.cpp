#include <iostream>
using namespace std;

int main() {
    int m, n;
    cin >> m >> n;

    int image1[100][100];
    int image2[100][100];
    int result[100][100];

    // 输入第一幅图像
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> image1[i][j];
        }
    }

    // 输入第二幅图像
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> image2[i][j];
        }
    }

    // 叠加图像
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (image1[i][j] == 0 && image2[i][j] == 0) {
                result[i][j] = 0;
            } else {
                result[i][j] = 1;
            }
        }
    }

    // 输出结果
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << result[i][j];
            if (j < n - 1) cout << " ";
        }
        cout << endl;
    }

    return 0;
}