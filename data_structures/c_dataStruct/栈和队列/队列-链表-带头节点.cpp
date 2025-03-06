#include <stdio.h>
#include<stdlib.h>
typedef struct LNode {
  int data;
  struct LNode * next;
} LNode;
typedef struct {
    LNode * front, *rear; // 队头、队尾
    int len; // 当前队列的成员数
} LinkQueue;

// 初始化队列（带头结点）
bool Queue_Init (LinkQueue &Q) {
  Q.front = Q.rear = (LNode *)malloc(sizeof(LNode));
  Q.front->next = NULL;
  Q.len = 0;
  return true;
}

// 判断队列是否为空
bool Queue_Empty (LinkQueue Q) {
    return Q.front == Q.rear;
}

// 获取队列有效数据节点个数
int Queue_Length (LinkQueue Q) {
  return Q.len;
}


// 创建队列
LinkQueue Queue_Create(LinkQueue &Q) {
  LNode *pTemp; int x;
  scanf("%d", &x);
  while (x != 999) {
    pTemp = (LNode *)malloc(sizeof(LNode));
    pTemp->data = x;
    pTemp->next = NULL;
    Q.rear->next = pTemp;
    Q.rear = pTemp;
    Q.len += 1;
    scanf("%d", &x);
  }
  return Q;
}


// 新元素入队
bool Queue_En(LinkQueue &Q, int e) {
  LNode *pTemp = (LNode *)malloc(sizeof(LNode));
  pTemp->data = e;
  pTemp->next = NULL;
  Q.rear->next = pTemp;
  Q.rear = pTemp;
  Q.len += 1;
  return true;
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