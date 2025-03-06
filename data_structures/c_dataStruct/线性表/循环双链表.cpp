#include <stdio.h>
#include <stdlib.h>

typedef struct DNode {
  int data;
  struct DNode* next;
  struct DNode* prior;
} DNode, *DLinkList;

// 初始化循环双链表
bool List_Init(DLinkList& pHead) {
  pHead = (DNode*)malloc(sizeof(DNode));
  if (pHead == NULL) return false;
  pHead->next = pHead;
  pHead->prior = pHead;
  return true;
}

// 判断循环双链表是否为空
bool List_Empty(DLinkList pHead) {
  return pHead->next == pHead;
}

// 获取循环双链表有效数据节点个数
int List_Length(DLinkList pHead) {
  int count = 0;
  DNode* p = pHead->next;
  while (p != pHead) {
    count++;
    p = p->next;
  }
  return count;
}


// 创建循环双链表，头插法结果为倒叙
DLinkList List_Create(DLinkList& pHead) {
  DNode* pTemp; int x;
  scanf("%d", &x);
  while (x != 999) {
    pTemp = (DNode*)malloc(sizeof(DNode));
    pTemp->data = x;
    pTemp->next = pHead->next;
    pTemp->prior = pHead;

    // 仅当链表为空时 pHead的next的prior指向的pHead自身
    pHead->next->prior = pTemp;
    pHead->next = pTemp;
    scanf("%d", &x);
  }
  return pHead;
}


// 创建循环双链表-通过尾插法
DLinkList List_Create_Tail_Insert(DLinkList& pHead) {
  DNode* pTemp;
  DNode* pTail = pHead;
  int x;
  scanf("%d", &x);
  while (x != 999) {
    pTemp = (DNode*)malloc(sizeof(DNode));
    pTemp->data = x;
    pTemp->next = pHead;
    pTemp->prior = pTail;
    pTail->next = pTemp;
    pHead->prior = pTemp;
    pTail = pTemp;
    scanf("%d", &x);
  }
  return pHead;
}


// 按位序插入，i=1插在表头，i=length+1插在表尾
bool List_Insert(DLinkList& pHead, int i, int e) {
  if (i < 1 || i > List_Length(pHead) + 1) return false;
  int j = 0;
  DNode* p = pHead;
  while (p != NULL && j < i - 1) {
    p = p->next;
    j++;
  }
  DNode* pTemp = (DNode*)malloc(sizeof(DNode));
  pTemp->data = e;
  pTemp->next = p->next;
  pTemp->prior = p;
  p->next->prior = pTemp;
  p->next = pTemp;
  return true;
}


// 通过值获取结点和其位序
DNode* List_Get_Elem(DLinkList pHead, int e, int& i) {
  i = 1;
  DNode* p = pHead->next;
  while (p != pHead && p->data != e) {
      p = p->next;
      i++;
  }
  if (p == pHead) return NULL;
  return p;
}



// 按位序删除，i=1删表头，i=length删头尾
bool List_Del(DLinkList& pHead, int i) {
  if (i < 1 || i > List_Length(pHead)) return false;
  DNode* p = pHead;
  
  for (int j = 0; j < i - 1; j++)
      p = p->next;
  DNode* q = p->next;
  p->next = q->next;
  q->next->prior = p;
  free(q);
  return true;
}



// 打印循环双链表所有值
void List_Show(DLinkList pHead) {
  DNode* node = pHead->next;
  printf("循环双链表值：");
  while (node != pHead) {
      printf("%d、", node->data);
      node = node->next;
  }
  printf("");
}

int main() {
  DLinkList pHead;
  List_Init(pHead);
  printf("循环双链表判空：%s", List_Empty(pHead) ? "空" : "非空");

  // 头插法创建
  List_Create(pHead);
  List_Show(pHead);
  printf("循环双链表长度：%d", List_Length(pHead));

  printf("位序为1(头插)，插入：0");
  List_Insert(pHead, 1, 0);
  List_Show(pHead);
  printf("循环双链表长度：%d", List_Length(pHead));

  printf("位序为%d(尾插)，插入：99", List_Length(pHead) + 1);
  List_Insert(pHead, List_Length(pHead) + 1, 99);
  List_Show(pHead);
  printf("循环双链表长度：%d", List_Length(pHead));

  printf("删除位序为1(头删)");
  List_Del(pHead, 1);
  List_Show(pHead);
  printf("循环双链表长度：%d", List_Length(pHead));

  printf("删除位序为%d(尾删)", List_Length(pHead));
  List_Del(pHead, List_Length(pHead));
  List_Show(pHead);
  printf("循环双链表长度：%d", List_Length(pHead));

  printf("获取值为：5的结点位序");
  int i = -1; // -1 为未找到
  DNode* p5 = List_Get_Elem(pHead, 5, i);
  printf("值为5的结点位序为：%d", p5 != NULL ? i : -1);

  printf("循环双链表判空：%s", List_Empty(pHead) ? "空" : "非空");

  // 尾插法创建
  DLinkList pHead1;
  List_Init(pHead1);

  List_Create_Tail_Insert(pHead1);
  printf("尾插法创建循环双链表：");
  List_Show(pHead1);
  return 0;
}