#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100  // 双端队列的最大容量

// 双端队列结构体
typedef struct {
  int data[MAX_SIZE];
  int front;  // 队列头指针
  int rear;   // 队列尾指针
} Deque;

// 初始化双端队列
void Deque_Init(Deque &Q) {
  Q.front = 0;  // 头指针指向0
  Q.rear = 0;   // 尾指针指向0
}

// 判断双端队列是否为空
int isEmpty(Deque &Q) {
  return (Q.front == Q.rear);
}

// 判断双端队列是否已满
int isFull(Deque &Q) {
  return (Q.front == (Q.rear + 1) % MAX_SIZE);
}


// 在队头插入元素
void Deque_InsertFront(Deque &Q, int element) {
  if (Q.front == (Q.rear + 1) % MAX_SIZE) {
    printf("双端队列已满，无法插入元素\n");
  }
  // 注意是先移动，在插值。和在队尾插入元素是相反的
  Q.front = (Q.front - 1 + MAX_SIZE) % MAX_SIZE;  // 循环向前移动头指针
  Q.data[Q.front] = element;  // 在队头插入元素
}


// 在队尾插入元素
void Deque_InsertRear(Deque &Q, int element) {
  if (Q.front == (Q.rear + 1) % MAX_SIZE) {
    printf("双端队列已满，无法插入元素\n");
  }

  Q.data[Q.rear] = element;  // 在队尾插入元素
  Q.rear = (Q.rear + 1) % MAX_SIZE;  // 循环向后移动尾指针
}


// 从队头删除元素
int Deque_DeleteFront(Deque &Q) {
  if (Q.front == Q.rear) {
    printf("双端队列为空，无法删除元素\n");
    return -1;  // 返回一个特殊值表示错误
  }

  int element = Q.data[Q.front];
  Q.front = (Q.front + 1) % MAX_SIZE;  // 循环向后移动头指针
  return element;
}


// 从队尾删除元素
int Deque_DeleteRear(Deque &Q) {
  if (Q.front == Q.rear) {
    printf("双端队列为空，无法删除元素\n");
    return -1;  // 返回一个特殊值表示错误
  }

  Q.rear = (Q.rear - 1 + MAX_SIZE) % MAX_SIZE;  // 循环向前移动尾指针
  return Q.data[Q.rear];
}


void Deque_print (Deque Q) {
  // 输出队列中的值
  printf("队列中的值: ");
  int i;
  for (i = Q.front; i != Q.rear; i = (i + 1) % MAX_SIZE) {
      printf("%d ", Q.data[i]);
  }
  printf("\n");
}


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