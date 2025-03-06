#include <stdio.h>
#include <stdlib.h>

typedef struct LNode {
  int data;
  struct LNode *next;
} LNode, *LinkStack;

// 初始化栈
bool Stack_Init(LinkStack &pStack) {
  pStack = NULL;
  return true;
}

// 判断栈是否为空
bool Stack_Empty(LinkStack pStack) {
  return pStack == NULL;
}

// 获取栈有效数据节点个数
int Stack_Length(LinkStack pStack) {
  int length = 0;
  LNode *current = pStack;
  while (current != NULL) {
    length++;
    current = current->next;
  }
  return length;
}

// 创建栈
LinkStack Stack_Create(LinkStack &pStack) {
  LNode *pTemp;
  int x;
  scanf("%d", &x);
  while (x != 999) {
    pTemp = (LNode *)malloc(sizeof(LNode));
    pTemp->data = x;
    pTemp->next = pStack;
    pStack = pTemp;
    scanf("%d", &x);
  }
  return pStack;
}


// 新元素入栈
bool Stack_Push(LinkStack &pStack, int e) {
  LNode *pTemp = (LNode *)malloc(sizeof(LNode));
  pTemp->data = e;
  pTemp->next = pStack;
  pStack = pTemp;
  return true;
}


// 出栈
bool Stack_Pop(LinkStack &pStack, int &e) {
  if (pStack == NULL) return false;
  LNode *p = pStack;
  e = p->data;
  pStack = pStack->next;
  free(p);
  return true;
}


// 返回第一个
LNode *Stack_Get_Top(LinkStack pStack) {
  return pStack;
}


// 打印栈所有值
void Stack_Show(LinkStack pStack) {
  LNode *node = pStack;
  printf("栈值：");
  while (node != NULL) {
    printf("%d、", node->data);
    node = node->next;
  }
  printf("\n");
}


int main() {
  int i = -1;
  LinkStack pStack;
  Stack_Init(pStack);
  printf("栈判空：%s\n", Stack_Empty(pStack) ? "空" : "非空");

  Stack_Push(pStack, 1);
  Stack_Push(pStack, 2);
  Stack_Push(pStack, 3);
  Stack_Push(pStack, 4);
  Stack_Show(pStack);

  Stack_Pop(pStack, i);
  printf("出栈：%d\n", i);
  Stack_Show(pStack);

  Stack_Pop(pStack, i);
  printf("出栈：%d\n", i);
  Stack_Show(pStack);

  Stack_Pop(pStack, i);
  printf("出栈：%d\n", i);
  Stack_Show(pStack);

  printf("栈长度：%d\n\n", Stack_Length(pStack));

  printf("栈判空：%s\n", Stack_Empty(pStack) ? "空" : "非空");
  return 0;
}