#include <stdio.h>
#include <stdlib.h>
// 树存储结构
typedef struct BiTNode {
  int data;
  struct BiTNode *lchild, *rchild; // 左右孩子指针
} BiTNode, * BiTree;

// 循环队列算法，辅助完成二叉树层次遍历
#define MaxSize 50   // 定义队列中元素的最大个数
typedef struct {
  BiTree data[MaxSize]; // 存放队列元素
  int front, rear;   // 队头和队尾指针 
} SqQueue;

// 初始化队列（带头结点）
void Queue_Init(SqQueue &Q) {
  Q.rear = Q.front = 0;
}

// 判断队列是否为空
bool Queue_Empty(SqQueue Q) {
  return Q.front == Q.rear;
}

// 入队
bool Queue_En(SqQueue &Q, BiTree e) {
  if ((Q.rear + 1) % MaxSize == Q.front) return false; // 队满则报错
  Q.data[Q.rear] = e;
  Q.rear = (Q.rear + 1) % MaxSize; // 队尾指针加 1 取模
  return true;
}

// 出队
bool Queue_De(SqQueue &Q, BiTree &e) {
  if (Queue_Empty(Q)) return false; // 队空则报错
  e = Q.data[Q.front];
  Q.front = (Q.front + 1) % MaxSize;
  return true;
}


// 通过给定数组创建二叉树，0为空结点
// nums 为数组、len 为数组长度、i 为当前数组下标
BiTNode * BiTree_Create (char* nums, int len , int i) {
  if (i >= len || nums[i] == 0) return NULL;
  BiTNode * node = (BiTNode *)malloc(sizeof(BiTNode));
  node->data = nums[i];
  node->lchild = BiTree_Create(nums, len, 2 * i + 1);
  node->rchild = BiTree_Create(nums, len, 2 * i + 2);
  return node;
}


// 先序遍历: 根左右(NLR)
void Order_Pre(BiTree tree) {
  if(tree == NULL) return;
  printf("%d,", tree->data);  // 访问根树内容
  Order_Pre(tree->lchild); // 递归遍历左子树
  Order_Pre(tree->rchild); // 递归遍历右子树
}


// 中序遍历: 左根右(LNR)
void Order_In(BiTree tree) {
  if(tree == NULL) return;
  Order_In(tree->lchild); // 递归遍历左子树
  printf("%d,", tree->data);  // 访问根树内容
  Order_In(tree->rchild); // 递归遍历右子树
}


// 后序遍历: 左根右(LRN)
void Order_Post(BiTree tree) {
  if(tree == NULL) return;
  Order_Post(tree->lchild); // 递归遍历左子树
  Order_Post(tree->rchild); // 递归遍历右子树
  printf("%d,", tree->data);  // 访问根树内容
}


// 层次遍历
void Order_Level (BiTree tree) {
  SqQueue Q; // 初始化队列
  Queue_Init(Q);
  BiTree p;
  Queue_En(Q, tree); // 根节点入队
  while (!Queue_Empty(Q)) { // 队列不空则继续遍历
    Queue_De(Q, p); // 队头结点出队
    printf("%d,", p->data); // 访问出队结点内容
    if (p->lchild != NULL)
      Queue_En(Q, p->lchild); // 左子树不为空，则左子树根入队
    if (p->rchild != NULL)
      Queue_En(Q, p->rchild); // 右子树不为空，则右子树根入队
  }
}


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