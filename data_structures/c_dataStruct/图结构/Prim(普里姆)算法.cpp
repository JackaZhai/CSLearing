#include <stdio.h>
#include <stdlib.h>

typedef char VertexType; // 顶点类型
typedef int EdgeType; // 边上的权值
#define MAXVEX 100 // 最大顶点数
#define INF 65535 // 如果两个顶点之间不可达，用无穷表示距离
#define DIRECTED true // 是否为有向图

typedef struct {
  VertexType vexs[MAXVEX]; // 顶点表
  EdgeType arc[MAXVEX][MAXVEX]; // 邻接矩阵，可看做边表
  int vexNum, edgeNum; // 图中当前的顶点数和边数
} MGraph;


// 创建邻接矩阵
int Graph_Create (MGraph &G) {
  int vi, vj, weight;
  // 输入顶点数和边数
  printf("请输入顶点数：");
  scanf("%d", &G.vexNum);
  printf("请输入边数：");
  scanf("%d", &G.edgeNum);

  for (int i = 0; i < G.vexNum; i++) { // 为每个顶点初始化信息
    printf("请输入第 %d 个的顶点名称: ", i + 1);
    scanf(" %c", &G.vexs[i]);
  }
  for (int i = 0; i < G.vexNum; i++) { // 初始化顶点之间的权值 默认为无穷
    for (int j = 0; j < G.vexNum; j++) {
      G.arc[i][j] = INF;
    }
  }

  printf("下标为 -1 -1 则退出创建边\n");
  for(int i = 0; i < G.edgeNum; i++){ // 根据边的条数，为每一条边赋值
    printf("请输入要创建边的下标 v1 v2 ");
    scanf("%d %d", &vi, &vj);
    if (vi == -1 && vj == -1) break;
    printf("请输入边为[%d][%d]的权值 weight = ", vi, vj);
    scanf("%d", &weight);
    G.arc[vi][vj] = weight;
    // 在无向网中满足图对称性，即Vi-Vj 和Vj-Vi的距离相等，实际就是一条路径
    if (!DIRECTED) {
      G.arc[vj][vi] = weight;
    }
  }
}


// 找到未在最小生成树中且边权值最小的顶点
int Find_Min_V(MGraph G, int cost[], bool visited[]) {
  int minCost = INF; // 最小边权值初始设为无穷大
  int minVertex = -1; // 初始化最小边权值对应的顶点索引

  for (int v = 0; v < G.vexNum; v++) {
    if ((visited[v] == false) && cost[v] < minCost) {
      minCost = cost[v]; // 更新最小边权值
      minVertex = v; // 记录对应顶点索引
    }
  }
  return minVertex; // 返回最小边权值对应的顶点索引
}


// v 为开始顶点
void Prim (MGraph G, int v) {
  int parent[MAXVEX]; // 记录每个顶点在最小生成树中的父节点
  int cost[MAXVEX]; // 记录每个顶点与当前最小生成树的最小边权值
  bool visited[MAXVEX]; // 记录顶点是否已经在最小生成树中

  // 初始化权值
  for (int i = 0; i < G.vexNum; i++) {
    parent[i] = -1;
    cost[i] = INF;
    visited[i] = false;
  }

  cost[v] = 0; // 指定的开始顶点作为初始顶点
  parent[v] = -1; // 初始顶点没有父结点

  // 主循环，构建最小生成树
  // 最小生成树有 vexNum - 1 条边，当 i 达到 vexNum - 1 时，算法就已经完成了构建最小生成树的过程
  for (int i = 0; i < G.vexNum - 1; i++) {
    // 找到最小边权值的顶点，第一次循环找到的是开始顶点
    int minV = Find_Min_V(G, cost, visited);
    // 非联通的
    if (minV == -1) continue;
    visited[minV] = true;
    // 更新其他顶点到最小生成树的边权值和父结点
    for (int j = 0; j < G.vexNum; j++) {
      if (
        G.arc[minV][j]
        && (visited[j] == false)
        && G.arc[minV][j] < cost[j]
      ) {
        parent[j] = minV; // 顶点 j 的父节点是顶点 u
        cost[j] = G.arc[minV][j]; // 更新顶点 j 到最小生成树的边权值
      }
    }
  }
  // 输出构建的最小生成树的顶点
  printf("Vertices in the MST:\n");
  for (int i = 0; i < G.vexNum; i++)
  {
    printf("v=%d p=%d c=%d\n", i, parent[i], cost[i]);
  }
}


// 打印图
void Graph_Show (MGraph G) {
  // 打印顶点
  for (int i = 0; i < G.vexNum; i++)
    printf("%c", G.vexs[i]);
  printf("\n");
  // 打印邻接矩阵
  for(int i = 0; i < G.vexNum; i++){
    for(int j = 0; j < G.vexNum; j++){
      if(G.arc[i][j] == INF) printf("%6s", "∞");
      else printf("%6d", G.arc[i][j]);
    }
    printf("\n");
  }
}

int main () {
  MGraph G;
  // Graph_Create(G);
  G.vexNum = 6;
  G.edgeNum = 10;
  G.vexs[0] = 'a';
  G.vexs[1] = 'b';
  G.vexs[2] = 'c';
  G.vexs[3] = 'd';
  G.vexs[4] = 'e';
  G.vexs[5] = 'f';
  for (int i = 0; i < G.vexNum; i++) { // 初始化顶点之间的权值 默认为无穷
    for (int j = 0; j < G.vexNum; j++) {
      G.arc[i][j] = INF;
    }
  }
  // 设置边
  G.arc[0][1] = G.arc[1][0] = 6;
  G.arc[0][3] = G.arc[3][0] = 5;
  G.arc[0][2] = G.arc[2][0] = 1;
  G.arc[1][2] = G.arc[2][1] = 5;
  G.arc[2][3] = G.arc[3][2] = 5;
  G.arc[1][4] = G.arc[4][1] = 3;
  G.arc[2][4] = G.arc[4][2] = 6;
  G.arc[2][5] = G.arc[5][2] = 4;
  G.arc[3][5] = G.arc[5][3] = 2;
  G.arc[4][5] = G.arc[5][4] = 6;
  Graph_Show(G);
  Prim(G, 0);
  return 0;
}