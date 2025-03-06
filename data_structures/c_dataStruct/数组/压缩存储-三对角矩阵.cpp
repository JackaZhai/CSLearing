#include <stdio.h>
#include <math.h>

int main() {
  const int n = 5;
  char A[n][n] = {
    {'a', 'c', '0', '0', '0'},
    {'b', 'a', 'c', '0', '0'},
    {'0', 'b', 'a', 'c', '0'},
    {'0', '0', 'b', 'a', 'c'},
    {'0', '0', '0', 'b', 'a'}
  };

  // 压缩存储
  char B[3 * n - 2];
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      // 三对角内 进行压缩存储
      if (abs(i - j) <= 1) {
        int k = 2 * i + j - 3;
        B[k] = A[i - 1][j - 1];
      }
      // else 不在三对角内，不进行操作
    }
  }

  // 打印压缩后的矩阵B
  printf("压缩后的矩阵B：\n");
  for (int i = 0; i < 3 * n - 2; i++) {
    printf("%c ", B[i]);
  }
  printf("\n");

  return 0;
}