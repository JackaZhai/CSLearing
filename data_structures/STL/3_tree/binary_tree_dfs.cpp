//前中后序遍历二叉树
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// 二叉树节点结构体
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 从数组生成二叉树
TreeNode* vectorToTree(const vector<int>& nums) {
    if (nums.empty()) return nullptr;

    TreeNode* root = new TreeNode(nums[0]);
    queue<TreeNode*> q;
    q.push(root);

    for (size_t i = 1; i < nums.size(); i++) {
        TreeNode* node = q.front();
        q.pop();

        if (nums[i] != -1) { // -1 表示空值
            node->left = new TreeNode(nums[i]);
            q.push(node->left);
        }
        if (++i < nums.size() && nums[i] != -1) {
            node->right = new TreeNode(nums[i]);
            q.push(node->right);
        }
    }
    return root;
}

// 打印二叉树的辅助函数（前序遍历）
void printTree(TreeNode* root) {
    if (root == nullptr) return;
    cout << root->val << " ";
    printTree(root->left);
    printTree(root->right);
}

// 打印向量的辅助函数
void printVector(const vector<int>& vec) {
    for (int val : vec) {
        cout << val << " ";
    }
    cout << endl;
}

// 存储遍历序列的向量
vector<int> vec;

/* 前序遍历 */
void preOrder(TreeNode* root) {
    if (root == nullptr)
        return;
    // 访问优先级：根节点 -> 左子树 -> 右子树
    vec.push_back(root->val);
    preOrder(root->left);
    preOrder(root->right);
}

/* 中序遍历 */
void inOrder(TreeNode* root) {
    if (root == nullptr)
        return;
    // 访问优先级：左子树 -> 根节点 -> 右子树
    inOrder(root->left);
    vec.push_back(root->val);
    inOrder(root->right);
}

/* 后序遍历 */
void postOrder(TreeNode* root) {
    if (root == nullptr)
        return;
    // 访问优先级：左子树 -> 右子树 -> 根节点
    postOrder(root->left);
    postOrder(root->right);
    vec.push_back(root->val);
}

/* Driver Code */
int main() {
    /* 初始化二叉树 */
    TreeNode* root = vectorToTree(vector<int>{1, 2, 3, 4, 5, 6, 7});
    cout << "初始化二叉树:\n";
    printTree(root);
    cout << endl;

    /* 前序遍历 */
    vec.clear();
    preOrder(root);
    cout << "前序遍历的节点打印序列 = ";
    printVector(vec);

    /* 中序遍历 */
    vec.clear();
    inOrder(root);
    cout << "中序遍历的节点打印序列 = ";
    printVector(vec);

    /* 后序遍历 */
    vec.clear();
    postOrder(root);
    cout << "后序遍历的节点打印序列 = ";
    printVector(vec);

    // 释放内存（需要实现 freeMemoryTree）
    return 0;
}
