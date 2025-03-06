// 层序遍历
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

// 层序遍历
vector<int> levelOrder(TreeNode* root) {
    vector<int> vec;
    if (root == nullptr) return vec; // 处理空树情况

    queue<TreeNode*> queue;
    queue.push(root);

    while (!queue.empty()) {
        TreeNode* node = queue.front();
        queue.pop();
        vec.push_back(node->val); // 保存节点值

        if (node->left != nullptr)
            queue.push(node->left); // 左子节点入队
        if (node->right != nullptr)
            queue.push(node->right); // 右子节点入队
    }
    return vec;
}

/* Driver Code */
int main() {
    /* 初始化二叉树 */
    TreeNode* root = vectorToTree(vector<int>{1, 2, 3, 4, 5, 6, 7});
    cout << endl << "初始化二叉树:\n";
    printTree(root);
    cout << endl;

    /* 层序遍历 */
    vector<int> vec = levelOrder(root);
    cout << "层序遍历的节点打印序列 = ";
    printVector(vec);

    // 释放二叉树内存
    // 这里可以调用 freeMemoryTree 确保释放所有节点的内存
    return 0;
}
