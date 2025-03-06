//二叉树的插入与删除
#include <iostream>
using namespace std;

// 定义二叉树节点结构体
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 打印二叉树的辅助函数（前序遍历）
void printTree(TreeNode *root) {
    if (root == nullptr) return;
    cout << root->val << " "; // 打印节点值
    printTree(root->left);    // 遍历左子树
    printTree(root->right);   // 遍历右子树
}

// 释放二叉树内存的辅助函数
void freeMemoryTree(TreeNode *root) {
    if (root == nullptr) return; // 遇到空指针直接返回
    freeMemoryTree(root->left);  // 释放左子树
    freeMemoryTree(root->right); // 释放右子树
    delete root;                 // 释放当前节点
}

int main() {
    /* 初始化二叉树 */
    // 初始化节点
    TreeNode *n1 = new TreeNode(1);
    TreeNode *n2 = new TreeNode(2);
    TreeNode *n3 = new TreeNode(3);
    TreeNode *n4 = new TreeNode(4);
    TreeNode *n5 = new TreeNode(5);
    
    // 构建节点之间的引用（指针）
    n1->left = n2;
    n1->right = n3;
    n2->left = n4;
    n2->right = n5;

    cout << "初始化二叉树:\n";
    printTree(n1); // 打印初始树
    cout << endl;

    /* 插入与删除节点 */
    TreeNode *P = new TreeNode(0);
    // 在 n1->n2 中间插入节点 P
    n1->left = P;
    P->left = n2; // P 成为 n1 的左子节点
    cout << "插入节点 P 后:\n";
    printTree(n1); // 打印插入后的树
    cout << endl;

    // 删除节点 P
    n1->left = n2; // 恢复 n1 左子节点为 n2
    delete P; // 释放 P 的内存
    cout << "删除节点 P 后:\n";
    printTree(n1); // 打印删除后的树
    cout << endl;

    // 释放内存
    freeMemoryTree(n1); // 释放整个树的内存

    return 0;
}
