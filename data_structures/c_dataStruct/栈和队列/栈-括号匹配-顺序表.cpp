#include <iostream>

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


// 括号匹配函数
bool Bracket_Match(char str[], int n) {
  SqStack S;            // 创建一个栈
  Stack_Init(S);        // 初始化栈

  for (int i = 0; i < n; i++) {  // 遍历输入的字符数组
    if (str[i] == '(' || str[i] == '[' || str[i] == '{') {
      // 如果遇到左括号 (、[、{，则将其入栈
      Stack_Push(S, str[i]);
    } else {
      if (Stack_Empty(S)) {
        // 如果遇到右括号但栈为空，说明无法匹配，返回false
        return false;
      }

      char topElem;
      Stack_Pop(S, topElem); // 弹出栈顶元素，与当前右括号进行匹配

      // 检查栈顶元素与当前右括号是否匹配，不匹配则返回false
      if (str[i] == ')' && topElem != '(')
        return false;

      if (str[i] == ']' && topElem != '[')
        return false;

      if (str[i] == '}' && topElem != '{')
        return false;
    }
  }

  // 所有字符处理完毕后，如果栈为空，表示括号匹配成功
  return Stack_Empty(S);
}


int main() {
  char str[] = "{[()]}";
  int n = strlen(str);

  if (Bracket_Match(str, n)) {
    std::cout << "括号匹配成功" << std::endl;
  } else {
    std::cout << "括号匹配失败" << std::endl;
  }

  return 0;
}