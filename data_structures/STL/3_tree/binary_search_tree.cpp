//二叉搜索树（Binary Search Tree，BST）是一种特殊的二叉树，它的每个节点的值都大于其左子树中的任意节点的值，小于其右子树中的任意节点的值。
//二叉搜索树的中序遍历是一个递增的有序序列。
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

// 释放二叉树内存的辅助函数
void freeMemoryTree(TreeNode* root) {
    if (root == nullptr) return;
    freeMemoryTree(root->left);
    freeMemoryTree(root->right);
    delete root;
}

// 二叉搜索树类定义
class BinarySearchTree {
  private:
    TreeNode *root;

  public:
    /* 构造方法 */
    BinarySearchTree() {
        // 初始化空树
        root = nullptr;
    }

    /* 析构方法 */
    ~BinarySearchTree() {
        freeMemoryTree(root);
    }

    /* 获取二叉树根节点 */
    TreeNode *getRoot() {
        return root;
    }

    /* 查找节点 */
    TreeNode *search(int num) {
        TreeNode *cur = root;
        while (cur != nullptr) {
            if (cur->val < num)
                cur = cur->right;
            else if (cur->val > num)
                cur = cur->left;
            else
                break;
        }
        return cur; // 返回目标节点或 nullptr
    }

    /* 插入节点 */
    void insert(int num) {
        if (root == nullptr) {
            root = new TreeNode(num);
            return;
        }
        TreeNode *cur = root, *pre = nullptr;
        while (cur != nullptr) {
            if (cur->val == num) // 找到重复节点
                return;
            pre = cur;
            if (cur->val < num)
                cur = cur->right;
            else
                cur = cur->left;
        }
        TreeNode *node = new TreeNode(num);
        if (pre->val < num)
            pre->right = node;
        else
            pre->left = node;
    }

    /* 删除节点 */
    void remove(int num) {
        if (root == nullptr)
            return;
        TreeNode *cur = root, *pre = nullptr;
        while (cur != nullptr) {
            if (cur->val == num)
                break;
            pre = cur;
            if (cur->val < num)
                cur = cur->right;
            else
                cur = cur->left;
        }
        if (cur == nullptr) // 若无待删除节点
            return;

        // 子节点数量 = 0 or 1
        if (cur->left == nullptr || cur->right == nullptr) {
            TreeNode *child = cur->left != nullptr ? cur->left : cur->right;
            if (cur != root) {
                if (pre->left == cur)
                    pre->left = child;
                else
                    pre->right = child;
            } else {
                root = child; // 重新指定根节点
            }
            delete cur; // 释放内存
        } else {
            // 寻找中序后继
            TreeNode *tmp = cur->right;
            while (tmp->left != nullptr) {
                tmp = tmp->left;
            }
            int tmpVal = tmp->val;
            remove(tmp->val); // 递归删除节点 tmp
            cur->val = tmpVal; // 用 tmp 的值覆盖 cur
        }
    }
};

/* Driver Code */
int main() {
    /* 初始化二叉搜索树 */
    BinarySearchTree *bst = new BinarySearchTree();
    vector<int> nums = {8, 4, 12, 2, 6, 10, 14, 1, 3, 5, 7, 9, 11, 13, 15};
    for (int num : nums) {
        bst->insert(num);
    }
    cout << "初始化的二叉树为:\n";
    printTree(bst->getRoot());
    cout << endl;

    /* 查找节点 */
    TreeNode *node = bst->search(7);
    cout << "查找到的节点对象为 " << node << "，节点值 = " << node->val << endl;

    /* 插入节点 */
    bst->insert(16);
    cout << "插入节点 16 后，二叉树为:\n";
    printTree(bst->getRoot());
    cout << endl;

    /* 删除节点 */
    bst->remove(1);
    cout << "删除节点 1 后，二叉树为:\n";
    printTree(bst->getRoot());
    cout << endl;

    bst->remove(2);
    cout << "删除节点 2 后，二叉树为:\n";
    printTree(bst->getRoot());
    cout << endl;

    bst->remove(4);
    cout << "删除节点 4 后，二叉树为:\n";
    printTree(bst->getRoot());
    cout << endl;

    // 释放内存
    delete bst;

    return 0;
}
