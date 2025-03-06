#include <stdio.h>
#include <stdlib.h>

int main () {
  // 声明一个3x3的数组 A
  int A[3][3] = {
    {0, 1, 2},
    {10, 11, 12},
    {20, 21, 22}
  };

  // 使用嵌套循环迭代数组的每个元素
  for (int row = 0; row < 3; row++) {
    for (int col = 0; col < 3; col++) {
      // 打印数组元素位置，\t 是制表符起到对齐作用
      printf("A[%d][%d]\t", row, col);
    }
    // 在每行结束时打印一个换行符
    printf("\n");
  }
  return 0;
}