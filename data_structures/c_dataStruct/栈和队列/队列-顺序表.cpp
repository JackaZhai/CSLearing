#include <stdio.h>

#define MAX_SIZE 100
typedef int ElemType; // 假设队列中存储的元素类型是整数

typedef struct {
  ElemType data[MAX_SIZE]; // 存储队列元素的数组
  int front, rear; // 队列的队头和队尾指针
} SqQueue;

// 初始化队列
void Queue_Init(SqQueue &Q) {
  Q.front = Q.rear = 0;
}

// 判断队列是否为空
int Queue_IsEmpty(SqQueue &Q) {
  return Q.front == Q.rear;
}

// 判断队列是否已满
int Queue_IsFull(SqQueue &Q) {
  return Q.rear == MAX_SIZE - 1;
}


// 入队操作
int Queue_En(SqQueue &Q, ElemType x) {
  if (Q.rear == MAX_SIZE - 1) {
    printf("队列已满，无法入队\n");
    return 0; // 入队失败
  }
  Q.data[Q.rear] = x;
  Q.rear++; // 队尾指针增加
  return 1; // 入队成功
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