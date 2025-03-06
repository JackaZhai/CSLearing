//数组二叉树
#include <iostream>
#include <vector>
#include <queue>
#include <limits.h> // INT_MAX
using namespace std;

// 二叉树节点结构体
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void freeMemoryTree(TreeNode *root) {
    if (root == nullptr) return; // 遇到空指针直接返回
    freeMemoryTree(root->left);  // 释放左子树
    freeMemoryTree(root->right); // 释放右子树
    delete root;                 // 释放当前节点
}
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

// 打印向量的辅助函数
void printVector(const vector<int>& vec) {
    for (int val : vec) {
        cout << val << " ";
    }
    cout << endl;
}

// 打印二叉树的辅助函数（前序遍历）
void printTree(TreeNode* root) {
    if (root == nullptr) return;
    cout << root->val << " ";
    printTree(root->left);
    printTree(root->right);
}

// 数组表示的二叉树类
class ArrayBinaryTree {
  public:
    /* 构造方法 */
    ArrayBinaryTree(vector<int> arr) {
        tree = arr;
    }

    /* 列表容量 */
    int size() {
        return tree.size();
    }

    /* 获取索引为 i 节点的值 */
    int val(int i) {
        if (i < 0 || i >= size())
            return INT_MAX; // 超出边界返回 INT_MAX
        return tree[i];
    }

    /* 获取索引为 i 节点的左子节点的索引 */
    int left(int i) {
        return 2 * i + 1;
    }

    /* 获取索引为 i 节点的右子节点的索引 */
    int right(int i) {
        return 2 * i + 2;
    }

    /* 获取索引为 i 节点的父节点的索引 */
    int parent(int i) {
        return (i - 1) / 2;
    }

    /* 层序遍历 */
    vector<int> levelOrder() {
        vector<int> res;
        for (int i = 0; i < size(); i++) {
            if (val(i) != INT_MAX)
                res.push_back(val(i));
        }
        return res;
    }

    /* 前序遍历 */
    vector<int> preOrder() {
        vector<int> res;
        dfs(0, "pre", res);
        return res;
    }

    /* 中序遍历 */
    vector<int> inOrder() {
        vector<int> res;
        dfs(0, "in", res);
        return res;
    }

    /* 后序遍历 */
    vector<int> postOrder() {
        vector<int> res;
        dfs(0, "post", res);
        return res;
    }

  private:
    vector<int> tree;

    /* 深度优先遍历 */
    void dfs(int i, string order, vector<int> &res) {
        if (val(i) == INT_MAX) // 超出边界返回
            return;

        // 前序遍历
        if (order == "pre")
            res.push_back(val(i));
        
        dfs(left(i), order, res); // 左子树
        
        // 中序遍历
        if (order == "in")
            res.push_back(val(i));
        
        dfs(right(i), order, res); // 右子树

        // 后序遍历
        if (order == "post")
            res.push_back(val(i));
    }
};

/* Driver Code */
int main() {
    // 初始化二叉树
    vector<int> arr = {1, 2, 3, 4, INT_MAX, 6, 7, 8, 9, INT_MAX, INT_MAX, 12, INT_MAX, INT_MAX, 15};
    TreeNode *root = vectorToTree(arr);
    
    cout << "\n初始化二叉树:\n";
    cout << "二叉树的数组表示：\n";
    printVector(arr);
    cout << "二叉树的链表表示：\n";
    printTree(root);  // 打印链表表示
    cout << endl;

    // 数组表示的二叉树类
    ArrayBinaryTree abt(arr);

    // 访问节点
    int i = 1;
    int l = abt.left(i), r = abt.right(i), p = abt.parent(i);
    cout << "\n当前节点的索引为 " << i << "，值为 " << abt.val(i) << "\n";
    cout << "其左子节点的索引为 " << l << "，值为 " << (l < abt.size() ? to_string(abt.val(l)) : "nullptr") << "\n";
    cout << "其右子节点的索引为 " << r << "，值为 " << (r < abt.size() ? to_string(abt.val(r)) : "nullptr") << "\n";
    cout << "其父节点的索引为 " << p << "，值为 " << (p >= 0 ? to_string(abt.val(p)) : "nullptr") << "\n";

    // 遍历树
    vector<int> res = abt.levelOrder();
    cout << "\n层序遍历为： ";
    printVector(res);
    res = abt.preOrder();
    cout << "前序遍历为： ";
    printVector(res);
    res = abt.inOrder();
    cout << "中序遍历为： ";
    printVector(res);
    res = abt.postOrder();
    cout << "后序遍历为： ";
    printVector(res);

    // 释放内存
    freeMemoryTree(root); // 释放链表表示的二叉树
    return 0;
}
