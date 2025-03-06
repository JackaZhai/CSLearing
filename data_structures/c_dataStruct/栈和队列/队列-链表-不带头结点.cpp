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