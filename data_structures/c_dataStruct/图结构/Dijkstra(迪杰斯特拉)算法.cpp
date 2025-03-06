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


// 找到距离值最小的顶点，从尚未包括在最短路径树中的顶点集合中选取
int minDistance (MGraph G, int dist[], bool visited[]) {
  int min = INF, minIndex;
  // 遍历所有顶点，找到距离最小的顶点
  for (int v = 0; v < G.vexNum; v++)
    if (visited[v] == false && dist[v] <= min)
      min = dist[v], minIndex = v;

  return minIndex;
}

// 打印构造的距离数组
void printPath (int parent[], int i) {
  // 递归打印路径
  if (parent[i] == -1)
    return;
  printPath(parent, parent[i]);
  printf(" -> %d", i);
}


// 实现Dijkstra算法的函数
// 计算从源顶点到其他顶点的最短路径并输出
void Dijkstra (MGraph G, int src) {
  // 保存从源到每个顶点的最短路径
  int dist[G.vexNum];
  // 标记顶点是否在最短路径树中
  bool visited[G.vexNum];
  // 存储每个顶点在最短路径中的前一个顶点
  int parent[G.vexNum];
  // 初始化距离、最短路径树集合和前驱顶点
  for (int i = 0; i < G.vexNum; i++) {
    dist[i] = INF; // 初始化距离为无限大
    visited[i] = false; // 尚未包括在最短路径树中
    parent[i] = -1; // 初始前驱为 -1
  }

  dist[src] = 0; // 源顶点到自身的距离为0

  // 查找原顶点到其他顶点的最短路径
  for (int i = 0; i < G.vexNum - 1; i++) {
    // 找到距离最小的顶点，第一次循环找到的是开始顶点
    int u = minDistance(G, dist, visited);
    visited[u] = true;
    // 其他没更新到的顶点 dist 任然为 INF
    // 所以在 i 的下次循环中 找到的顶点是相邻顶点
    // 更新从找到的最小顶点到其相邻顶点的距离和前驱顶点
    for (int v = 0; v < G.vexNum; v++) {
      if (
        !visited[v]
        && G.arc[u][v]
        && dist[u] != INF
        // 判断是否找到了一条比当前路径更短的路径
        && dist[u] + G.arc[u][v] < dist[v]
      ) {
        dist[v] = dist[u] + G.arc[u][v];
        parent[v] = u; // 更新前驱结点
      }
    }
  }
  // 输出每个顶点的最短路径及路径本身
  printf("Vertex \t Distance \t Path\n");
  for (int i = 0; i < G.vexNum; i++) {
    printf("%d \t %d \t\t %d", i, dist[i], src);
    printPath(parent, i);  // 打印路径
    printf("\n");
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
  Dijkstra(G, 0);
  return 0;
}