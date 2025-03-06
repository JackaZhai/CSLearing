#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN 255

typedef struct {
  char ch[MAX_LEN];
  int length;
} SString;



/**
 * 简单模式匹配，模式下标从 1 开始
 * @param S 被搜索的字符串
 * @param T 模式字符串
 * @return 如果找到了模式 T 在字符串 S 中的位置，返回模式在 S 中的起始位置（下标从 1 开始），否则返回 0
 */
int Index (SString S, SString T) {
 int i = 1, j = 1; // 初始化主串 S 和模式串 T 的下标

 // 使用循环遍历主串和模式串
 while (i <= S.length && j <= T.length) {
   if (S.ch[i] == T.ch[j]) {
     ++i; // 如果字符匹配，主串下标向后移动
     ++j; // 模式串下标向后移动
   } else {
     i = i - j + 2; // 如果字符不匹配，主串下标回溯，并且移动到下一个位置
     j = 1; // 模式串下标重置为 1
   }
 }

 // 如果模式串完全匹配了主串，则返回模式串在主串中的起始位置
 if (j > T.length) return i - T.length;
 else return 0; // 否则返回 0 表示未找到匹配
}



/**
 * 下标从 0 开始的模式匹配，0 号位不用于存储 length，则可以存储字符
 * @param S 被搜索的字符串
 * @param T 模式字符串
 * @return 如果找到了模式 T 在字符串 S 中的位置，返回模式在 S 中的起始位置（下标从 0 开始），否则返回 -1
 */
 int IndexBy0(SString S, SString T) {
   int i = 0, j = 0; // 初始化主串 S 和模式串 T 的下标
 
   // 使用循环遍历主串和模式串
   while (i < S.length && j < T.length) {
     if (S.ch[i] == T.ch[j]) {
       ++i; // 如果字符匹配，主串下标向后移动
       ++j; // 模式串下标向后移动
     } else {
       i = i - j + 1; // 如果字符不匹配，主串下标回溯，并且移动到下一个位置
       j = 0; // 模式串下标重置为 0
     }
   }
 
   // 如果模式串完全匹配了主串，则返回模式串在主串中的起始位置
   if (j >= T.length) return i - T.length;
   else return -1; // 否则返回 -1 表示未找到匹配
 }



int main () {
  SString S, T;
  S.ch[1] = 'a';
  S.ch[2] = 'b';
  S.ch[3] = 'a';
  S.ch[4] = 'b';
  S.ch[5] = 'c';
  S.ch[6] = 'a';
  S.ch[7] = 'b';
  S.ch[8] = 'c';
  S.ch[9] = 'a';
  S.ch[10] = 'c';
  S.ch[11] = 'b';
  S.ch[12] = 'a';
  S.ch[13] = 'b';
  S.length = 13;

  T.ch[1] = 'a';
  T.ch[2] = 'b';
  T.ch[3] = 'c';
  T.ch[4] = 'a';
  T.ch[5] = 'c';
  T.length = 5;

  int result = Index(S, T);
  if (result != 0) {
    printf("下标从1开始的模式匹配模式T在字符串S中的位置是：%d\n", result);
  } else {
    printf("下标从1开始的模式匹配模式T未在字符串S中找到\n");
  }

  // 下标从0开始
  SString S1, T1;
  S1.ch[0] = 'a';
  S1.ch[1] = 'a';
  S1.ch[2] = 'a';
  S1.ch[3] = 'b';
  S1.ch[4] = 'c';
  S1.length = 5;

  T1.ch[0] = 'a';
  T1.ch[1] = 'b';
  T1.length = 2;

  int result1 = IndexBy0(S1, T1);
  if (result1 != -1) {
    printf("下标从0开始的模式匹配模式T1在字符串S1中的位置是：%d\n", result1);
  } else {
    printf("下标从0开始的模式匹配模式T1未在字符串S1中找到\n");
  }

}