#include <iostream>
#include <stdio.h>
#include <stdlib.h>

// 栈 顺序表
// 定义栈中元素的最大个数
#define MAX_SIZE 10

typedef struct {
  char data[MAX_SIZE];
  int top;
} SqStack;


// 初始化栈
void Stack_Init(SqStack &S) {
  S.top = -1; // 初始化栈顶指针为-1，表示栈为空
}


// 判断栈是否为空
bool Stack_Empty(SqStack S) {
  return S.top == -1;
}


// 判断栈是否已满
bool Stack_Full(SqStack S) {
  return S.top == MAX_SIZE - 1;
}


// 新元素入栈
bool Stack_Push(SqStack &S, char x) {
  if (Stack_Full(S)) {
    std::cout << "栈已满，无法入栈" << std::endl;
    return false;
  } else {
    S.data[++S.top] = x; // 将元素入栈，并更新栈顶指针
    return true;
  }
}


// 栈顶元素出栈，x为出栈的栈顶元素
bool Stack_Pop(SqStack &S, char &x) {
  if (Stack_Empty(S)) {
    std::cout << "栈为空，无法出栈" << std::endl;
    return false;
  } else {
    x = S.data[S.top--]; // 将栈顶元素出栈，并更新栈顶指针
    return true;
  }
}


int main() {
  SqStack stack;
  Stack_Init(stack);

  // 测试入栈操作
  for (char c = 'A'; c <= 'J'; ++c) {
    if (!Stack_Push(stack, c)) {
      std::cout << "入栈失败，栈已满" << std::endl;
      break;
    }
  }

  // 测试出栈操作
  char x;
  while (Stack_Pop(stack, x)) {
    std::cout << "出栈元素: " << x << std::endl;
  }

  return 0;
}

