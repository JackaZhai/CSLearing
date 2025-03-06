#include <stdio.h>
#include <math.h>

int main() {
  const int n = 5;
  char A[n][n] = {
    {1, 5, 0, 22, 0},
    {7, 0, 33, 0, 0},
    {0, 55, 0, 9, 0},
    {0, 0, 0, 18, 0},
    {16, 0, 17, 0, 0}
  };

  // 记录三元矩阵的行数，即非零元素的行数
  int num = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (A[i][j] != 0) {
        num++;
      }
    }
  }

  // 分配内存以存储稀疏矩阵的三元组数据
  // 如果不太明白可以选中代码后点击 AI 解析
  int **B = (int **)malloc(num * sizeof(int*));
  int index = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (A[i][j] != 0) {
        // 分配存储非零元素的 行、列、和值
        B[index] = (int *)malloc(3 * sizeof(int));
        B[index][0] = i;
        B[index][1] = j;
        B[index][2] = A[i][j];
        index++;
      }
    }
  }

  // 打印压缩后的矩阵B
  printf("压缩后的矩阵B：\ni\tj\tv\t\n");
  for (int i = 0; i < num; i++) {
    printf("%d\t",  B[i][0]);
    printf("%d\t",  B[i][1]);
    printf("%d\t", B[i][2]);
    printf("\n");
  }
  printf("\n");

  return 0;
}