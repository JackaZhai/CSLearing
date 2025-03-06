// 定义二叉树节点的数据类型为整数
#define ElemType int
#include <stdlib.h>
#include <stdio.h>

// 定义二叉树节点的结构体，包括数据域，左右孩子指针，以及左右线索标记
// ltag, rtag 为 0 表示指向孩子节点的指针
//            为 1 表示指向前驱或后继线索的指针
typedef struct ThreadNode {
  ElemType data;
  struct ThreadNode *lchild, *rchild;
  int ltag, rtag;
} ThreadNode, * ThreadTree;

// 前序线索化中用于记录前驱节点的全局变量
ThreadNode *pre = NULL;


// 通过给定数组创建二叉树，0 表示空节点
// nums 为数组、len 为数组长度、i 为当前数组下标
ThreadTree Thread_Create(char* nums, int len, int i) {
  if (i >= len || nums[i] == 0) return NULL;
  // 分配内存创建新节点
  ThreadTree node = (ThreadTree)malloc(sizeof(ThreadNode));
  node->data = nums[i];
  // 递归创建左右子树
  node->lchild = Thread_Create(nums, len, 2 * i + 1);
  node->rchild = Thread_Create(nums, len, 2 * i + 2);
  node->ltag = 0;
  node->rtag = 0;
  return node;
}


// 前序线索化函数
void PreThread(ThreadTree T) {
  if (T != NULL) {
    // 当前节点的左孩子为空，建立前驱线索
    if (T->lchild == NULL) {
      T->lchild = pre;
      T->ltag = 1;  // 设置左线索标记
    }

    // 前驱节点的右孩子为空，建立后继线索
    if (pre != NULL && pre->rchild == NULL) {
      pre->rchild = T;
      pre->rtag = 1;  // 设置右线索标记
    }
    pre = T;  // 更新前驱节点

    // 递归处理左子树
    if (T->ltag == 0) {
      PreThread(T->lchild);
    }
    // 递归处理右子树
    if (T->rtag == 0) {
      PreThread(T->rchild);
    }
  }
}

// 创建前序线索二叉树
void CreatePreThread(ThreadTree T) {
  pre = NULL;  // 初始化前驱节点
  if (T != NULL) {
    PreThread(T);

    // 处理最后一个节点的后继线索
    if (pre->rchild == NULL)
      pre->rtag = 1;
  }
}


// 中序线索化函数
void InThread(ThreadTree T) {
  if (T != NULL) {
    // 递归处理左子树
    InThread(T->lchild);

    // 当前节点的左孩子为空，建立前驱线索
    if (T->lchild == NULL) {
      T->lchild = pre;
      T->ltag = 1;  // 设置左线索标记
    }

    // 前驱节点的右孩子为空，建立后继线索
    if (pre != NULL && pre->rchild == NULL) {
      pre->rchild = T;
      pre->rtag = 1;  // 设置右线索标记
    }
    pre = T;  // 更新前驱节点

    // 递归处理右子树
    InThread(T->rchild);
  }
}

// 创建中序线索二叉树
void CreateInThread(ThreadTree T) {
  pre = NULL;  // 初始化前驱节点
  if (T != NULL) {
    InThread(T);

    // 处理最后一个节点的后继线索
    if (pre->rchild == NULL) {
      pre->rtag = 1;
    }
  }
}


// 后序线索化函数
void PostThread(ThreadTree T) {
  if (T != NULL) {
    // 递归处理左子树
    PostThread(T->lchild);

    // 递归处理右子树
    PostThread(T->rchild);
    // 当前节点的左孩子为空，建立前驱线索
    if (T->lchild == NULL) {
      T->lchild = pre;
      T->ltag = 1;  // 设置左线索标记
    }

    // 前驱节点的右孩子为空，建立后继线索
    if (pre != NULL && pre->rchild == NULL) {
      pre->rchild = T;
      pre->rtag = 1;  // 设置右线索标记
    }

    pre = T;  // 更新前驱节点
  }
}

// 创建后序线索二叉树
void CreatePostThread(ThreadTree T) {
  pre = NULL;  // 初始化前驱节点
  if (T != NULL) {
    PostThread(T);

    // 处理最后一个节点的后继线索
    if (pre->rchild == NULL) {
      pre->rtag = 1;
    }
  }
}


// 前序线索二叉树的前序遍历输出
void PreThreadTraverse(ThreadTree T) {
  if (T != NULL) {
    printf("%d ", T->data);  // 输出节点数据
    // 如果左孩子不是线索节点，递归遍历左子树
    if (T->ltag == 0) {
      PreThreadTraverse(T->lchild);
    }
    // 如果右孩子不是线索节点，递归遍历右子树
    if (T->rtag == 0) {
      PreThreadTraverse(T->rchild);
    }
  }
}

// 中序线索二叉树的中序遍历输出
void InThreadTraverse(ThreadTree T) {
  if (T != NULL) {
    // 递归遍历左子树
    if (T->ltag == 0) {
      InThreadTraverse(T->lchild);
    }
    printf("%d ", T->data);  // 输出节点数据
    // 递归遍历右子树
    if (T->rtag == 0) {
      InThreadTraverse(T->rchild);
    }
  }
}

// 后序线索二叉树的后序遍历输出
void PostThreadTraverse(ThreadTree T) {
  if (T != NULL) {
    // 递归遍历左子树
    if (T->ltag == 0) {
      PostThreadTraverse(T->lchild);
    }
    // 递归遍历右子树
    if (T->rtag == 0) {
      PostThreadTraverse(T->rchild);
    }
    printf("%d ", T->data);  // 输出节点数据
  }
}


int main() {
  // 创建测试二叉树
  char nums[11] = {1, 2, 3, 0, 4, 0, 5, 0, 0, 6, 0};
  ThreadTree preTree = Thread_Create(nums, 11, 0);
  ThreadTree inTree = Thread_Create(nums, 11, 0);
  ThreadTree postTree = Thread_Create(nums, 11, 0);

  // 创建前序线索二叉树
  CreatePreThread(preTree);

  // 输出前序遍历结果
  printf("前序遍历结果：");
  PreThreadTraverse(preTree);
  printf("\n");

  // 创建中序线索二叉树
  CreateInThread(inTree);

  // 输出中序遍历结果
  printf("中序遍历结果：");
  InThreadTraverse(inTree);
  printf("\n");

  // 创建后序线索二叉树
  CreatePostThread(postTree);

  // 输出后序遍历结果
  printf("后序遍历结果：");
  PostThreadTraverse(postTree);
  printf("\n");

  return 0;
}