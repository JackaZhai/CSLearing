#include <stdio.h>
#define MAX_SIZE 7

typedef int ElemType;

// 定义静态链表结点
typedef struct {
  ElemType data; // 数据元素
  // 下一个结点的索引
  // -1 表示当前结点是链表的尾结点
  // -2，则表示当前结点是空闲结点
  int next;
} SLinkList[MAX_SIZE];


// 初始化静态链表
void Initialize(SLinkList list) {
  // 0号结点充当“头结点”，不具体存放数据
  list[0].next = -1;

  // 初始化其他结点的next为特殊值-2，表示结点空闲
  for (int i = 1; i < MAX_SIZE; i++) {
    list[i].next = -2;
  }
}


// 插入操作
int Insert(SLinkList list, int position, ElemType data) {
  // 找到一个空闲结点
  int freeNode = -1;
  for (int i = 1; i < MAX_SIZE; i++) {
    if (list[i].next == -2) {
      freeNode = i;
      break;
    }
  }

  // 如果没有空闲结点，插入失败
  if (freeNode == -1) {
    printf("插入失败，静态链表已满\n");
    return 0;
  }

  int current = 0; // 从头结点开始
  int count = 0;

  // 找到要插入位置的前一个结点
  // 直到找到前一个结点或者达到链表的末尾
  while (count < position && list[current].next != -1) {
    current = list[current].next;
    count++;
  }

  // 插入新结点
  list[freeNode].data = data; // 将数据存储在新结点
  list[freeNode].next = list[current].next; // 将新结点指向原位置的下一个结点
  list[current].next = freeNode; // 更新前一个结点的指向，使其指向新结点

  return 1;
}


// 按值查找操作
int FindByValue(SLinkList list, ElemType value) {
  int current = list[0].next; // 从第一个数据结点开始
  int position = 1; // 初始化位置

  while (current != -1) {
    // 比较当前结点的数据与目标值
    if (list[current].data == value) {
      // 找到匹配值，返回位置
      return position;
    }

    // 没有找到，继续遍历下一个结点
    current = list[current].next;
    position++;
  }

  // 没有找到匹配值，返回 -1 表示未找到
  return -1;
}


// 删除操作
int Delete(SLinkList list, int position) {
  int current = 0; // 从头结点开始
  int count = 0;

  // 找到要删除位置的前一个结点
  // 直到找到前一个结点或者达到链表的末尾
  while (count < position && list[current].next != -1) {
    current = list[current].next; // 移动到下一个结点
    count++;
  }

  // 判断是否找到要删除的位置
  if (list[current].next == -1 || count < position) {
    printf("删除失败，位置无效\n");
    return 0;
  }

  // 要删除的结点
  int toBeDeleted = list[current].next;

  // 更新前一个结点的指向，跳过要删除的结点
  list[current].next = list[toBeDeleted].next;

  // 标记要删除的结点为空闲结点
  list[toBeDeleted].data = NULL;
  list[toBeDeleted].next = -2;

  return 1;
}


// 输出静态链表
void PrintList(SLinkList list) {
  int current = list[0].next; // 从第一个数据结点开始
  while (current != -1) {
    printf("%d ", list[current].data);
    current = list[current].next;
  }
  printf("\n");
}


int main() {
  SLinkList list;
  Initialize(list);

  Insert(list, 0, 10);
  Insert(list, 1, 20);
  Insert(list, 1, 30);
  Insert(list, 3, 40);

  printf("静态链表内容：\n");
  PrintList(list);

  Delete(list, 1);
  printf("删除第2个元素后的静态链表内容：\n");
  PrintList(list);

  return 0;
}