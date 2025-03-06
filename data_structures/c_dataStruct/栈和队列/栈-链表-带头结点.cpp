#include <stdio.h>
#include<stdlib.h>

typedef struct LNode {
  int data;
  struct LNode * next;
} LNode, *LinkStack;

// 初始化栈
bool Stack_Init (LinkStack &pStack) {
  pStack = (LNode *) malloc(sizeof(LNode));
  if (pStack == NULL) return false;
  pStack->next = NULL;
  // 头结点存储栈长度
  pStack->data = 0;
  return true;
}

// 判断栈是否为空
bool Stack_Empty (LinkStack pStack) {
  // 或 pStack->data == 0;
  return pStack->next == NULL;
}

// 获取栈有效数据节点个数
int Stack_Length (LinkStack pStack)
{
  return pStack->data;
}


// 创建栈
LinkStack Stack_Create(LinkStack &pStack) {
  LNode *pTemp; int x;
  scanf("%d", &x);
  while (x != 999) {
    pTemp = (LNode *)malloc(sizeof(LNode));
    pTemp->data = x;
    pTemp->next = pStack->next;
    pStack->next = pTemp;
    pStack->data += 1;
    scanf("%d", &x);
  }
  return pStack;
}


// 新元素入栈
bool Stack_Push(LinkStack &pStack, int e) {
  LNode *pTemp = (LNode *)malloc(sizeof(LNode));
  pTemp->data = e;
  pTemp->next = pStack->next;
  pStack->next = pTemp;
  pStack->data += 1;
  return true;
}


// 出栈
bool Stack_Pop (LinkStack &pStack, int &e) {
  if (pStack->next == NULL) return false;
  LNode *p = pStack->next; // 待删除结点
  pStack->next = p->next;
  e = p->data;
  free(p);
  pStack->data -= 1;
  return true;
}


// 返回第一个
LNode* Stack_Get_Top (LinkStack pStack) {
  return pStack->next;
}


// 打印栈所有值
void Stack_Show (LinkStack pStack) {
  LNode *node = pStack->next;
  printf("栈值：");
  while (node != NULL) {
    printf("%d、", node->data);
    node = node->next;
  }
  printf("\n");
}

int main () {
  int i = -1;
  LinkStack pStack;
  Stack_Init(pStack);
  printf("栈判空：%s\n", Stack_Empty(pStack) ? "空" : "非空");

  Stack_Create(pStack);
  Stack_Show(pStack);
  printf("栈长度：%d\n\n", Stack_Length(pStack));

  printf("入栈：0\n");
  Stack_Push(pStack, 0);
  Stack_Show(pStack);
  printf("栈长度：%d\n\n", Stack_Length(pStack));
  
  printf("入栈：99\n");
  Stack_Push(pStack, 99);
  Stack_Show(pStack);
  printf("栈长度：%d\n\n", Stack_Length(pStack));

  Stack_Pop(pStack, i);
  printf("出栈：%d\n", i);
  Stack_Show(pStack);
  printf("栈长度：%d\n\n", Stack_Length(pStack));
  
  Stack_Pop(pStack, i);
  printf("出栈：%d\n", i);
  Stack_Show(pStack);
  printf("栈长度：%d\n\n", Stack_Length(pStack));

  LNode *top = Stack_Get_Top(pStack);
  printf("获取栈顶元素：%d\n\n", top == NULL ? -1 : top->data);

  printf("栈判空：%s\n", Stack_Empty(pStack) ? "空" : "非空");
  return 0;
}