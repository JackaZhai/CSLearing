#include <stdio.h>
#include <stdlib.h>
typedef struct LNode {
    int data;
    struct LNode * next;
} LNode, *LinkList;

// 初始化链表
bool List_Init (LinkList &pHead) {
    pHead = NULL;
    return true;
}

// 判断单链表是否为空
bool List_Empty (LinkList pHead) {
    return pHead == NULL;
}

// 获取单链表有效数据节点个数
int List_Length (LinkList pHead)
{
  int count = 0;
  for (LNode *p = pHead; p != NULL; p = p->next)
    count++;
  return count;
}

// 创建链表，头插结果为倒叙
LinkList List_Create(LinkList &pHead) {
    LNode *pTemp; int x;
    scanf("%d", &x);
    while (x != 999) {
        pTemp = (LNode *)malloc(sizeof(LNode));
        pTemp->data = x;
        pTemp->next = pHead;
        pHead = pTemp;
        scanf("%d", &x);
    }
    return pHead;
}

// 按位序插入，i=1插在表头，i=length+1插在表尾
bool List_Insert(LinkList &pHead, int i, int e) {
    if (i < 1 || i > List_Length(pHead) + 1) return false;
    LNode *pTemp = (LNode *)malloc(sizeof(LNode));
    if (i == 1) { // 插入第1个结点的操作
        pTemp->data = e;
        pTemp->next = pHead;
        pHead = pTemp;
        return true;
    }
    LNode *p; // 指针p指向的为当前扫描到的结点
    int j = 1; // 当前p指向的是第几个结点
    p = pHead; // p 指向第1个结点（注意：不是头节点）
    while (p != NULL && j < i - 1) { // 循环找到要插入位置的前驱结点
        p = p->next;
        j++;
    }
    pTemp->data = e;
    pTemp->next = p->next;
    p->next = pTemp;
    return true;
}

// 通过值获取结点和位序
LNode* List_Get_Elem (LinkList pHead, int e, int &i) {
  i = 1;
  LNode *p = pHead;
  while(p != NULL && p->data != e) {
      p = p->next;
      i = i + 1;
  }
  return p;
}


// 按位序删除，i=1删表头，i=length删头尾
bool List_Del (LinkList &pHead, int i) {
    if (i < 1 || i > List_Length(pHead)) return false;
    LNode *p = pHead; // p 指向表头
    if (i == 1) { // 删除第一个结点
        pHead = p->next;
        free(p);
        return true;
    }
    // 找到待删除位序的前一位结点，i==1已处理，故从j=2开始
    for (int j = 2; j < i; j++)
        p = p->next;
    LNode *q = p->next; // 待删除结点
    p->next = q->next; // p->next q q->next 跳过q
    free(q);
    return true;
}


// 打印链表所有值
void List_Show (LinkList pHead) {
    LNode *node = pHead;
    printf("链表值：");
    do {
      printf("%d、", node->data);
      node = node->next;
    } while(node != NULL);
    printf("\n");
}

int main () {
    LinkList pHead;
    List_Init(pHead);
    printf("链表判空：%s\n", List_Empty(pHead) ? "空" : "非空");
    List_Create(pHead);
    List_Show(pHead);
    printf("链表长度：%d\n\n", List_Length(pHead));

    printf("位序为1(头插)，插入：0\n");
    List_Insert(pHead, 1, 0);
    List_Show(pHead);
    printf("链表长度：%d\n\n", List_Length(pHead));
    
    printf("位序为%d(尾插)，插入：99\n", List_Length(pHead) + 1);
    List_Insert(pHead, List_Length(pHead) + 1, 99);
    List_Show(pHead);
    printf("链表长度：%d\n\n", List_Length(pHead));

    printf("删除位序为1(头删)\n");
    List_Del(pHead, 1);
    List_Show(pHead);
    printf("链表长度：%d\n\n", List_Length(pHead));
    
    printf("删除位序为%d(尾插)\n", List_Length(pHead));
    List_Del(pHead, List_Length(pHead));
    List_Show(pHead);
    printf("链表长度：%d\n\n", List_Length(pHead));

    printf("获取值为：5的结点位序\n");
    int i = -1; // -1 为未找到
    LNode * p5 = List_Get_Elem(pHead, 5, i);
    printf("值为5的结点位序为：%d\n\n", i);

    printf("链表判空：%s\n", List_Empty(pHead) ? "空" : "非空");
    return 0;
}
