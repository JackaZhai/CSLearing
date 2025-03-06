#include <stdio.h>
#include<stdlib.h>
using namespace std;

// 定义双链表结构
typedef struct DNode {
  int data; // 数据
  struct DNode *prior, *next; // 前驱和后继指针
} DNode, *DLinkList;

// 初始化链表
bool DList_Init(DLinkList &pHead) {
  pHead = NULL; // 不再创建头结点
  return true;
}

// 判断双链表是否为空（不带头节点）
bool DList_Empty(DLinkList pHead) {
  return pHead == NULL;
}

// 获取链表有效数据节点个数
int DList_Length(DLinkList pHead) {
  int count = 0;
  DNode *p = pHead;
  while (p != NULL) { // 当指针p不为空时，即链表不为空时
    count++;
    p = p->next; // 将指针p移动到下一个节点
  }
  return count;
}


// 创建双链表，头插结果为倒序（不带头节点）
DLinkList DList_Create(DLinkList &pHead) {
  pHead = NULL; // 初始化链表头指针为空，表示链表为空
  int x;
  scanf("%d", &x);
  DNode *pTemp; // 创建一个临时节点指针pTemp
  while (x != 999) {
    pTemp = (DNode *)malloc(sizeof(DNode));
    pTemp->data = x; // 将新节点的数据域设置为x
    pTemp->prior = NULL; // 新节点的prior为空，因为是头插法，头始终为空
    pTemp->next = pHead; // 新节点的next指向链表当前头节点
    if (pHead != NULL) {
      pHead->prior = pTemp; // 设置原头节点的prior指向新节点
    }
    pHead = pTemp; // 更新链表头指针为新节点
    scanf("%d", &x);
  }
  return pHead; // 返回创建好的双链表的头指针
}


// 按位序插入，i=1插在表头，i=length+1插在表尾
bool DList_Insert(DLinkList &pHead, int i, int e) {
  // 检查插入位置的有效性
  if (i < 1 || i > DList_Length(pHead) + 1) return false;
  // 创建一个新节点pTemp并分配内存
  DNode *pTemp = (DNode *)malloc(sizeof(DNode));
  pTemp->data = e;

  // 如果插入位置是链表头
  if (i == 1) {
    pTemp->next = pHead; // 新节点的next指向当前头节点
    pTemp->prior = NULL; // 新节点的prior为空，因为是头插法
    if (pHead != NULL) { // 如果链表不为空
      pHead->prior = pTemp; // 设置原头节点的prior指向新节点
    }
    pHead = pTemp; // 更新链表头指针为新节点
  } else { // 插入位置不在表头
    int j = 1;
    DNode *p = pHead; // 创建一个指针p，指向链表头节点
    while (j < i - 1) { // 循环找到要插入位置的前驱结点
      p = p->next;
      j++;
    }
    pTemp->next = p->next; // 新节点的next指向前驱结点的下一个节点
    pTemp->prior = p;  // 新节点的prior指向前驱结点
    if (p->next != NULL) { // 如果前驱结点的下一个节点存在
      p->next->prior = pTemp; // 设置前驱结点的下一个节点的prior指向新节点
    }
    p->next = pTemp; // 设置前驱结点的next指向新节点
  }
  return true;
}


// 通过值获取结点和其位序
DNode* DList_Get_Elem(DLinkList pHead, int e, int &i) {
  i = 1;
  DNode *p = pHead; // 创建一个指针p，指向链表头节点
  while (p != NULL && p->data != e) { // 循环查找值为e的节点或到达链表尾部
    p = p->next; // 移动到下一个节点
    i++;
  }
  return p;// 返回找到的节点，如果没有找到则返回NULL
}


// 按位序删除，i=1删表头，i=length删头尾
bool DList_Del(DLinkList &pHead, int i) {
   // 检查删除位置的有效性
  if (i < 1 || i > DList_Length(pHead)) return false;

  if (i == 1) { // 如果删除位置是链表头
    DNode *q = pHead; // 创建一个指针q，指向链表头节点
    pHead = pHead->next; // 更新链表头指针为下一个节点
    if (pHead != NULL) { // 如果链表不为空
      pHead->prior = NULL; // 设置新头节点的prior为空
    }
    free(q); // 释放原头节点的内存
  } else { // 删除位置不在表头
    int j = 1;
    DNode *p = pHead; // 创建一个指针p，指向链表头节点
    while (j < i - 1) { // 循环找到要删除位置的前驱结点
      p = p->next; // 移动到下一个节点
      j++; // 增加位置计数器
    }
    DNode *q = p->next; // 创建一个指针q，指向待删除的节点
    p->next = q->next; // 前驱结点的next指向待删除节点的下一个节点
    if (q->next != NULL) { // 如果待删除节点的下一个节点存在
      q->next->prior = p; // 设置待删除节点的下一个节点的prior指向前驱结点
    }
    free(q); // 释放待删除节点的内存
  }
  return true;
}

// 打印链表所有值
void DList_Show(DLinkList pHead) {
  DNode *node = pHead;
  printf("链表值(从头遍历)：");
  while (node != NULL) {
    printf("%d、", node->data);
    node = node->next;
  }
  printf("\n");
}

// 打印链表所有值，从尾到头
// 双链表是可以走回头路的，所以可以从最后一个结点往前遍历
void DList_Show_Back(DLinkList pHead) {
  DNode *node = pHead;
  while (node->next != NULL) {
    node = node->next;
  }
  printf("链表值(从尾遍历)：");
  while (node != NULL) { // 从最后一个节点开始循环，一直到链表头
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
  int i = -1;
  DNode *p5 = DList_Get_Elem(pHead, 5, i);
  printf("值为5的结点位序为：%d\n\n", p5 != NULL ? i : -1);

  printf("链表判空：%s\n", DList_Empty(pHead) ? "空" : "非空");
  return 0;
}