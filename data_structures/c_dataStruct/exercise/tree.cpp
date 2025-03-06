// 二叉树
#include <stdio.h>
#include <stdlib.h>
// 树存储结构


// 循环队列算法，辅助完成二叉树层次遍历



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


// 二叉排序树
#include <stdio.h>
#include <stdlib.h>
// 树存储结构


// 循环队列算法，辅助完成二叉树层次遍历


// 初始化队列（带头结点）

// 判断队列是否为空


// 入队


// 出队



// 插入关键字为 k 的新结点



// tree 根节点、 nums 数组、len 数组长度


// 删除结点


// 先序遍历: 根左右(NLR)


// 中序遍历: 左根右(LNR)



// 后序遍历: 左根右(LRN)



// 层次遍历



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


// 哈夫曼树
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 树存储结构


    // 字符指针数组中存储的元素类型

// 查找在 0 到 i 中的两个最小值，且没有被处理过(parent == 0)



// 构建哈夫曼树 HT=哈夫曼树、w=权值、n=待编码数量



// 生成哈夫曼编码 HT=哈夫曼树、HC=编码结果保存(相当于二维数组)、n=待编码字符个数



// 打印哈夫曼树，n=编码节点个数

int main() {
  int n = 4;
  HuffmanTree HT;
  int w[] = {7, 5, 2, 4};
  char data[] = {'a', 'b', 'c', 'd'};
  Huffman_Create(HT, w, data, n);
  HuffmanTree_Print(HT, n);

  HuffmanCode HC;
  Huffman_Coding(HT, HC, n);
  HuffmanCode_Print(HT, HC, n);
  return 0;
}


// 线索二叉树
// 定义二叉树节点的数据类型为整数
#define ElemType int
#include <stdlib.h>
#include <stdio.h>

// 定义二叉树节点的结构体，包括数据域，左右孩子指针，以及左右线索标记
// ltag, rtag 为 0 表示指向孩子节点的指针
//            为 1 表示指向前驱或后继线索的指针

// 前序线索化中用于记录前驱节点的全局变量



// 通过给定数组创建二叉树，0 表示空节点
// nums 为数组、len 为数组长度、i 为当前数组下标



// 前序线索化函数


// 创建前序线索二叉树



// 中序线索化函数


// 创建中序线索二叉树



// 后序线索化函数


// 创建后序线索二叉树



// 前序线索二叉树的前序遍历输出


// 中序线索二叉树的中序遍历输出


// 后序线索二叉树的后序遍历输出



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


// AVL平衡二叉树
#include <stdio.h>
#include <stdlib.h>



// 计算节点的高度


// 更新节点的高度


// 获取节点的平衡因子



// 单旋转 - LL平衡旋转（右单旋转）



// 单旋转 - RR平衡旋转（左单旋转）



// 插入节点



// 前序遍历以打印树的内容


// 中序遍历以打印树的内容



// 主函数
int main() {
  int arr[6] = {15, 3, 7, 10, 9, 8};

  TreeNode* root = NULL;
  for (int i = 0; i < 6; i++) {
    root = insert(root, arr[i]);
  }

  printf("中序遍历结果：");
  inorderTraversal(root);
  printf("\n");

  printf("前序遍历结果：");
  preorderTraversal(root);
  return 0;
}