#include <stdio.h>
#include <stdlib.h>

#define MaxVertexNum 26
// 是否为有向图
#define DIRECTED true
typedef char VertexType;
typedef int ArcWeight;

// 边表结点
typedef struct ArcNode {
  int adjvex; // 该边指向的顶点下标
  ArcWeight weight; // 权值
  struct ArcNode *next; // 指向下一条边的指针
} ArcNode;

// 顶点表结点
typedef struct VNode{
  VertexType data; // 顶点信息
  ArcNode *first; // 指向该顶点的第一条边的指针
} VNode, AdjList[MaxVertexNum];

// 邻接表的图结构
typedef struct {
  AdjList adjList; // 邻接表
  int vexnum, arcnum; // 图的顶点数和边数
} ALGraph;

// 队列-广度

// 循环队列算法，辅助完成二叉树层次遍历
#define MaxSize 50   // 定义队列中元素的最大个数
typedef struct {
  int data[MaxSize]; // 存放队列元素
  int front, rear;   // 队头和队尾指针 
} SqQueue;

// 初始化队列（带头结点）
void Queue_Init(SqQueue &Q) {
  Q.rear = Q.front = 0;
}

// 判断队列是否为空
bool Queue_Empty(SqQueue Q) {
  return Q.front == Q.rear;
}

// 入队
bool Queue_En(SqQueue &Q, int e) {
  if ((Q.rear + 1) % MaxSize == Q.front) return false; // 队满则报错
  Q.data[Q.rear] = e;
  Q.rear = (Q.rear + 1) % MaxSize; // 队尾指针加 1 取模
  return true;
}

// 出队
bool Queue_De(SqQueue &Q, int &e) {
  if (Queue_Empty(Q)) return false; // 队空则报错
  e = Q.data[Q.front];
  Q.front = (Q.front + 1) % MaxSize;
  return true;
}


void ALGraph_Create (ALGraph &G) {
  // 对顶点表结点进行初始化
  for (int i = 0; i < MaxVertexNum; i++) {
    G.adjList[i].first = NULL;
  }
  printf("输入顶点 边个数（空格间隔）：");
  scanf("%d %d", &G.vexnum, &G.arcnum);
  // 建立顶点表
  for (int i = 0; i < G.vexnum; i++) {
    printf("请输入第%d个顶点的值：", i + 1);
    scanf(" %c", &G.adjList[i].data);
    G.adjList[i].first = NULL;
  }
  // 建立边表
  int vi, vj;
  ArcWeight weight;
  printf("下标为 -1 -1 则退出创建边\n");
  for (int i = 0; i < G.arcnum; i++) {
    // 代表两个顶点 vi 指向 vj 的边，注意vi vj是从0开始的
    printf("请输入要创建边的两个顶点 vi vj ");
    scanf("%d %d", &vi, &vj);
    if (vi == -1 && vj == -1) break;
    printf("请输入边为[%d->%d]的权值 weight = ", vi, vj);
    scanf("%d", &weight);
    ArcNode *arcNode;
    arcNode = (ArcNode *)malloc(sizeof(ArcNode));
    // 通过头插法插入新边，
    arcNode->next = G.adjList[vi].first;
    arcNode->adjvex = vj; // 该边指向的顶点位置
    arcNode->weight = weight;
    G.adjList[vi].first = arcNode;
    // 如果是无向图，则还需要创建相反方向的边
    if (!DIRECTED) {
      ArcNode *arcNode2;
      arcNode2 = (ArcNode *)malloc(sizeof(ArcNode));
      // 相反方向，放入vj里 头插
      arcNode2->next = G.adjList[vj].first;
      arcNode2->adjvex = vi;
      arcNode2->weight = weight;
      G.adjList[vj].first = arcNode2;
    }
  }
}


// 访问标记数组
bool BFSVisited[MaxVertexNum];
// 对图G进行广度优先遍历
// 注意：对邻接表进行广度优先遍历的结果并不唯一
void BFS (ALGraph G, int v) { // 从顶点V出发，广度优先遍历图G
  for (int i = 0; i < G.vexnum; i++)
    BFSVisited[i] = false;
  SqQueue Q;
  Queue_Init(Q); // 初始化辅助队列Q
  Queue_En(Q, v); // 将顶点 v 的下标入队
  // 访问初始顶点 V
  printf("\n对顶点【%d】进行广度优先遍历：", v);
  BFSVisited[v] = true; // 对 v 进行已访问标记
  ArcNode *p;
  while (Queue_Empty(Q) == false) { // 当队列非空时
    Queue_De(Q, v); // 将队头元素出队并送到 v 中
    p = G.adjList[v].first; // 指针 p 指向顶点 v 的边表
    while (p != NULL) {
      // 遍历该顶点的出边表
      if (BFSVisited[p->adjvex] == false) {
        printf("%d、", p->adjvex); // 访问顶点
        BFSVisited[p->adjvex] = true;
        Queue_En(Q, p->adjvex); // 将顶点下标入队
      }
      p = p->next;
    }
  }
}

// 对整个图进行遍历
void BFS_Traverse (ALGraph G) {
  for (int i = 0; i < G.vexnum; i++)
    BFS(G, i);
}


// 访问标记数组
bool DFSVisited[MaxVertexNum];
// 深度优先遍历
// 注意：对邻接表进行深度优先遍历的结果并不唯一
void DFS (ALGraph G, int v) {
  ArcNode *p;
  p = G.adjList[v].first;
  printf("%d、", v);
  DFSVisited[v] = true;
  while (p) {
    int j = p->adjvex;
    if (DFSVisited[j] == false) {
      DFS(G, j);
    }
    p = p->next;
  }
}
// 对整个图进行遍历
void DFS_Traverse (ALGraph G) {
  for (int i = 0; i < G.vexnum; i++) {
    // 从顶点V出发，深度优先遍历图G
    for (int j = 0; j < G.vexnum; j++)
      DFSVisited[j] = false;

    printf("\n对顶点【%d】进行深度优先遍历：", i);
    DFS(G, i);
  }
}


void ALGraph_Show (ALGraph G) {
  for (int i = 0; i < G.vexnum; i++) {
    printf("%c", G.adjList[i].data);
    ArcNode *p = G.adjList[i].first;
    while (p) {
      printf("->%d", p->adjvex);
      p = p->next;
    }
    printf("\n");
  }
}

int main () {
  printf("注意，当前创建图为有向图\n");
  ALGraph G;
  ALGraph_Create(G);
  ALGraph_Show(G);
  BFS_Traverse(G);
  DFS_Traverse(G);
  return 0;
}s