#include <iostream>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
// 栈 顺序表
// 定义栈中元素的最大个数
#define MAX_SIZE 10

//结构体
typedef struct {
  char data[MAX_SIZE];
  int top;
}SqStack;

// 初始化栈
void Stack_Init(SqStack &s){
  s.top = -1;
}

// 判断栈是否为空
bool Stack_Empty(SqStack s){
  return s.top == -1;
}

// 判断栈是否已满
bool Stack_Full(SqStack s){
  return s.top == MAX_SIZE-1
}

// 新元素入栈
bool Stack_Push(SqStack &s,char e){
  if (!Stack_Full(s))  {
    return false;
  }else{
  s.data[++s.top] = e;
  return true;
  }
}

// 栈顶元素出栈，x为出栈的栈顶元素
bool Stack_Push(SqStack &s,char e){
  if (!Stack_Empty(s))  {
    return false;
  }else{
    s.data[s.top--] = e;
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

// 栈 链表 带头节点

//结构体
typedef struct LNode {
  int data;
  struct LNode * next;
}LNode, *LinkStack;

// 初始化栈
void Stack_Init(LinkStack &pStack){
  pStack = (LNode*)malloc(sizeof(LNode));
  pStack ->next=nullptr;
  pStack ->data=0;// 头结点存储栈长度
}

// 判断栈是否为空
bool Stack_Empty(LinkStack pStack){
  return pStack ->data==0;
}

// 获取栈有效数据节点个数
int Stack_Length (LinkStack pStack){
  return pStack->data;
}


// 创建栈
void Stack_Create(LinkStack &pStack){
  LNode *pTemp; int x;
  scanf("%d",&x);
  while (x!=999){
    pTemp ->data = x;
    pTemp ->next= pStack ->next;
    pStack ->next = pTemp;
    pStack->data ++;
    scanf("%d",&x);
  }
}

// 新元素入栈
void Stack_Push(LinkStack &pStack,int e){
  LNode *pTemp; 
  pTemp ->data = e;
  pTemp ->next= pStack ->next;
  pStack ->next = pTemp;
  pStack->data ++;
}

// 出栈
int Stack_Push(LinkStack &pStack){
  LNode *p = pStack ->next;
  pStack ->next=p -> next;
  int e = p ->data;
  free(p);
  pStack ->data--;
  return e;
}

// 返回第一个
LNode* Stack_Get_Top (LinkStack pStack) {
  return pStack->next;
}


// 打印栈所有值
void Stack_Show(LinkStack &pStack) {
    LNode *p = pStack->next;  // 假设 pStack 是头节点
    while (p != nullptr) {    // 逐个遍历直到链表末尾
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
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

// 栈 链表 不带头结点

//struct
typedef struct LNode{
  int data;
  struct LNode *next;
}LNode,*LinkStack;

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



// 新元素入栈



// 出栈



// 返回第一个



// 打印栈所有值



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


// 队列 顺序表
#define MAX_SIZE 100
typedef int ElemType; // 假设队列中存储的元素类型是整数

//struct
typedef struct 
{
  ElemType data[MaxSize];
  int front,rear;
} SqQueue;

// 初始化队列
void Queue_Init(SqQueue &q){
  q.front =  q.rear =0;
}

// 判断队列是否为空
bool Queue_IsEmpty(SqQueue q){
  return q.front ==  q.rear;
}

// 判断队列是否已满
int Queue_IsFull(SqQueue &Q) {
  return Q.rear == MAX_SIZE - 1;
}


// 入队操作
int Queue_En(SqQueue &q,ElemType x){
  if (Queue_IsFull){
    printf("队列已满,无法入队");
    return 0;
  }
  q.data[q.rear] = x;
  q.rear ++;
  return 1;
}


// 出队操作
int Queue_De(SqQueue &Q, ElemType &x) {
  if (Q.front == Q.rear) {
    printf("队列为空，无法出队\n");
    return 0; // 出队失败
  }
  x = Q.data[Q.front];
  Q.front++; // 队头指针增加
  return 1; // 出队成功
}


// 输出队列中的元素
void Queue_Print(SqQueue &Q) {
  int i;
  for (i = Q.front; i < Q.rear; i++) {
    printf("%d ", Q.data[i]);
  }
  printf("\n");
}


int main() {
  SqQueue Q;
  Queue_Init(Q);

  Queue_En(Q, 1);
  Queue_En(Q, 2);
  Queue_En(Q, 3);

  printf("队列元素: ");
  Queue_Print(Q);

  ElemType x;
  Queue_De(Q, x);
  printf("出队元素：%d\n", x);

  printf("队列元素: ");
  Queue_Print(Q);

  return 0;
}


// 队列 链表 带头借点
//struct 链表和队列


// 初始化队列（带头结点）


// 判断队列是否为空


// 获取队列有效数据节点个数



// 创建队列



// 新元素入队



// 出队


// 打印队列所有值

int main () {
  int i = -1;
  LinkQueue Q;
  Queue_Init(Q);
  printf("队列判空：%s\n", Queue_Empty(Q) ? "空" : "非空");

  Queue_Create(Q);
  Queue_Show(Q);
  printf("队列长度：%d\n\n", Queue_Length(Q));

  printf("入队列：0\n");
  Queue_En(Q, 0);
  Queue_Show(Q);
  printf("队列长度：%d\n\n", Queue_Length(Q));
  
  printf("入队列：99\n");
  Queue_En(Q, 99);
  Queue_Show(Q);
  printf("队列长度：%d\n\n", Queue_Length(Q));

  Queue_De(Q, i);
  printf("出队列值：%d\n", i);
  Queue_Show(Q);
  printf("队列长度：%d\n\n", Queue_Length(Q));
  
  Queue_De(Q, i);
  printf("出队列值：%d\n", i);
  Queue_Show(Q);
  printf("队列长度：%d\n\n", Queue_Length(Q));

  printf("队列判空：%s\n", Queue_Empty(Q) ? "空" : "非空");
  return 0;
}


// 队列 链表 不带头结点
//struct double


// 初始化队列（不带头结点）


// 判断队列是否为空


// 获取队列有效数据节点个数


// 创建队列


// 新元素入队



// 出队



// 打印队列所有值



int main() {
  int i = -1;
  LinkQueue Q;
  Queue_Init(&Q);
  printf("队列判空：%s\n", Queue_Empty(&Q) ? "空" : "非空");


  Queue_En(&Q, 10);
  Queue_En(&Q, 20);
  Queue_En(&Q, 30);
  Queue_En(&Q, 40);
  Queue_En(&Q, 50);
  Queue_Show(&Q);
  printf("队列长度：%d\n\n", Queue_Length(&Q));

  Queue_De(&Q, &i);
  printf("出队列值：%d\n", i);
  Queue_Show(&Q);
  printf("队列长度：%d\n\n", Queue_Length(&Q));

  Queue_De(&Q, &i);
  printf("出队列值：%d\n", i);
  Queue_Show(&Q);
  printf("队列长度：%d\n\n", Queue_Length(&Q));

  printf("队列判空：%s\n", Queue_Empty(&Q) ? "空" : "非空");
  return 0;
}


// 队列 顺序表 循环队列 
#define ElemType int
#define MAX_SIZE 10
//struct


// 初始化队列


// 检查队列是否为空



// 入队操作，将元素 x 添加到队列尾部



// 出队操作，将队列头部元素存储在 x 中，并从队列中删除



int main() {
  SqQueue myQueue;
  Queue_Init(myQueue); // 初始化队列

  // 入队操作
  for (int i = 1; i <= 5; ++i) {
    Queue_En(myQueue, i * 10);
  }

  // 出队操作
  while (!Queue_IsEmpty(myQueue)) {
    ElemType frontElem;
    Queue_De(myQueue, frontElem);
    printf("出队元素：%d\n", frontElem);
  }

  return 0;
}


// 栈 括号匹配 顺序表
// 定义栈中元素的最大个数
#define MAX_SIZE 10
// struct


// 初始化栈


// 判断栈是否为空


// 判断栈是否已满


// 新元素入栈


// 栈顶元素出栈，x为出栈的栈顶元素



// 括号匹配函数



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


// 栈 表达式计算 顺序表
#define MAX_EXPR_SIZE 100

// 函数用于返回操作符的优先级


// 函数用于检查字符是否为操作符

// 函数用于反转字符串


// 函数用于替换括号，将'('替换为')'，将')'替换为'('



// 函数用于将中缀表达式转换为后缀表达式


// 函数用于将中缀表达式转换为前缀表达式



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


// 队列 双端队列
#define MAX_SIZE 100  // 双端队列的最大容量

// 双端队列结构体


// 初始化双端队列


// 判断双端队列是否为空


// 判断双端队列是否已满



// 在队头插入元素


// 在队尾插入元素


// 从队头删除元素


// 从队尾删除元素

// 打印值



int main() {
  Deque Q;
  Deque_Init(Q);

  // 在队头插入元素
  Deque_InsertFront(Q, 1);
  Deque_InsertFront(Q, 2);

  // 在队尾插入元素
  Deque_InsertRear(Q, 3);
  Deque_InsertRear(Q, 4);

  Deque_print(Q);

  // 从队头删除元素
  int frontElement = Deque_DeleteFront(Q);
  printf("从队头删除元素: %d\n", frontElement);
  Deque_print(Q);

  // 从队尾删除元素
  int rearElement = Deque_DeleteRear(Q);
  printf("从队尾删除元素: %d\n", rearElement);
  Deque_print(Q);

  return 0;
}


// 队列 层次遍历
// 树存储结构体


// 循环队列算法，辅助完成二叉树层次遍历
#define MaxSize 50   // 定义队列中元素的最大个数
//队列结构体


// 初始化队列（带头结点）


// 判断队列是否为空


// 入队

// 出队



// 通过给定数组创建二叉树，0为空结点
// nums 为数组、len 为数组长度、i 为当前数组下标



// 先序遍历: 根左右(NLR)



// 中序遍历: 左根右(LNR)



// 后序遍历: 左根右(LRN)


// 层次遍历



int main() {
  char nums[11] = {1, 2, 3, 0, 4, 0, 5, 0, 0, 6, 0};
  BiTree tree = BiTree_Create(nums, 11, 0);
  printf("先序遍历：");
  Order_Pre(tree);
  printf("\n");

  printf("中序遍历：");
  Order_In(tree);
  printf("\n");

  printf("后序遍历：");
  Order_Post(tree);
  printf("\n");

  // 层次遍历需要借助队列实现
  printf("层次遍历: ");
  Order_Level(tree);

  return 0;
}