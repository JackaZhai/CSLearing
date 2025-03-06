#include <stdio.h>

// 常量方向，1 上三角，2 下三角
#define DIRECTION 2

int main() {
  const int n = 3;
  char A[n][n] = {
    {'a', 'c', 'c'},
    {'b', 'a', 'c'},
    {'b', 'b', 'a'}
  };

  // 压缩存储
  char B[2 * n + 1];
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      int k;
      // 如果常量在【上三角】，则上三角元素跳过
      if (DIRECTION == 1 && i < j) {
        continue;
      } else if (DIRECTION == 1 && i >= j) {
       // 存储 下三角元素和主对角线元素
        k = i * (i - 1) / 2 + j - 1;
      }

      // 如果常量在【下三角】，则下三角元素跳过
      if (DIRECTION == 2 && i > j) {
        continue;
      } else if (DIRECTION == 2 && i <= j) {
        // 存储 上三角元素和主对角元素
        k = ((i - 1) * (2 * n - i + 2)) / 2 + (j - i);
      }

      B[k] = A[i - 1][j - 1];
    }
  }
  // 存储常量，常量在 上三角区
  if (DIRECTION == 1) {
    B[2 * n] = A[0][1];
  }
  // 常量在 下三角区
  if (DIRECTION == 2) {
    B[2 * n] = A[1][0];
  }

  // 打印压缩后的矩阵B
  printf("压缩后的矩阵B：\n");
  for (int i = 0; i < 2 * n + 1; i++) {
    printf("%c ", B[i]);
  }
  printf("\n");

  return 0;
}