#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

#define MAX_SIZE 10 // 定义最大长度

//顺序表结构体
typedef struct {
    int data[MAX_SIZE];
    int length;
} SqList;

// 初始化顺序表
void InitList(SqList &L){
    L.length = 0;
}

// 在 L 的位序 i 处插入元素 e
// 注意区分【位序】和【下标】，位序从1开始，下标从0开始
void ListInsert(SqList &L,int i,int e){
    if (i<1 || i>L.length+1){
        cout<<"位序不合法"<<endl;
        return;
    }
    if (L.length==MAX_SIZE){
        cout<<"超过最大值"<<endl;
        return;
    }
    for (int j=L.length;j>i-1;j--){
        L.data[j]=L.data[j-1];
    }
    L.data[i-1] = e;
    L.length++;
    return;
}

// 删除顺序表 L 的位序 i，并使用 e 返回删除的值
void ListDelete(SqList &L,int i,int &e){
    if (i<1 || i>L.length){
        cout<<"位序不合法"<<endl;
        return;
    }
    e=L.data[i-1];
    for (int j=i-1;j<L.length;j++){
        L.data[j] = L.data[j+1];
    }
    L.length --;
    return;
}

// 按位序查找，返回的为 值
int ListGetElem (SqList L, int i){
    return L.data[i-1];
}
// 按值查找，返回的为位序
int ListLocateElem (SqList L, int e){
    for (int j=0;j<L.length;j++){
        if (L.data[j]==e){
            return j+1;
        }
    }
    return -999;
}

// 打印顺序表
void ListPrint(SqList &L){
    cout<<"当前顺序表的值: ";
    for (int i =0;i<L.length;i++){
        cout<<L.data[i]<<" ";
    }
    cout<<endl;
}
// 在尾部插入
void ListInsertTail (SqList &L, int e){
    if (MAX_SIZE<=L.length){
        cout<<"达到最大值,无法存入!"<<endl;
        return;
    }
    L.data[L.length] = e;
    L.length++;
    return;
}

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

// // 不带头节点的单链表
// // 链表的结构体
// typedef struct LNode{
//     int data;
//     struct LNode *next;
// }LNode,*LinkList;

// // 初始化链表
// void List_Init(LinkList &pHead){
//     pHead = nullptr;
// }

// // 判断单链表是否为空
// bool List_Empty(LinkList &pHead){
//     return pHead == nullptr;
// }

// // 获取单链表有效数据节点个数
// int List_Length(LinkList &pHead){
//     int count = 0;
//     LNode *p = pHead; 
//     while (p != nullptr){
//         p = p -> next ;
//         count ++;
//     }
//     return count;
// }

// // 创建链表，头插结果为倒叙
// LinkList List_Create(LinkList &pHead){
//     LNode *p;
//     int x;
//     scanf("%d",&x);
//     while (x!=999){
//         p = (LNode*)malloc(sizeof(LNode));
//         p ->data = x;
//         p ->next = pHead;
//         pHead = p;
//         scanf("%d",&x);
//     }
//     return pHead;
// }

// // 按位序插入，i=1插在表头，i=length+1插在表尾,位序i,插入数值e
// bool List_Insert(LinkList &pHead, int i, int e) {
//     if (i < 1 || i > List_Length(pHead) + 1) return false;
//     LNode *pTemp = (LNode *)malloc(sizeof(LNode));
//     if (i == 1) { // 插入第1个结点的操作
//         pTemp->data = e;
//         pTemp->next = pHead;
//         pHead = pTemp;
//         return true;
//     }
//     LNode *p; // 指针p指向的为当前扫描到的结点
//     int j = 1; // 当前p指向的是第几个结点
//     p = pHead; // p 指向第1个结点（注意：不是头节点）
//     while (p != NULL && j < i - 1) { // 循环找到要插入位置的前驱结点
//         p = p->next;
//         j++;
//     }
//     pTemp->data = e;
//     pTemp->next = p->next;
//     p->next = pTemp;
//     return true;
// }

// // 通过值获取结点和位序
// LNode* List_Get_Elem (LinkList pHead, int e, int &i){
//   i = 1;
//   LNode *p = pHead;
//   while(p != NULL && p->data != e) {
//       p = p->next;
//       i = i + 1;
//   }
//   return p;
// }


// // 按位序删除，i=1删表头，i=length删头尾
// bool List_Del (LinkList &pHead, int i) {
//     if (i < 1 || i > List_Length(pHead)) return false;
//     LNode *p = pHead; // p 指向表头
//     if (i == 1) { // 删除第一个结点
//         pHead = p->next;
//         free(p);
//         return true;
//     }
//     // 找到待删除位序的前一位结点，i==1已处理，故从j=2开始
//     for (int j = 2; j < i; j++)
//         p = p->next;
//     LNode *q = p->next; // 待删除结点
//     p->next = q->next; // p->next q q->next 跳过q
//     free(q);
//     return true;
// }
   

// // 打印链表所有值
// void List_Show (LinkList pHead) {
//     LNode *node = pHead;
//     printf("链表值：");
//     do {
//       printf("%d、", node->data);
//       node = node->next;
//     } while(node != NULL);
//     printf("");
// }

// //不带头结点的单链表
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
//     LNode* List_Get_Elem (LinkList pHead, int e, int &i);

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
typedef struct LNode {
    int data;
    struct LNode *next;
}LNode,*LinkList;

// 初始化链表
void List_Init(LinkList &pHead){
    pHead = (LNode*)malloc(sizeof(LNode));
    pHead ->next=nullptr ;
    return;
}

// 判断单链表是否为空
bool List_Empty(LinkList pHead){
    return pHead ->next==nullptr;
}

// 获取单链表有效数据节点个数
int List_Length(LinkList pHead){
    int count = 0;
    for (LNode *p=pHead->next;p!=nullptr;p = p->next){
        count ++;
    }
    return count;
}

//创建链表，头插法结果为倒叙
void List_Create(LinkList &pHead){
    LNode *p;int x;
    cin>>x;
    while (x!=999){
        p = (LNode*)malloc(sizeof(LNode));
        p ->data=x;
        p ->next = pHead ->next;
        pHead ->next =p;
        cin>>x;
    }
}

// 创建链表-通过尾插法
void List_Create_Tail_Insert(LinkList &pHead){
    LNode *p;
    LNode *pTail=pHead;
    int x;
    cin>>x;
    while (x!=999){
        p = (LNode*)malloc(sizeof(LNode));
        p ->data = x;
        pTail ->next= p;
        pTail = p;
        cin>>x;
    }
    return;
}

// 按位序插入，i=1插在表头，i=length+1插在表尾
void List_Insert(LinkList &pHead, int i, int e) {
	int j = 0;
	LNode *p = pHead;
	while (p != nullptr && j < i - 1) {
		p = p -> next;
		j++;
	}
	LNode *pTemp = (LNode *)malloc(sizeof(LNode));
	pTemp -> data = e;
	pTemp -> next = p -> next ;
	p ->next = pTemp;
	return;
}


// 通过值获取结点和其位序
LNode *List_Get_Elem (LinkList pHead, int e, int &i) {
	i = 0;
	LNode *p = pHead;//have different need confirm
	while (p != nullptr && p->data != e) {
		++i;
		p = p ->next;
	}
	return p;
}

// 按位序删除，i=1删表头，i=length删头尾
void List_Del (LinkList &pHead, int i) {
	LNode *p = pHead;
	for (int j = 0; j < i - 1; j++) {
		p = p -> next;
	}
	LNode *q = p ->next;
	p -> next = q ->next;
	free(q);
	return;

}

// 打印链表所有值
void List_Show(LinkList pHead) {
	LNode *p = pHead->next;
	printf("链表值： ");
	while (p != nullptr) {
		cout << p -> data << " ";
		p = p->next;
	}
	cout << endl;
}

int main () {
  LinkList pHead;
  List_Init(pHead);
  printf("链表判空：%s\n", List_Empty(pHead) ? "空" : "非空");

  // 头插法创建
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
  
  printf("删除位序为%d(尾删)\n", List_Length(pHead));
  List_Del(pHead, List_Length(pHead));
  List_Show(pHead);
  printf("链表长度：%d\n\n", List_Length(pHead));

  printf("获取值为：5的结点位序\n");
  int i = -1; // -1 为未找到
  LNode * p5 = List_Get_Elem(pHead, 5, i);
  printf("值为5的结点位序为：%d\n\n", p5 != NULL ? i : -1);

  printf("链表判空：%s\n", List_Empty(pHead) ? "空" : "非空");

  // 尾插法创建
  LinkList pHead1;
  List_Init(pHead1);

  List_Create_Tail_Insert(pHead1);
  printf("尾插法创建链表：\n");
  List_Show(pHead1);
  return 0;
}


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
