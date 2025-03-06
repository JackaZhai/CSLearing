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

// =========拓扑排序辅助栈
typedef struct {
  int data[MaxVertexNum];
  int top;
} Stack;

// 初始化栈
void Stack_Init(Stack &stack) {
  stack.top = -1;
}

// 栈是否空
int Stack_IsEmpty(Stack stack) {
  return stack.top == -1;
}

// 是否满栈
int Stack_IsFull(Stack stack) {
  return stack.top == MaxVertexNum - 1;
}

// 入栈
void Stack_Push(Stack &stack, int value) {
  if (!Stack_IsFull(stack)) {
    stack.top++;
    stack.data[stack.top] = value;
  } else {
    printf("栈满，不能Push操作\n");
  }
}

// 出栈
int Stack_Pop(Stack &stack) {
  if (!Stack_IsEmpty(stack)) {
    int value = stack.data[stack.top];
    stack.top--;
    return value;
  } else {
    printf("栈为空，不能Pop操作\n");
    return -1; // Indicating an error value
  }
}

// 添加边到图
void ALGraph_AddEdge(ALGraph &graph, int source, int target, ArcWeight weight) {
  ArcNode* newNode = (ArcNode*)malloc(sizeof(ArcNode));
  // 通过头插法插入新边
  newNode->adjvex = target; // 该边指向的顶点位置
  newNode->weight = weight;
  newNode->next = graph.adjList[source].first;
  graph.adjList[source].first = newNode;

  // 如果是无向图，则还需要创建相反方向的边
  if (!DIRECTED) {
    ArcNode* reverseNode = (ArcNode*)malloc(sizeof(ArcNode));
    reverseNode->adjvex = source;
    reverseNode->weight = weight;
    // 相反方向，放入vj里 头插
    reverseNode->next = graph.adjList[target].first;
    graph.adjList[target].first = reverseNode;
  }
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
    ALGraph_AddEdge(G, vi, vj, weight);
  }
}


// 拓扑排序
bool TopologicalSort (ALGraph G) {
  int indegree[MaxVertexNum] = {0}; // 存放每个顶点的入度
  Stack S; // 初始化栈，存储入度为0的顶点
  Stack_Init(S);

  // 计算每个顶点的入度
  for (int i = 0; i < G.vexnum; i++) {
    ArcNode *p = G.adjList[i].first;
    while (p) {
      indegree[p->adjvex]++;
      p = p->next;
    }
  }

  // 将入度为 0 的顶点入栈
  for (int i = 0; i < G.vexnum; i++) {
    if (indegree[i] == 0) {
      Stack_Push(S, i);
    }
  }

  int count = 0; // 记录已经输出的顶点数
  while(!Stack_IsEmpty(S)) {
    int v = Stack_Pop(S); // 弹出栈顶入度为 0 的顶点
    printf("%c", G.adjList[v].data); // 输出顶点
    count++;
    ArcNode *p = G.adjList[v].first;
    while (p) {
      indegree[p->adjvex]--;
      if (indegree[p->adjvex] == 0) {
        Stack_Push(S, p->adjvex);
      }
      p = p->next;
    }
    
  }
  if (count != G.vexnum) {
    printf("\n图存在回路！\n");
    return false;
  }
  return true;
}


void ALGraph_Show (ALGraph G) {
  for (int i = 0; i < G.vexnum; i++) {
    printf("%c", G.adjList[i].data);
    ArcNode *p = G.adjList[i].first;
    while (p) {
      printf("->%c", G.adjList[p->adjvex].data);
      p = p->next;
    }
    printf("\n");
  }
}

int main () {
  printf("注意，当前创建图为有向图\n");
  ALGraph G;
  // ALGraph_Create(G);
  G.vexnum = 5;
  G.arcnum = 7;
  G.adjList[0].data = 'a';
  G.adjList[1].data = 'b';
  G.adjList[2].data = 'c';
  G.adjList[3].data = 'd';
  G.adjList[4].data = 'e';
  G.adjList[0].first = NULL;
  G.adjList[1].first = NULL;
  G.adjList[2].first = NULL;
  G.adjList[3].first = NULL;
  G.adjList[4].first = NULL;

  // 建立边表
  ALGraph_AddEdge(G, 0, 1, 0); // a->b
  ALGraph_AddEdge(G, 0, 3, 0); // a->d
  ALGraph_AddEdge(G, 1, 3, 0); // b->d
  ALGraph_AddEdge(G, 1, 2, 0); // b->c
  ALGraph_AddEdge(G, 3, 4, 0); // d->e
  ALGraph_AddEdge(G, 3, 2, 0); // d->c
  ALGraph_AddEdge(G, 2, 4, 0); // c->e

  ALGraph_Show(G);
  TopologicalSort(G);
  return 0;
}