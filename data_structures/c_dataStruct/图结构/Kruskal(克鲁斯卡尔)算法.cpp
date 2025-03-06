#include <stdio.h>
#include <stdlib.h>

typedef char VertexType; // 顶点类型
typedef int EdgeType; // 边上的权值
#define MAXVEX 100 // 最大顶点数
#define INF 65535 // 如果两个顶点之间不可达，用无穷表示距离
#define DIRECTED true // 是否为有向图

// Kruskal 辅助边
typedef struct {
  int source;
  int target;
  int weight;
} Edge;

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


// 比较函数，用于排序边
int compareEdges (const void *a, const void *b) {
  return ((Edge *)a)->weight - ((Edge *)b)->weight;
}


// Kruskal 克鲁斯卡尔算法
void Kruskal (MGraph G, Edge edges[]) {
  // 每个顶点配置一个标记值（并查集思想）
  int *sets = (int *)malloc(G.vexNum * sizeof(int));
  // 初始状态下，每个顶点的标记都不相同
  for (int i = 0; i < G.vexNum; i++) {
    sets[i] = i;
  }
  // 根据权值，对所有边进行升序排序
  qsort(edges, G.edgeNum, sizeof(edges[0]), compareEdges);

  // 遍历所有边
  int num = 0; // 记录加入的边数
  // 由于已经按升序进行排序，只需对边进行遍历每个都是最小权值边
  for (int i = 0; i < G.edgeNum; i++) {
    // 找到当前边的两个顶点在 sets 数组中的位置下标
    int source = edges[i].source;
    int target = edges[i].target;
    int weight = edges[i].weight;
    // 如果顶点位置存在且顶点的标记不同，说明不在一个集合中，不会产生回路
    if (sets[source] != sets[target]) {
      printf("s=%d, t=%d, w=%d\n", source, target, weight);
      num++;
      // 将新加入的生成树的顶点标记全改为一样的
      for (int j = 0; j < G.vexNum; j++) {
        // 找到集合的 target 标记
        if (sets[j] == sets[target]) {
          // 使 targe 标记 = source 的标记（相反也行）
          sets[j] = sets[source];
        }
      }
      // 如果选中的边数量=顶点数-1，证明最小生成树已形成，退出循环
      if (num == G.vexNum - 1) {
        break;
      }
    }
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
  G.edgeNum = 10;
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
  Edge *edges = (Edge *)malloc(G.edgeNum * sizeof(Edge));
  int edgeIndex = 0;
  // 构建边数组，只使用矩阵的上三角
  for (int i = 0; i < G.vexNum; i++) {
    for (int j = i + 1; j < G.vexNum; j++) {
      if (G.arc[i][j] != INF) {
        edges[edgeIndex].source = i;
        edges[edgeIndex].target = j;
        edges[edgeIndex].weight = G.arc[i][j];
        edgeIndex++;
      }
    }
  }
  Graph_Show(G);
  Kruskal(G, edges);
  return 0;
}