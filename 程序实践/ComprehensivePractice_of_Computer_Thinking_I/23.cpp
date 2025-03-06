#include <stdio.h>

int main() {
    int startnum, n;  // 起始数字和方阵大小
    scanf("%d %d", &startnum, &n);
    int p[n][n];
    int count = startnum;  // 计数

    for (int i = 0; i < n; i++) {  // 处于第i列
        for (int j = 0; j <= i; j++) {  // 从第0行自上而下打印列
            p[j][i] = count;
            count++;
        }
        for (int j = i - 1; j >= 0; j--) {  // 到达第i行时，在该从右到左打印
            p[i][j] = count;
            count++;
        }
    }

    // 输出方阵，数字按列整齐对齐
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%4d", p[i][j]);  // 每个数字占用4个字符宽度
        }
        printf("\n");
    }

    return 0;
}
