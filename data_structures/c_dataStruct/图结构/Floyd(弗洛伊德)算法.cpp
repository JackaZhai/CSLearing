#include <stdio.h>
#include <stdlib.h>

typedef char VertexType; // 顶点类型
typedef int EdgeType; // 边上的权值
#define MAXVEX 100 // 最大顶点数
#define INF 65535 // 如果两个顶点之间不可达，用无穷表示距离
#define DIRECTED true // 是否为有向图

#define V 3 // 定义图中结点的个数


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


// 输出最短路径的函数
void printPath (int path[V][V], int start, int end) {
  // 如果路径前驱为-1，表示没有路径
  if (path[start][end] == -1) {
    printf("%d", start); // 直接输出起始结点
    return;
  }
  printPath(path, start, path[start][end]); // 递归输出路径
  printf(" -> %d", end); // 输出当前路径
}


// Flyod-Warshall 算法函数
void Floyd (MGraph G) {
  int dist[V][V]; // 最短路径的距离矩阵
  int path[V][V]; // 最短路径的前驱结点

  // 初始化 dist 和 path 矩阵
  for (int i = 0; i < V; i++) {
    for (int j = 0; j < V; j++) {
      dist[i][j] = G.arc[i][j];
      if (i != j && G.arc[i][j] != INF) {
        path[i][j] = i; // 初始化路径前驱结点
      } else {
        path[i][j] = -1; // 无路径时设置为 -1
      }
    }
  }

  // 逐个结点尝试作为中间节点，更新最短路径
  for (int k = 0; k <  V; k++) {
    for (int i = 0; i < V; i++) {
      for (int j = 0; j < V; j++) {
        // dist[i][k] + dist[k][j] 表示通过中间节点 k 从节点 i 到节点 j 的路径长度，即通过节点 k 的路径长度。
        // dist[i][j] 是节点 i 到节点 j 的当前已知的最短路径长度。
        // i != j 自己到自己的路径为无穷(或0)所以不需要更新
        // 如果通过中间节点 k 的路径更短，则更新最短路径
        if (i != j && dist[i][k] + dist[k][j] < dist[i][j]) {
          dist[i][j] = dist[i][k] + dist[k][j];
          path[i][j] = path[k][j]; // 更新路径前驱信息
        }
      }
    }
  }

  // 输出最终的最短路径矩阵
  printf("最短路径矩阵：\n");
  for (int i = 0; i < V; i++) {
    for (int j = 0; j < V; j++) {
      if (dist[i][j] == INF) {
        printf("INF ");
      } else {
        printf("%d  ", dist[i][j]);
      }
    }
    printf("\n");
  }

  // 输出没对节点之前的最短路径信息
  printf("\n最短路径信息：\n");
  for (int i = 0; i < V; i++) {
    for (int j = 0; j < V; j++) {
      if (path[i][j] == -1) {
        printf("No Path from %d to %d", i, j); // 没有路径时的提示
      } else {
        printf("Path from %d to %d: ", i, j);
        printPath(path, i, j); // 调用输出路径的函数
      }
      printf("\n");
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
  // 注意 为了方便申请数组内存，在全局定义了顶点数常量
  MGraph G;
  // Graph_Create(G);
  G.vexNum = V;
  G.vexs[0] = '0';
  G.vexs[1] = '1';
  G.vexs[2] = '2';
  for (int i = 0; i < G.vexNum; i++) { // 初始化顶点之间的权值 默认为无穷
    for (int j = 0; j < G.vexNum; j++) {
      G.arc[i][j] = INF;
    }
  }
  G.edgeNum = 5;
  // 设置边
  G.arc[0][1] = 6;
  G.arc[0][2] = 13;
  G.arc[1][0] = 10;
  G.arc[1][2] = 4;
  G.arc[2][0] = 5;
  Graph_Show(G);
  Floyd(G);
  return 0;
}