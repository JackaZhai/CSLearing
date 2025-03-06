#include <stdio.h>

// 存储方向，1 下三角，2 上三角
#define DIRECTION 1

int main() {
  char A[3][3] = {
    {'a', 'b', 'b'},
    {'b', 'a', 'b'},
    {'b', 'b', 'a'}
  };

  // 压缩存储
  char B[6];
  for (int i = 1; i <= 3; i++) {
    for (int j = 1; j <= 3; j++) {
      int k;
      // 如果当前方式为【存储下三角】，则上三角元素跳过
      if (DIRECTION == 1 && i < j) {
        continue;
      }
      // 如果当前方式为【存储上三角】，则下三角元素跳过
      if (DIRECTION == 2 && i > j) {
        continue;
      }

      // 下三角和主对角线
      if (i >= j) {
        k = i * (i - 1) / 2 + j -1;
      }
      if (i < j) {
        k = j * (j - 1) / 2 + i - 1;
      }
      B[k] = A[i - 1][j - 1];
    }
  }

  // 打印压缩后的矩阵B
  printf("压缩后的矩阵B：\n");
  for (int i = 0; i < 6; i++) {
    printf("%c ", B[i]);
  }
  printf("\n");

  return 0;
}s