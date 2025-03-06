#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

#define MAX_SIZE 10 // 定义最大长度

//顺序表结构体

// 初始化顺序表

// 在 L 的位序 i 处插入元素 e
// 注意区分【位序】和【下标】，位序从1开始，下标从0开始

// 删除顺序表 L 的位序 i，并使用 e 返回删除的值

// 按位序查找，返回的为 值

// 按值查找，返回的为位序

//打印顺序表

// 在尾部插入

// 数组
// int main () {
//   // 声明一个顺序表
//   SqList L;
//   // 初始化顺序表
//   InitList(L);

//   ListInsert(L, 1, 1);
//   ListInsert(L, 1, 2);
//   ListInsert(L, 1, 3);
//   ListInsert(L, 1, 4);
//   // 超出 length，并没有插入成功
//   ListInsert(L, 8, 7);
//   ListPrint(L);

//   int delValue;
//   ListDelete(L, 1, delValue);
//   cout<<"删除的值:"<<delValue<<endl;
//   ListPrint(L);

//   cout<<"位序为2的值: "<<ListGetElem (L, 2)<<endl;
//   ListInsertTail (L, 5);
//   cout<<"值为5的位序: "<<ListLocateElem (L, 5)<<endl;
//   ListPrint(L);
//   return 0;
// }

// 链表的结构体

// 初始化链表

// 判断单链表是否为空

// 获取单链表有效数据节点个数

// 创建链表，头插结果为倒叙

// 按位序插入，i=1插在表头，i=length+1插在表尾

// 通过值获取结点和位序

// 按位序删除，i=1删表头，i=length删头尾

// 打印链表所有值

// 不带头结点的单链表
// int main () {
//     LinkList pHead;
//     List_Init(pHead);
//     printf("链表判空：%s\n", List_Empty(pHead) ? "空" : "非空");
//     List_Create(pHead);
//     List_Show(pHead);
//     printf("链表长度：%d\n\n", List_Length(pHead));

//     printf("位序为1(头插)，插入：0\n");
//     List_Insert(pHead, 1, 0);
//     List_Show(pHead);
//     printf("链表长度：%d\n\n", List_Length(pHead));
    
//     printf("位序为%d(尾插)，插入：99\n", List_Length(pHead) + 1);
//     List_Insert(pHead, List_Length(pHead) + 1, 99);
//     List_Show(pHead);
//     printf("链表长度：%d\n\n", List_Length(pHead));

//     printf("删除位序为1(头删)\n");
//     List_Del(pHead, 1);
//     List_Show(pHead);
//     printf("链表长度：%d\n\n", List_Length(pHead));
    
//     printf("删除位序为%d(尾插)\n", List_Length(pHead));
//     List_Del(pHead, List_Length(pHead));
//     List_Show(pHead);
//     printf("链表长度：%d\n\n", List_Length(pHead));

//     printf("获取值为：5的结点位序\n");
//     int i = -1; // -1 为未找到
//     LNode * p5 = List_Get_Elem(pHead, 5, i);
//     printf("值为5的结点位序为：%d\n\n", i);

//     printf("链表判空：%s\n", List_Empty(pHead) ? "空" : "非空");
//     return 0;
// }

// 带头结点的单链表

// 结构体

// 初始化链表

// 判断单链表是否为空

// 获取单链表有效数据节点个数

//创建链表，头插法结果为倒叙

// 创建链表-通过尾插法

// 按位序插入，i=1插在表头，i=length+1插在表尾

// 通过值获取结点和其位序

// 按位序删除，i=1删表头，i=length删头尾

// 打印链表所有值

// int main () {
//   LinkList pHead;
//   List_Init(pHead);
//   printf("链表判空：%s\n", List_Empty(pHead) ? "空" : "非空");

//   // 头插法创建
//   List_Create(pHead);
//   List_Show(pHead);
//   printf("链表长度：%d\n\n", List_Length(pHead));

//   printf("位序为1(头插)，插入：0\n");
//   List_Insert(pHead, 1, 0);
//   List_Show(pHead);
//   printf("链表长度：%d\n\n", List_Length(pHead));
  
//   printf("位序为%d(尾插)，插入：99\n", List_Length(pHead) + 1);
//   List_Insert(pHead, List_Length(pHead) + 1, 99);
//   List_Show(pHead);
//   printf("链表长度：%d\n\n", List_Length(pHead));

//   printf("删除位序为1(头删)\n");
//   List_Del(pHead, 1);
//   List_Show(pHead);
//   printf("链表长度：%d\n\n", List_Length(pHead));
  
//   printf("删除位序为%d(尾删)\n", List_Length(pHead));
//   List_Del(pHead, List_Length(pHead));
//   List_Show(pHead);
//   printf("链表长度：%d\n\n", List_Length(pHead));

//   printf("获取值为：5的结点位序\n");
//   int i = -1; // -1 为未找到
//   LNode * p5 = List_Get_Elem(pHead, 5, i);
//   printf("值为5的结点位序为：%d\n\n", p5 != NULL ? i : -1);

//   printf("链表判空：%s\n", List_Empty(pHead) ? "空" : "非空");

//   // 尾插法创建
//   LinkList pHead1;
//   List_Init(pHead1);

//   List_Create_Tail_Insert(pHead1);
//   printf("尾插法创建链表：\n");
//   List_Show(pHead1);
//   return 0;
// }

// 双链表-不带头节点
// 结构体

// 初始化链表

// 判断双链表是否为空

// 获取双链表有效数据节点个数

// 创建双链表，头插结果为倒序

// 按位序插入，i=1插在表头，i=length+1插在表尾

// 通过值获取结点和其位序

// 按位序删除，i=1删表头，i=length删头尾

// 打印链表所有值

// 打印链表所有值，从尾到头
// 双链表是可以走回头路的，所以可以从最后一个结点往前遍历

// int main() {
//   DLinkList pHead;
//   DList_Init(pHead);
//   printf("链表判空：%s\n", DList_Empty(pHead) ? "空" : "非空");

//   DList_Create(pHead);
//   DList_Show(pHead);
//   DList_Show_Back(pHead);
//   printf("链表长度：%d\n\n", DList_Length(pHead));

//   printf("位序为1(头插)，插入：0\n");
//   DList_Insert(pHead, 1, 0);
//   DList_Show(pHead);
//   printf("链表长度：%d\n\n", DList_Length(pHead));

//   printf("位序为%d(尾插)，插入：99\n", DList_Length(pHead) + 1);
//   DList_Insert(pHead, DList_Length(pHead) + 1, 99);
//   DList_Show(pHead);
//   printf("链表长度：%d\n\n", DList_Length(pHead));

//   printf("删除位序为1(头删)\n");
//   DList_Del(pHead, 1);
//   DList_Show(pHead);
//   DList_Show_Back(pHead);
//   printf("链表长度：%d\n\n", DList_Length(pHead));

//   printf("删除位序为%d(尾删)\n", DList_Length(pHead));
//   DList_Del(pHead, DList_Length(pHead));
//   DList_Show(pHead);
//   DList_Show_Back(pHead);
//   printf("链表长度：%d\n\n", DList_Length(pHead));

//   printf("获取值为：5的结点位序\n");
//   int i = -1;
//   DNode *p5 = DList_Get_Elem(pHead, 5, i);
//   printf("值为5的结点位序为：%d\n\n", p5 != NULL ? i : -1);

//   printf("链表判空：%s\n", DList_Empty(pHead) ? "空" : "非空");
//   return 0;
// }

// 双链表-带头节点
// 结构体

// 初始化链表

// 判断双链表是否为空

// 获取双链表有效数据节点个数

// 创建双链表，头插结果为倒叙（带头节点）

// 按位序插入，i=1插在表头，i=length+1插在表尾

// 通过值获取结点和其位序

// 按位序删除，i=1删表头，i=length删头尾

// 打印链表所有值

// 打印链表所有值，从尾到头

// int main() {
//   DLinkList pHead;
//   DList_Init(pHead);
//   printf("链表判空：%s\n", DList_Empty(pHead) ? "空" : "非空");

//   DList_Create(pHead);
//   DList_Show(pHead);
//   DList_Show_Back(pHead);
//   printf("链表长度：%d\n\n", DList_Length(pHead));

//   printf("位序为1(头插)，插入：0\n");
//   DList_Insert(pHead, 1, 0);
//   DList_Show(pHead);
//   printf("链表长度：%d\n\n", DList_Length(pHead));

//   printf("位序为%d(尾插)，插入：99\n", DList_Length(pHead) + 1);
//   DList_Insert(pHead, DList_Length(pHead) + 1, 99);
//   DList_Show(pHead);
//   printf("链表长度：%d\n\n", DList_Length(pHead));

//   printf("删除位序为1(头删)\n");
//   DList_Del(pHead, 1);
//   DList_Show(pHead);
//   DList_Show_Back(pHead);
//   printf("链表长度：%d\n\n", DList_Length(pHead));
  
//   printf("删除位序为%d(尾删)\n", DList_Length(pHead));
//   DList_Del(pHead, DList_Length(pHead));
//   DList_Show(pHead);
//   DList_Show_Back(pHead);
//   printf("链表长度：%d\n\n", DList_Length(pHead));

//   printf("获取值为：5的结点位序\n");
//   int i = -1; // -1 为未找到
//   DNode * p5 = DList_Get_Elem(pHead, 5, i);
//   printf("值为5的结点位序为：%d\n\n", p5 != NULL ? i : -1);

//   printf("链表判空：%s\n", DList_Empty(pHead) ? "空" : "非空");
//   return 0;
// }

// 循环单链表
// 结构体

// 初始化链表

// 判断循环单链表是否为空

// 获取循环单链表有效数据节点个数

// 创建循环单链表，头插结果为倒叙

// 创建循环单链表-通过尾插法

// 按位序插入，i=1插在表头，i=length+1插在表尾

// 通过值获取结点和其位序

// 按位序删除，i=1删表头，i=length删头尾

// 打印循环单链表所有值

// int main() {
//   LinkList pHead;
//   List_Init(pHead);
//   printf("循环单链表判空：%s\n", List_Empty(pHead) ? "空" : "非空");

//   // 头插法创建
//   List_Create(pHead);
//   List_Show(pHead);
//   printf("循环单链表长度：%d\n\n", List_Length(pHead));

//   printf("位序为1(头插)，插入：0\n");
//   List_Insert(pHead, 1, 0);
//   List_Show(pHead);
//   printf("循环单链表长度：%d\n\n", List_Length(pHead));

//   printf("位序为%d(尾插)，插入：99\n", List_Length(pHead) + 1);
//   List_Insert(pHead, List_Length(pHead) + 1, 99);
//   List_Show(pHead);
//   printf("循环单链表长度：%d\n\n", List_Length(pHead));

//   printf("删除位序为1(头删)\n");
//   List_Del(pHead, 1);
//   List_Show(pHead);
//   printf("循环单链表长度：%d\n\n", List_Length(pHead));

//   printf("删除位序为%d(尾删)\n", List_Length(pHead));
//   List_Del(pHead, List_Length(pHead));
//   List_Show(pHead);
//   printf("循环单链表长度：%d\n\n", List_Length(pHead));

//   printf("获取值为：5的结点位序\n");
//   int i = -1; // -1 为未找到
//   LNode* p5 = List_Get_Elem(pHead, 5, i);
//   printf("值为5的结点位序为：%d\n\n", p5 != NULL ? i : -1);

//   printf("循环单链表判空：%s\n", List_Empty(pHead) ? "空" : "非空");

//   // 尾插法创建
//   LinkList pHead1;
//   List_Init(pHead1);

//   List_Create_Tail_Insert(pHead1);
//   printf("尾插法创建循环单链表：\n");
//   List_Show(pHead1);
//   return 0;
// }

// 循环双链表
// 结构体

// 初始化链表

// 判断循环双链表是否为空

// 获取循环双链表有效数据节点个数

// 创建循环双链表，头插结果为倒叙

// 创建循环双链表-通过尾插法

// 按位序插入，i=1插在表头，i=length+1插在表尾

// 通过值获取结点和其位序

// 按位序删除，i=1删表头，i=length删头尾

// 打印循环双链表所有值

// int main() {
//   DLinkList pHead;
//   List_Init(pHead);
//   printf("循环双链表判空：%s", List_Empty(pHead) ? "空" : "非空");

//   // 头插法创建
//   List_Create(pHead);
//   List_Show(pHead);
//   printf("循环双链表长度：%d", List_Length(pHead));

//   printf("位序为1(头插)，插入：0");
//   List_Insert(pHead, 1, 0);
//   List_Show(pHead);
//   printf("循环双链表长度：%d", List_Length(pHead));

//   printf("位序为%d(尾插)，插入：99", List_Length(pHead) + 1);
//   List_Insert(pHead, List_Length(pHead) + 1, 99);
//   List_Show(pHead);
//   printf("循环双链表长度：%d", List_Length(pHead));

//   printf("删除位序为1(头删)");
//   List_Del(pHead, 1);
//   List_Show(pHead);
//   printf("循环双链表长度：%d", List_Length(pHead));

//   printf("删除位序为%d(尾删)", List_Length(pHead));
//   List_Del(pHead, List_Length(pHead));
//   List_Show(pHead);
//   printf("循环双链表长度：%d", List_Length(pHead));

//   printf("获取值为：5的结点位序");
//   int i = -1; // -1 为未找到
//   DNode* p5 = List_Get_Elem(pHead, 5, i);
//   printf("值为5的结点位序为：%d", p5 != NULL ? i : -1);

//   printf("循环双链表判空：%s", List_Empty(pHead) ? "空" : "非空");

//   // 尾插法创建
//   DLinkList pHead1;
//   List_Init(pHead1);

//   List_Create_Tail_Insert(pHead1);
//   printf("尾插法创建循环双链表：");
//   List_Show(pHead1);
//   return 0;
// }

// 静态链表
// 结构体

// 初始化静态链表

// 插入操作

// 按值查找操作

// 删除操作

// 输出静态链表


// int main() {
//   SLinkList list;
//   Initialize(list);

//   Insert(list, 0, 10);
//   Insert(list, 1, 20);
//   Insert(list, 1, 30);
//   Insert(list, 3, 40);

//   printf("静态链表内容：\n");
//   PrintList(list);

//   Delete(list, 1);
//   printf("删除第2个元素后的静态链表内容：\n");
//   PrintList(list);

//   return 0;
// }
