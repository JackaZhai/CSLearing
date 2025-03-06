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


// 实现贝尔曼-福特算法的函数
// 计算从源顶点到其他顶点的最短路径并输出
void BellmanFord (MGraph G, int src) {
  int dist[MAXVEX]; // 存储从源顶点到每个顶点的最短距离
  int parent[MAXVEX]; // 前驱数组，用于追踪路径，即每个节点的父节点
  
  // 初始化距离和前驱数组
  for (int i = 0; i < G.vexNum; i++) {
    dist[i] = INF; // 将所有顶点的初始距离设为无穷大
    parent[i] = -1; // 初始化前驱为 -1，表示无前驱
  }

  dist[src] = 0; // 源顶点到自身的距离为 0

  // 放松所有边 V-1 次
  for (int i = 1; i < G.vexNum; i++) {
    bool hasChange = false; // 标记本轮是否有距离更新

    // 循环遍历每一条边
    for (int u = 0; u < G.vexNum; u++) { // 遍历所有顶点 u
      for (int v = 0; v < G.vexNum; v++) { // 遍历所有顶点 v
        int weight = G.arc[u][v]; // 获取边 (u, v) 的权重
        // 判断是否满足放松条件
        if (
          weight != INF // 边存在
          && dist[u] != INF // 从源到 u 的距离有效
          && dist[u] + weight < dist[v] // 从源到 v 的距离是否可以更新
        ) {
          dist[v] = dist[u] + weight; // 更新从源到 v 的最短距离
          parent[v] = u; // 更新 v 的前驱为 u
          hasChange = true; // 标记发生了变化
        }
      }
    }

    // 如果这一轮没有任何变化，提前退出
    if (!hasChange) {
      break; // 没有更新，说明已经找到最短路径
    }
  }

  // 检查是否存在负权环
  for (int u = 0; u < G.vexNum; u++) { // 遍历所有顶点 u
    for (int v = 0; v < G.vexNum; v++) { // 遍历所有顶点 v
      int weight = G.arc[u][v]; // 获取边 (u, v) 的权重
      // 如果可以进一步放松，则说明存在负权环
      if (weight != INF && dist[u] != INF && dist[u] + weight < dist[v]) {
        printf("图中存在负环路，无法求解\n"); // 输出负权环信息
        return; // 结束函数
      }
    }
  }

  // 打印从源顶点到其他所有顶点的最短路径和距离
  for (int i = 0; i < G.vexNum; i++) { // 遍历每个顶点
    if (src == i) continue; // 跳过源顶点
    // 打印从源顶点到当前顶点的最短距离和路径
    printf("从顶点%c出发到%c的最短距离为%d，最短路径为：%c", G.vexs[src], G.vexs[i], dist[i], G.vexs[src]);
    printPath(G, parent, i); // 递归打印从源到当前顶点的路径
    printf("\n"); // 换行
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
  G.vexNum = 5;
  G.edgeNum = 8;
  G.vexs[0] = 'A';
  G.vexs[1] = 'B';
  G.vexs[2] = 'C';
  G.vexs[3] = 'D';
  G.vexs[4] = 'E';
  for (int i = 0; i < G.vexNum; i++) { // 初始化顶点之间的权值 默认为无穷
    for (int j = 0; j < G.vexNum; j++) {
      G.arc[i][j] = INF;
    }
  }

  G.arc[0][1] = -1;
  G.arc[0][2] = 4;
  G.arc[1][2] = 3;
  G.arc[1][3] = 2;
  G.arc[1][4] = 2;

  //G.arc[4][1] = 1;
  G.arc[3][2] = 5;
  G.arc[3][1] = 1;

  G.arc[4][3] = -3;
  Graph_Show(G);
  BellmanFord(G, 0);
  return 0;
}