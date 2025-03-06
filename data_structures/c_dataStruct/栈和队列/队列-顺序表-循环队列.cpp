#include <stdio.h>
#include <stdlib.h>

#define ElemType int
#define MAX_SIZE 10

typedef struct {
  ElemType data[MAX_SIZE]; // 存储队列元素的数组
  int front, rear; // 队列的前端和后端指针
} SqQueue;

// 初始化队列
void Queue_Init(SqQueue &Q) {
  Q.rear = 0; // 初始化队尾指针
  Q.front = 0; // 初始化队头指针
}

// 检查队列是否为空
bool Queue_IsEmpty(SqQueue Q) {
  if (Q.rear == Q.front)
    return true; // 队列为空
  else
    return false; // 队列不为空
}


// 入队操作，将元素 x 添加到队列尾部
bool Queue_En(SqQueue &Q, ElemType x) {
  // 检查队列是否已满，如果队尾指针的下一个位置等于队头指针，表示队列已满
  if ((Q.rear + 1) % MAX_SIZE == Q.front) {
    return false; // 队列已满，无法入队，返回 false
  }

  Q.data[Q.rear] = x; // 将元素 x 存储在队列尾部
  Q.rear = (Q.rear + 1) % MAX_SIZE; // 更新队尾指针，实现循环队列，即如果到达数组末尾，循环回到数组开头

  return true; // 入队成功，返回 true
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