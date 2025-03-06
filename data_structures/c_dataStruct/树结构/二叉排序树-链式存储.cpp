#include <stdio.h>
#include <stdlib.h>
// 树存储结构
typedef struct BiTNode {
  int data;
  struct BiTNode *lchild, *rchild; // 左右孩子指针
} BSTNode, * BSTree;

// 循环队列算法，辅助完成二叉树层次遍历
#define MaxSize 50   // 定义队列中元素的最大个数
typedef struct {
  BSTree data[MaxSize]; // 存放队列元素
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
bool Queue_En(SqQueue &Q, BSTree e) {
  if ((Q.rear + 1) % MaxSize == Q.front) return false; // 队满则报错
  Q.data[Q.rear] = e;
  Q.rear = (Q.rear + 1) % MaxSize; // 队尾指针加 1 取模
  return true;
}

// 出队
bool Queue_De(SqQueue &Q, BSTree &e) {
  if (Queue_Empty(Q)) return false; // 队空则报错
  e = Q.data[Q.front];
  Q.front = (Q.front + 1) % MaxSize;
  return true;
}


// 插入关键字为 k 的新结点
int BST_Insert (BSTree &tree, int s) {
  if (tree == NULL) { // 传入的为空节点，新插入的结点为根节点
    tree = (BSTNode *)malloc(sizeof(BSTNode));
    tree->data = s;
    tree->lchild = tree->rchild = NULL;
    return 1;
  }
  else if (s == tree->data) return 0; // 相同节点，失败
  else if (s < tree->data) // 插入到 tree 的左子树
    return BST_Insert(tree->lchild, s);
  else if (s > tree->data) // 插入到 tree 的右子树
    return BST_Insert(tree->rchild, s);
}


// tree 根节点、 nums 数组、len 数组长度
void BST_Create (BSTree &tree, char* nums, int len) {
  tree = NULL;
  for (int i = 0; i < len; i++) {
    BST_Insert(tree, nums[i]);
  }
}


// 删除结点
void BST_Delete (BSTree &tree, int e) {
  // 要删除的结点
  BSTree p = tree;
  // 要删除结点的父结点
  BSTree f = NULL;

  while (p) { // 查找
    if (p->data == e) {
      break; // 找到指定结点，结束循环
    }
    f = p; // 记录要删除结点的父结点
    if (p->data > e)
      p = p->lchild; // 在 p 的左子树中查找
    else
      p = p->rchild; // 在 p 的右子树中查找
  }

  // 要删除的结点不存在
  if (!p) return;

  // 二叉树待删除结点有四种情况
  // 待删除的为叶子结点、仅有一颗子节点树、左右子树均不为空
  // 情况1：要删除的结点为叶子结点，直接删除
  if (p->lchild == NULL && p->rchild == NULL) {
    if (f == NULL)
      tree = NULL; // 删除根结点
    else if (p == f->lchild)
      f->lchild == NULL; // 删除左子树结点
    else
      f->rchild = NULL; // 删除右子树结点
    free(p);
  }
  // 情况2：要删除的结点只有一个子树
  else if (p->lchild == NULL) { // 仅有右子树
    if (f == NULL)
      tree = p->rchild; // 删除根节点
    else if (p == f->lchild)
      f->lchild = p->rchild; // 删除左子树
    else
      f->rchild = p->rchild; // 删除右子树
    free(p);
  }
  else if (p->rchild == NULL) { // 仅有左子树
    if (f == NULL)
      tree = p->lchild; // 删除根节点
    else if (p == f->lchild)
      f->lchild = p->lchild; // 删除左子树
    else
      f->rchild = p->lchild; // 删除右子树
    free(p);
  }
  // 情况3: 左右子树均不为空
  else if (p->lchild && p->rchild) {
    BSTree s = p->lchild; // 待替换p的结点
    BSTree sf = p; // 指向 s 结点的父
    // 左子树中找到最大的值（即最右的结点）
    while (s->rchild) {
      sf = s;
      s = s->rchild; // 往最右下走
    }
    p->data = s->data; // 替换值，然后删除

    if (s == sf->lchild) {
      // s为sf的左子树，由于s已经为最大结点，所以s没有右子树
      sf->lchild = s->lchild;
    } else {
      // s为sf的右子树，由于s已经为最大结点，所以s没有右子树
      sf->rchild = s->lchild;
    }
    free(s);
  }
}


// 先序遍历: 根左右(NLR)
void Order_Pre(BSTree tree) {
  if(tree == NULL) return;
  printf("%d,", tree->data);  // 访问根树内容
  Order_Pre(tree->lchild); // 递归遍历左子树
  Order_Pre(tree->rchild); // 递归遍历右子树
}


// 中序遍历: 左根右(LNR)
void Order_In(BSTree tree) {
  if(tree == NULL) return;
  Order_In(tree->lchild); // 递归遍历左子树
  printf("%d,", tree->data);  // 访问根树内容
  Order_In(tree->rchild); // 递归遍历右子树
}


// 后序遍历: 左根右(LRN)
void Order_Post(BSTree tree) {
  if(tree == NULL) return;
  Order_Post(tree->lchild); // 递归遍历左子树
  Order_Post(tree->rchild); // 递归遍历右子树
  printf("%d,", tree->data);  // 访问根树内容
}


// 层次遍历
void Order_Level (BSTree tree) {
  SqQueue Q; // 初始化队列
  Queue_Init(Q);
  BSTree p;
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
  char nums[11] = {50,30,60,40,70,10,20,80};
  BSTree tree;
  BST_Create(tree, nums, 11);
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