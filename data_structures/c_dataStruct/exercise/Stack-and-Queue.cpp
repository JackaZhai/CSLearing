#include <iostream>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 栈 顺序表
// 定义栈中元素的最大个数
#define MAX_SIZE 10

//结构体

typedef struct {
  char data[Max_Size];
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
  return s.top == MAX_SIZE -1;
}

// 新元素入栈

bool Stack_Push(SqStack &s,int e){
  if (Stack_Full(s)){
    cout<<"栈满,无法入栈"<<endl;
    return false;
  }else{
    s.data[++s.top] = c;
    return true;
  }
}




// 栈顶元素出栈，x为出栈的栈顶元素

bool Stack_Pop(SqStack &s,int &e){
   if (Stack_Empty(s)){
    cout<<"栈空,无法出栈"<<endl;
    return false;
  }else{
    e = s.data[s.top--];
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
typedef struct LNode{
  int data;
  struct LNode *next;
}LNode,*LinkStack;

// 初始化栈
bool Stack_Init (LinkStack &pStack) {
  pStack = (LNode*)malloc(sizeof(LNode));
  if (pStack==null) return false;
  pStack ->next=nullptr;
  pStack ->data = 0;
  return true;
}

// 判断栈是否为空

bool Stack_Empty(LinkStack pStack){
  return pStack ->data==0;
}


// 获取栈有效数据节点个数

int Stack_Length(LinkStack pStack){
  return pStack ->data;
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

void Stack_Push(LinkStack &pStack,int c){
  LNode *p = (LNode *)malloc(sizeof(LNode));
  p ->data = c;
  p ->next = pStack ->next;
  pStack ->next = p;
  pStack ->data ++;
  return;
}

// 出栈

void Stack_Pop(LinkStack &pStack,int &c){
  LNode *p;
  p = pStack ->next;
  c = p ->data;
  pStack ->next =p ->next ;
  pStack ->data --;
  free(p);
  return;
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

// 栈 链表 不带头结点

//struct

typedef struct LNode{
  int data;
  struct LNode *next;
}LNode,*LinkStack;

// 初始化栈

bool Stack_Init (LinkStack &pStack) {
  pStack =nullptr;
  return true;
}

// 判断栈是否为空

bool Stack_Empty(LinkStack pStack){
  return pStack == NULL;

}

// 获取栈有效数据节点个数

int Stack_Length(LinkStack pStack){
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
  LNode *pTemp; int x;
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
LNode* Stack_Get_Top (LinkStack pStack) {
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


// 队列 顺序表
#define MAX_SIZE 100

typedef int ElemType; // 假设队列中存储的元素类型是整数

//struct

typedef struct {
  ElemType data[MAX_SIZE];
  int front,rear;
}SqQueue;

// 初始化队列
void Queue_Init(SqQueue &q){
  q.front = q.rear = 0;
}

// 判断队列是否为空

bool Queue_IsEmpty(SqQueue q){
  return q.front == q.rear;
}

// 判断队列是否已满

bool Queue_IsFull(SqQueue &q) {
  return q.rear == MAX_SIZE - 1;
}


// 入队操作

void Queue_En(SqQueue &q, int e){
  if (q.rear == MAX_SIZE - 1){
    cont<<"队列已满,无法入队"<<endl;
    return;
  }else{
    q.data[q.rear] =e;
    q.rear++;
    return;
  }
}


// 出队操作

int Queue_De(SqQueue &Q, ElemType &x) {
  if (Q.front == Q.rear) {
    printf("队列为空，无法出队\n");
    return 0; 
  }
  x = Q.data[Q.front];
  Q.front++; // 队头指针增加
  return 1; // 出队成功
}


// 输出队列中的元素

void Queue_Print(SqQueue &q){
  int i;
  for (i = q.front;i<q.rear;i++){
    printf("%d ", Q.data[i]);
  }
  print("\n");
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

typedef struct LNode{
  int data;
  struct LNode *next;
}LNode;
typedef struct {
  LNode * front,* rear;
  int len;
}LinkQueue;

// 初始化队列（带头结点）

void Queue_Init (LinkQueue &q){
  q.front= q.rear = (LNode*)malloc(sizeof(LNode));
  q.front ->next = nullptr;
  q.len =0;
  return;
}

// 判断队列是否为空

bool Queue_Empty(LinkQueue q){
  return q.front ==q.rear;
}

// 获取队列有效数据节点个数

int Queue_Length(LinkQueue q){
  return q.len;
}


// 创建队列

void Queue_Create(LinkQueue &q){
  LNode *pTemp;int x;
  scanf("%d",&x);
  while (x!=999){
    pTemp=(LNode*)malloc(sizeof(LNode));
    pTemp ->data =x;
    pTemp ->next=nullptr;
    q.rear ->next =pTemp;
    q.rear = pTemp;
    q.len++;
    scanf("%d",&x);
  }
  return q;
}


// 新元素入队

void Queue_En(LinkQueue &q,int e){
  LNode *pTemp = (LNode*)malloc(sizeof(LNode));
  pTemp ->data=e;
  pTemp ->next = nullptr;
  q.rear ->next =pTemp;
  q.rear = pTemp;
  q.len ++;
  return;
}


// 出队
bool Queue_De (LinkQueue &Q, int &e) {
  if (Q.front == Q.rear) return false;
  LNode *p = Q.front->next; // 待删除结点
  Q.front->next = p->next;
  e = p->data;
  if (Q.rear == p)  // 删除的为最后一个结点
    Q.rear = Q.front;
  free(p);
  Q.len -= 1;
  return true;
}

// 打印队列所有值
void Queue_Show (LinkQueue Q) {
  LNode *node = Q.front->next;
  printf("队列值：");
  while (node != NULL) {
    printf("%d、", node->data);
    node = node->next;
  }
  printf("\n");
}

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
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct LNode {
  int data;
  struct LNode* next;
} LNode;

typedef struct {
  LNode* front; // 队头
  LNode* rear;  // 队尾
  int len;    // 当前队列的成员数
} LinkQueue;

// 初始化队列（不带头结点）

bool Queue_Init(LinkQueue* Q) {
  Q->front = Q->rear = NULL;
  Q->len = 0;
  return true;
}

// 判断队列是否为空

bool Queue_Empty(LinkQueue* Q) {
  return Q->front == NULL;
}

// 获取队列有效数据节点个数

int Queue_Length(LinkQueue* Q) {
  return Q->len;
}

// 创建队列
void Queue_Create(LinkQueue* Q) {
  int x;
  scanf("%d", &x);
  while (x != 999) {
    LNode* pTemp = (LNode*)malloc(sizeof(LNode));
    pTemp->data = x;
    pTemp->next = NULL;
    if (Q->rear == NULL) {
      Q->front = Q->rear = pTemp;
    } else {
      Q->rear->next = pTemp;
      Q->rear = pTemp;
    }
    Q->len += 1;
    scanf("%d", &x);
  }
}


// 新元素入队

bool Queue_En(LinkQueue* Q, int e) {
  LNode* pTemp = (LNode*)malloc(sizeof(LNode));
  pTemp->data = e;
  pTemp->next = NULL;
  if (Q->front == NULL) {
    Q->front = pTemp;
    Q->rear = pTemp;
  } else {
    Q->rear->next = pTemp;
    Q->rear = pTemp;
  }
  Q->len += 1;
  return true;
}


// 出队

bool Queue_De(LinkQueue* Q, int* e) {
  if (Q->front == NULL) return false;
  LNode* p = Q->front;
  Q->front = p->next;
  *e = p->data;
  Q->len -= 1;
  if (Q->front == NULL) {
    Q->rear = NULL;
  }
  free(p);
  return true;
}


// 打印队列所有值
void Queue_Show(LinkQueue* Q) {
  LNode* node = Q->front;
  printf("队列值：");
  while (node != NULL) {
    printf("%d、", node->data);
    node = node->next;
  }
  printf("\n");
}



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

typedef struct {
  ElemType data[MAX_SIZE];
  int front,rear;
}SqQueue;

// 初始化队列
void Queue_Init(SqQueue &Q) {
  Q.rear = 0; 
  Q.front = 0; 
}



// 检查队列是否为空

bool Queue_IsEmpty(SqQueue Q){
  return Q.rear == Q.front;
}


// 入队操作，将元素 x 添加到队列尾部

bool Queue_En(SqQueue &Q, ElemType x) {
  if ((Q.rear + 1) % MAX_SIZE == Q.front) {
    return false; 
  }
  Q.data[Q.rear] = x; 
  Q.rear = (Q.rear + 1) % MAX_SIZE; // 更新队尾指针，实现循环队列，即如果到达数组末尾，循环回到数组开头
  return true; 
}


// 出队操作，将队列头部元素存储在 x 中，并从队列中删除

bool Queue_De(SqQueue &Q, ElemType &x) {
  // 检查队列是否为空，如果队尾指针等于队头指针，表示队列为空
  if (Q.rear == Q.front)
    return false; // 队列为空，无法出队，返回 false
  x = Q.data[Q.front]; // 将队头元素存储在 x 中
  Q.front = (Q.front + 1) % MAX_SIZE; // 更新队头指针，实现循环队列，即如果到达数组末尾，循环回到数组开头
  return true; // 出队成功，返回 true
}


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