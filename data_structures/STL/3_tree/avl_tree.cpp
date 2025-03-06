#include <iostream>
#include <vector>
#include <queue>
#include <algorithm> // 包含 std::max
#include <climits>  // 包含 INT_MAX
using namespace std;

// 二叉树节点结构体
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    int height; // 节点高度

    TreeNode(int x) : val(x), left(nullptr), right(nullptr), height(0) {}
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

        if (nums[i] != INT_MAX) { // INT_MAX 表示空值
            node->left = new TreeNode(nums[i]);
            q.push(node->left);
        }
        if (++i < nums.size() && nums[i] != INT_MAX) {
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

// AVL 树类定义
class AVLTree {
  private:
    TreeNode *root;

    /* 更新节点高度 */
    void updateHeight(TreeNode *node) {
        node->height = max(height(node->left), height(node->right)) + 1;
    }

    /* 获取节点高度 */
    int height(TreeNode *node) {
        return node == nullptr ? -1 : node->height;
    }

    /* 获取平衡因子 */
    int balanceFactor(TreeNode *node) {
        return height(node->left) - height(node->right);
    }

    /* 右旋操作 */
    TreeNode *rightRotate(TreeNode *node) {
        TreeNode *child = node->left;
        TreeNode *grandChild = child->right;
        child->right = node;
        node->left = grandChild;
        updateHeight(node);
        updateHeight(child);
        return child;
    }

    /* 左旋操作 */
    TreeNode *leftRotate(TreeNode *node) {
        TreeNode *child = node->right;
        TreeNode *grandChild = child->left;
        child->left = node;
        node->right = grandChild;
        updateHeight(node);
        updateHeight(child);
        return child;
    }

    /* 旋转以恢复平衡 */
    TreeNode *rotate(TreeNode *node) {
        int _balanceFactor = balanceFactor(node);
        if (_balanceFactor > 1) {
            if (balanceFactor(node->left) >= 0) {
                return rightRotate(node);
            } else {
                node->left = leftRotate(node->left);
                return rightRotate(node);
            }
        }
        if (_balanceFactor < -1) {
            if (balanceFactor(node->right) <= 0) {
                return leftRotate(node);
            } else {
                node->right = rightRotate(node->right);
                return leftRotate(node);
            }
        }
        return node; // 维持平衡
    }

    /* 递归插入节点 */
    TreeNode *insertHelper(TreeNode *node, int val) {
        if (node == nullptr)
            return new TreeNode(val);
        if (val < node->val)
            node->left = insertHelper(node->left, val);
        else if (val > node->val)
            node->right = insertHelper(node->right, val);
        else
            return node; // 忽略重复值
        updateHeight(node);
        return rotate(node);
    }

    /* 递归删除节点 */
    TreeNode *removeHelper(TreeNode *node, int val) {
        if (node == nullptr)
            return nullptr;

        if (val < node->val)
            node->left = removeHelper(node->left, val);
        else if (val > node->val)
            node->right = removeHelper(node->right, val);
        else {
            if (node->left == nullptr || node->right == nullptr) {
                TreeNode *child = node->left != nullptr ? node->left : node->right;
                if (child == nullptr) {
                    delete node;
                    return nullptr;
                }
                delete node;
                return child;
            } else {
                // 找到后继节点
                TreeNode *temp = node->right;
                while (temp->left != nullptr) {
                    temp = temp->left;
                }
                int tempVal = temp->val;
                node->right = removeHelper(node->right, temp->val);
                node->val = tempVal;
            }
        }
        updateHeight(node);
        return rotate(node);
    }

  public:
    /* 构造方法 */
    AVLTree() : root(nullptr) {}

    /* 析构方法 */
    ~AVLTree() {
        freeMemoryTree(root);
    }

    /* 插入节点 */
    void insert(int val) {
        root = insertHelper(root, val);
    }

    /* 删除节点 */
    void remove(int val) {
        root = removeHelper(root, val);
    }

    /* 查找节点 */
    TreeNode *search(int val) {
        TreeNode *cur = root;
        while (cur != nullptr) {
            if (cur->val < val)
                cur = cur->right;
            else if (cur->val > val)
                cur = cur->left;
            else
                break;
        }
        return cur;
    }

    /* 获取根节点 */
    TreeNode* getRoot() {
        return root;
    }
};

/* Driver Code */
int main() {
    /* 初始化空 AVL 树 */
    AVLTree avlTree;

    /* 插入节点 */
    vector<int> nums = {5, 3, 7, 2, 4, 6, 8};
    for (int num : nums) {
        avlTree.insert(num);
    }

    cout << "初始化的 AVL 树为:\n";
    printTree(avlTree.getRoot());
    cout << endl;

    /* 查找节点 */
    TreeNode *node = avlTree.search(6);
    cout << "查找节点 6, 找到的节点值 = " << (node ? to_string(node->val) : "nullptr") << endl;

    /* 删除节点 */
    avlTree.remove(7);
    cout << "删除节点 7 后的 AVL 树:\n";
    printTree(avlTree.getRoot());
    cout << endl;

    avlTree.remove(3);
    cout << "删除节点 3 后的 AVL 树:\n";
    printTree(avlTree.getRoot());
    cout << endl;

    return 0;
}
