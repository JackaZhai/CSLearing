#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPR_SIZE 100

// 函数用于返回操作符的优先级
int precedence(char c) {
  if (c == '^')
      return 3;
    else if (c == '/' || c == '*')
      return 2;
    else if (c == '+' || c == '-')
      return 1;
    else
      return -1; // 非操作符的情况
}

// 函数用于检查字符是否为操作符
int isOperator(char ch) {
  return (
    ch == '+'
    || ch == '-'
    || ch == '*'
    || ch == '/'
    || ch == '^'
  );
}

// 函数用于反转字符串
void reverseString(char *str) {
  int len = strlen(str);
  for (int i = 0; i < len / 2; i++) {
    char temp = str[i];
    str[i] = str[len - i - 1];
    str[len - i - 1] = temp;
  }
}

// 函数用于替换括号，将'('替换为')'，将')'替换为'('
void replaceParentheses(char *str) {
  int len = strlen(str);
  for (int i = 0; i < len; i++) {
    if (str[i] == '(') {
      str[i] = ')';
    } else if (str[i] == ')') {
      str[i] = '(';
    }
  }
}


// 函数用于将中缀表达式转换为后缀表达式
bool infixToPostfix(char* infix, char* postfix) {
  int i, j;
  int len = strlen(infix);
  char stack[MAX_EXPR_SIZE];
  int top = -1;

  for (i = 0, j = 0; i < len; i++) {
    if (infix[i] == ' ' || infix[i] == '\t')
      continue;

    // 如果扫描到的字符是操作数，将其添加到后缀表达式
    if (
      (infix[i] >= 'a' && infix[i] <= 'z')
      || (infix[i] >= 'A' && infix[i] <= 'Z')
      || (infix[i] >= '0' && infix[i] <= '9')
    ) {
      postfix[j++] = infix[i];
    }
    // 如果扫描到'('，将其压入栈中
    else if (infix[i] == '(') {
      stack[++top] = infix[i];
    }
    // 如果扫描到')'，则弹出栈中的元素并添加到输出字符串，直到找到'('
    else if (infix[i] == ')') {
      // 当扫描到的字符为')'时，需要将栈中的操作符弹出并添加到后缀表达式中，直到遇到'('
      while (top > -1 && stack[top] != '(') {
        postfix[j++] = stack[top--];
      }

      // 如果在上述循环结束后，栈顶仍然不是'('，则括号不匹配，返回false
      if (top == -1 || stack[top] != '(') {
        return false; // 括号不匹配的情况
      } else {
        top--; // 如果栈顶是'('，则将'('弹出栈
      }
    }
    // 如果扫描到操作符，将其压入栈中，但需要根据优先级进行处理
    else if (isOperator(infix[i])) {
      // 当栈不为空且栈顶操作符的优先级大于等于当前扫描到的操作符时，将栈顶操作符弹出并添加到后缀表达式中
      while (top > -1 && precedence(stack[top]) >= precedence(infix[i]))
        postfix[j++] = stack[top--];
      stack[++top] = infix[i];
    }
  }

  // 弹出栈中剩余的元素
  while (top > -1) {
    if (stack[top] == '(') {
      return false; // 括号不匹配的情况
    }
    postfix[j++] = stack[top--];
  }
  postfix[j] = ' ';
  return true;s
}


// 函数用于将中缀表达式转换为前缀表达式
void infixToPrefix(char *infix, char *prefix) {
  int len = strlen(infix);

  // 1. 反转中缀表达式
  reverseString(infix);

  // 2. 替换括号
  replaceParentheses(infix);

  // 3. 获取后缀表达式（这里实际上调用了中缀转后缀的函数）
  infixToPostfix(infix, prefix);

  // 4. 反转后缀表达式，得到前缀表达式
  reverseString(prefix);
}


// 主函数
int main() {
  char infix[MAX_EXPR_SIZE] = "A+B*(C-D)-E/F";
  // char infix[MAX_EXPR_SIZE] = "((15/(7-(1+1)))*3)-(2+(1+1))";
  printf("中缀表达式: %s\n", infix);
  
  char postfix[MAX_EXPR_SIZE];
  char prefix[MAX_EXPR_SIZE];
  
  // 调用中缀转后缀函数
  infixToPostfix(infix, postfix);
  printf("后缀表达式(左优先): %s\n", postfix);

  // 调用中缀转前缀函数
  infixToPrefix(infix, prefix);
  printf("前缀表达式(右优先): %s\n", prefix);
  return 0;
}