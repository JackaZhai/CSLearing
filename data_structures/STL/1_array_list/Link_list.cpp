#include <iostream>
using namespace std;

/* 链表结构体 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

/* 在链表的节点 n0 之后插入节点 P */
void insert(ListNode *n0, ListNode *p) {
    ListNode *n1 = n0->next;
    p->next = n1;
    n0->next = p;
}

/* 删除链表的节点 n0 之后的首个节点 */
void remove(ListNode *n0) {
    if (n0 == nullptr || n0->next == nullptr) {
        return; // 判断 n0 是否为 nullptr
    }
    ListNode *n1 = n0->next;
    n0->next = n1->next;
    delete n1;
}

/* 访问链表中索引为 index 的节点 */
ListNode *access(ListNode *head, int index) {
    for (int i = 0; i < index; i++) {
        if (head == nullptr) return nullptr; // 超出链表长度
        head = head->next;
    }
    return head;
}

/* 在链表中查找值为 target 的首个节点 */
int find(ListNode *head, int target) {
    int index = 0;
    while (head != nullptr) {
        if (head->val == target)
            return index;
        head = head->next;
        index++;
    }
    return -1;
}

/* 打印链表 */
int printLinkedList(ListNode *head) {
    int count = 0;
    while (head != nullptr) {
        cout << head->val << " ";  // 输出节点值
        count++;
        head = head->next;          // 移动到下一个节点
    }
    cout << endl;
    return count;
}

// 释放链表内存
void freeMemoryLinkedList(ListNode *head) {
    ListNode *current = head;
    ListNode *nextNode;

    while (current != nullptr) {
        nextNode = current->next; // 保存下一个节点
        delete current;           // 删除当前节点
        current = nextNode;       // 移动到下一个节点
    }
}

/* 头插法：在链表头部插入节点 */
ListNode *headInsert(ListNode *head, ListNode *newNode) {
    newNode->next = head;
    return newNode;
}

/* 尾插法：在链表尾部插入节点 */
ListNode *tailInsert(ListNode *head, ListNode *newNode) {
    if (head == nullptr) {
        return newNode; // 如果链表为空，则新节点作为头节点返回
    }

    ListNode *current = head;
    while (current->next != nullptr) {
        current = current->next; // 找到链表的尾部
    }
    current->next = newNode;
    return head;
}

int main() {
    /* 初始化链表 */
    ListNode *n0 = new ListNode(1);
    ListNode *n1 = new ListNode(3);
    ListNode *n2 = new ListNode(2);
    ListNode *n3 = new ListNode(5);
    ListNode *n4 = new ListNode(4);

    n0->next = n1;
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;

    cout << "初始化的链表为" << endl;
    printLinkedList(n0);

    /* 插入节点 */
    insert(n0, new ListNode(0));
    cout << "插入节点后的链表为" << endl;
    printLinkedList(n0);

    /* 删除节点 */
    remove(n0);
    cout << "删除节点后的链表为" << endl;
    printLinkedList(n0);

    /* 头插法 */
    n0 = headInsert(n0, new ListNode(10));
    cout << "头插法后的链表为" << endl;
    printLinkedList(n0);

    /* 尾插法 */
    n0 = tailInsert(n0, new ListNode(20));
    cout << "尾插法后的链表为" << endl;
    printLinkedList(n0);

    /* 访问节点 */
    ListNode *node = access(n0, 3);
    if (node != nullptr) {
        cout << "链表中索引 3 处的节点的值 = " << node->val << endl;
    } else {
        cout << "索引 3 处的节点不存在。" << endl;
    }

    /* 查找节点 */
    int index = find(n0, 2);
    cout << "链表中值为 2 的节点的索引 = " << index << endl;

    // 释放内存
    freeMemoryLinkedList(n0);

    return 0;
}
