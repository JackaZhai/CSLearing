#include <iostream>
using namespace std;
// 定义双链表结构
typedef struct DNode {
  int data; // 数据
  struct DNode *prior, *next; // 前驱和后继指针
} DNode, *DLinkList;

// 初始化链表
bool DList_Init (DLinkList &pHead) {
  pHead = (DNode *) malloc(sizeof(DNode)); // 创建头结点
  if (pHead == NULL) return false; // 内存不足，分配失败
  pHead->prior = NULL; // 普通双链表头结点 prior 始终指向 NULL
  pHead->next = NULL;
  return true;
}

// 判断双链表是否为空（带头节点）
bool DList_Empty (DLinkList pHead) {
  return pHead->next == NULL;
}

// 获取链表有效数据节点个数
int DList_Length (DLinkList pHead)
{
  int count = 0;
  for (DNode *p = pHead->next; p != NULL; p = p->next)
  count++;
  return count;
}


// 创建双链表，头插结果为倒叙（带头节点）
DLinkList DList_Create(DLinkList &pHead) {
  DNode *pTemp; int x;
  scanf("%d", &x);
  while (x != 999) {
    pTemp = (DNode *)malloc(sizeof(DNode));
    pTemp->data = x;
    pTemp->next = pHead->next;
    pTemp->prior = pHead;
    // 不是空链表
    if (pHead->next != NULL) {
      pHead->next->prior = pTemp;
    }
    pHead->next = pTemp;
    scanf("%d", &x);
  }
  return pHead;
}

// 按位序插入，i=1插在表头，i=length+1插在表尾
bool DList_Insert(DLinkList &pHead, int i, int e) {
  if (i < 1 || i > DList_Length(pHead) + 1) return false;
  int j = 0; // 当前p指向的是第几个结点
  DNode *p = pHead; // p 指向头结点
  while (p != NULL && j < i - 1) { // 循环找到要插入位置的前驱结点
    p = p->next;
    j++;
  }
  DNode *pTemp = (DNode *)malloc(sizeof(DNode));
  pTemp->data = e;
  pTemp->next = p->next;
  pTemp->prior = p;
  // 又后续结点，不是空链表
  if (p->next != NULL) {
    p->next->prior = pTemp;
  }
  p->next = pTemp;
  return true;
}


// 通过值获取结点和其位序
DNode* DList_Get_Elem (DLinkList pHead, int e, int &i) {
  i = 1;
  DNode *p = pHead->next;
  while(p != NULL && p->data != e) {
    p = p->next;
    i = i + 1;
  }
  return p;
}


// 按位序删除，i=1删表头，i=length删头尾
bool DList_Del (DLinkList &pHead, int i) {
  if (i < 1 || i > DList_Length(pHead)) return false;
  DNode *p = pHead;
  // 找到待删除位序的前一位结点
  for (int j = 0; j < i - 1; j++)
    p = p->next;
 
  DNode *q = p->next; // 待删除结点
  p->next = q->next;
  if (q->next != NULL)
    q->next->prior = p;
  free(q);
  return true;
}


// 打印链表所有值
void DList_Show (DLinkList pHead) {
  DNode *node = pHead->next;
  printf("链表值(从头遍历)：");
  while (node != NULL) {
    printf("%d、", node->data);
    node = node->next;
  }
  printf("\n");
}

// 打印链表所有值，从尾到头
void DList_Show_Back (DLinkList pHead) {
  DNode *node = pHead;
  // 先找到尾结点
  while (node->next != NULL) {
    node = node->next;
  }
  printf("链表值(从尾遍历)：");
  while (node->prior != NULL) { // 跳过头结点
    printf("%d、", node->data);
    node = node->prior;
  }
  printf("\n");
}


int main() {
  DLinkList pHead;
  DList_Init(pHead);
  printf("链表判空：%s\n", DList_Empty(pHead) ? "空" : "非空");

  DList_Create(pHead);
  DList_Show(pHead);
  DList_Show_Back(pHead);
  printf("链表长度：%d\n\n", DList_Length(pHead));

  printf("位序为1(头插)，插入：0\n");
  DList_Insert(pHead, 1, 0);
  DList_Show(pHead);
  printf("链表长度：%d\n\n", DList_Length(pHead));

  printf("位序为%d(尾插)，插入：99\n", DList_Length(pHead) + 1);
  DList_Insert(pHead, DList_Length(pHead) + 1, 99);
  DList_Show(pHead);
  printf("链表长度：%d\n\n", DList_Length(pHead));

  printf("删除位序为1(头删)\n");
  DList_Del(pHead, 1);
  DList_Show(pHead);
  DList_Show_Back(pHead);
  printf("链表长度：%d\n\n", DList_Length(pHead));
  
  printf("删除位序为%d(尾删)\n", DList_Length(pHead));
  DList_Del(pHead, DList_Length(pHead));
  DList_Show(pHead);
  DList_Show_Back(pHead);
  printf("链表长度：%d\n\n", DList_Length(pHead));

  printf("获取值为：5的结点位序\n");
  int i = -1; // -1 为未找到
  DNode * p5 = DList_Get_Elem(pHead, 5, i);
  printf("值为5的结点位序为：%d\n\n", p5 != NULL ? i : -1);

  printf("链表判空：%s\n", DList_Empty(pHead) ? "空" : "非空");
  return 0;
}