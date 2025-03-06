#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
  struct TreeNode* lchild;
  struct TreeNode* rchild;
  int data;
  int height; // 新增一个高度字段
} TreeNode;

// 计算节点的高度
int height(TreeNode* node) {
  if (node == NULL)
    return -1;
  return node->height;
}

// 更新节点的高度
void updateHeight(TreeNode* node) {
  // 计算左子树的高度
  int leftHeight = height(node->lchild);
  // 计算右子树的高度
  int rightHeight = height(node->rchild);
  // 将节点的高度设置为左右子树中较大的高度加1
  // 这样可以确保节点的高度是其子树高度的最大值加1
  node->height = (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

// 获取节点的平衡因子
int getBalanceFactor(TreeNode* node) {
  if (node == NULL)
    return 0;
  return height(node->lchild) - height(node->rchild);
}


// 单旋转 - LL平衡旋转（右单旋转）
TreeNode* LL(TreeNode* node) {
  // 创建一个指针 newRoot，用来存储将要成为新根节点的左孩子
  TreeNode* newRoot = node->lchild;
  // 将原根节点的左孩子设置为 newRoot 的右孩子
  node->lchild = newRoot->rchild;
  // 将原根节点作为 newRoot 的右孩子
  newRoot->rchild = node;

  // 更新节点高度
  updateHeight(node);
  updateHeight(newRoot);
  // 返回新的根节点
  return newRoot;
}


// 单旋转 - RR平衡旋转（左单旋转）
TreeNode* RR(TreeNode* node) {
  // 将右孩子作为新的根节点
  TreeNode* newRoot = node->rchild;
  // 将原根节点的左孩子设置为新根节点的左孩子
  node->rchild = newRoot->lchild;
  // 将原根节点作为新根节点的左孩子
  newRoot->lchild = node;

  // 更新节点高度
  updateHeight(node);
  updateHeight(newRoot);
  // 返回新的根节点
  return newRoot;
}


// 插入节点
TreeNode* insert(TreeNode* root, int data) {
  // 如果树为空，创建一个新节点并返回
  if (root == NULL) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->data = data;
    newNode->lchild = NULL;
    newNode->rchild = NULL;
    newNode->height = 0;
    return newNode;
  }

  // 如果要插入的数据小于当前节点的数据，插入到左子树中
  if (data < root->data)
    root->lchild = insert(root->lchild, data);
  // 如果要插入的数据大于当前节点的数据，插入到右子树中
  else if (data > root->data)
    root->rchild = insert(root->rchild, data);
  else
    return root; // 已存在相同值的节点，不插入

  // 更新节点高度
  updateHeight(root);

  // 获取平衡因子
  int balance = getBalanceFactor(root);

  // 平衡维护
  // 平衡因子 大于 0 则是左孩子，小于 0 则是右孩子
  // 插入的数据在左孩子的左子树 LL
  if (balance > 1 && data < root->lchild->data)
    return LL(root);

  // 插入的数据在右孩子的右子树 RR
  if (balance < -1 && data > root->rchild->data)
    return RR(root);

  // 插入的数据在左孩子的右子树 LR
  if (balance > 1 && data > root->lchild->data) {
    root->lchild = RR(root->lchild);
    return LL(root);
  }

  // 插入的数据在右孩子的左子树 RL
  if (balance < -1 && data < root->rchild->data) {
    root->rchild = LL(root->rchild);
    return RR(root);
  }

  return root; // 返回更新后的根节点
}


// 前序遍历以打印树的内容
void preorderTraversal(TreeNode* root) {
  if (root == NULL)
    return;

  printf("%d ", root->data);
  preorderTraversal(root->lchild);
  preorderTraversal(root->rchild);
}

// 中序遍历以打印树的内容
void inorderTraversal(TreeNode* root) {
  if (root == NULL)
    return;

  inorderTraversal(root->lchild);
  printf("%d ", root->data);
  inorderTraversal(root->rchild);
}


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