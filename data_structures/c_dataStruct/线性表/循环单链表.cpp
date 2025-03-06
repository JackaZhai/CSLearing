#include <stdio.h>
#include <stdlib.h>

typedef struct LNode {
  int data;
  struct LNode* next;
} LNode, *LinkList;

// 初始化循环单链表
bool List_Init(LinkList& pHead) {
  pHead = (LNode*)malloc(sizeof(LNode)); // 为头结点分配内存并将地址存储在pHead中。
  if (pHead == NULL) return false; // 检查内存分配是否成功（pHead不为NULL）。
  pHead->next = pHead; // 头结点的next指向自己，形成循环。
  return true;
}

// 判断循环单链表是否为空
bool List_Empty(LinkList pHead) {
  return pHead->next == pHead; // 检查头结点的next指针是否指向自己，如果是，则链表为空。
}

// 获取循环单链表有效数据节点个数
int List_Length(LinkList pHead) {
  int count = 0; // 用于计数有效节点的变量
  LNode* p = pHead->next; // 从头结点的下一个节点开始
  while (p != pHead) { // 遍历链表直到回到头结点
    count++; // 每经过一个节点，有效节点数量加1。
    p = p->next;
  }
  return count;
}


// 创建循环单链表，头插法结果为倒叙
LinkList List_Create(LinkList& pHead) {
  LNode* pTemp; int x; // 临时节点指针
  scanf("%d", &x);
  while (x != 999) {
    pTemp = (LNode*)malloc(sizeof(LNode)); // 分配内存并创建新节点
    pTemp->data = x;
    pTemp->next = pHead->next; // 新节点的指针指向当前头节点的下一个节点
    pHead->next = pTemp; // 头指针指向新节点，使其成为新的头节点
    scanf("%d", &x);
  }
  return pHead; // 返回带头结点的循环单链表头指针
}


// 创建循环单链表-通过尾插法
LinkList List_Create_Tail_Insert(LinkList& pHead) {
  LNode* pTemp; // 临时节点指针
  LNode* pTail = pHead; // 尾节点指针，初始指向头结点
  int x; // 用于存储输入的数据
  scanf("%d", &x);
  while (x != 999) {
    pTemp = (LNode*)malloc(sizeof(LNode)); // 分配内存并创建新节点
    pTemp->data = x; // 尾节点的下一个指针指向新节点
    pTail->next = pTemp; // 更新尾节点指针，使其指向新节点
    pTail = pTemp; // 尾节点指针后移
    scanf("%d", &x);
  }
  pTail->next = pHead; // 尾节点的下一个指针指向头结点，形成循环
  return pHead; // 返回带头结点的循环单链表头指针
}


// 按位序插入，i=1插在表头，i=length+1插在表尾
bool List_Insert(LinkList& pHead, int i, int e) {
  if (i < 1 || i > List_Length(pHead) + 1) return false;  // 检查插入位置是否有效
  int j = 0; // 当前p指向的是第几个结点
  LNode* p = pHead; // p 指向头结点
  while (p != NULL && j < i - 1) { // 循环找到要插入位置的前驱结点，直到找到前驱结点或者链表结束
    p = p->next;
    j++;
  }
  LNode* pTemp = (LNode*)malloc(sizeof(LNode));
  pTemp->data = e;
  pTemp->next = p->next; // 将新节点的next指向p的下一个节点
  p->next = pTemp; // 更新p的next指向新节点，完成插入操作。
  return true;
}


// 通过值获取结点和其位序
LNode* List_Get_Elem(LinkList pHead, int e, int& i) {
  i = 1;
  LNode* p = pHead->next; // p指向第一个数据节点
  while (p != pHead && p->data != e) { // 遍历链表直到回到头结点或者找到目标值
    p = p->next;
    i++;
  }
  if (p == pHead) return NULL; // 若找到头结点，则表示未找到目标值
  return p;
}


// 按位序删除，i=1删表头，i=length删头尾
bool List_Del(LinkList& pHead, int i) {
  if (i < 1 || i > List_Length(pHead)) return false;
  LNode* p = pHead;
  // 找到待删除位序的前一位结点，i==1已处理，故从j=2开始
  for (int j = 0; j < i - 1; j++)
    p = p->next;
  LNode* q = p->next; // 待删除结点
  p->next = q->next; // 跳过待删除结点
  free(q);
  return true;
}


// 打印循环单链表所有值
void List_Show(LinkList pHead) {
  LNode* node = pHead->next;
  printf("循环单链表值：");
  while (node != pHead) {
    printf("%d、", node->data);
    node = node->next;
  }
  printf("\n");
}

int main() {
  LinkList pHead;
  List_Init(pHead);
  printf("循环单链表判空：%s\n", List_Empty(pHead) ? "空" : "非空");

  // 头插法创建
  List_Create(pHead);
  List_Show(pHead);
  printf("循环单链表长度：%d\n\n", List_Length(pHead));

  printf("位序为1(头插)，插入：0\n");
  List_Insert(pHead, 1, 0);
  List_Show(pHead);
  printf("循环单链表长度：%d\n\n", List_Length(pHead));

  printf("位序为%d(尾插)，插入：99\n", List_Length(pHead) + 1);
  List_Insert(pHead, List_Length(pHead) + 1, 99);
  List_Show(pHead);
  printf("循环单链表长度：%d\n\n", List_Length(pHead));

  printf("删除位序为1(头删)\n");
  List_Del(pHead, 1);
  List_Show(pHead);
  printf("循环单链表长度：%d\n\n", List_Length(pHead));

  printf("删除位序为%d(尾删)\n", List_Length(pHead));
  List_Del(pHead, List_Length(pHead));
  List_Show(pHead);
  printf("循环单链表长度：%d\n\n", List_Length(pHead));

  printf("获取值为：5的结点位序\n");
  int i = -1; // -1 为未找到
  LNode* p5 = List_Get_Elem(pHead, 5, i);
  printf("值为5的结点位序为：%d\n\n", p5 != NULL ? i : -1);

  printf("循环单链表判空：%s\n", List_Empty(pHead) ? "空" : "非空");

  // 尾插法创建
  LinkList pHead1;
  List_Init(pHead1);

  List_Create_Tail_Insert(pHead1);
  printf("尾插法创建循环单链表：\n");
  List_Show(pHead1);
  return 0;
}