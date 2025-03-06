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

// 栈相关
// 定义栈中元素的最大个数为顶点个数
#define STACK_MAX_SIZE MAXVEX

typedef struct {
  int data[STACK_MAX_SIZE];
  int top;
} SqStack;

// 初始化栈
void Stack_Init(SqStack &S) {
  S.top = -1; // 初始化栈顶指针为-1，表示栈为空
}

// 判断栈是否为空
bool Stack_Empty(SqStack S) {
  return S.top == -1;
}

// 判断栈是否已满
bool Stack_Full(SqStack S) {
  return S.top == STACK_MAX_SIZE - 1;
}

// 新元素入栈
bool Stack_Push(SqStack &S, int x) {
  if (Stack_Full(S)) {
    printf("栈已满，无法入栈");
    return false;
  } else {
    S.data[++S.top] = x; // 将元素入栈，并更新栈顶指针
    return true;
  }
}

// 栈顶元素出栈，x为出栈的栈顶元素
bool Stack_Pop(SqStack &S, int &x) {
  if (Stack_Empty(S)) {
    printf("栈为空，无法出栈");
    return false;
  } else {
    x = S.data[S.top--]; // 将栈顶元素出栈，并更新栈顶指针
    return true;
  }
}


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
  return 0;
}


// 打印图
void Graph_Show (MGraph G) {
  printf("顶点：");
  // 打印顶点
  for (int i = 0; i < G.vexNum; i++)
      printf("%c ", G.vexs[i]);
  printf("\n邻接矩阵：\n");
  // 打印邻接矩阵
  for(int i = 0; i < G.vexNum; i++){
    for(int j = 0; j < G.vexNum; j++){
      if(G.arc[i][j] == INF) printf("%6s", "∞");
      else printf("%6d", G.arc[i][j]);
    }
    printf("\n");
  }
}


// 求关键路径
bool Critical_Path (MGraph G) {
  // 1.先求拓扑排序
  SqStack S;
  Stack_Init(S);
  // 拓扑排序序列，存储的为顶点下标
  int topOrder[MAXVEX];
  // 当前拓扑排序中有多少个元素
  int topOrderLen = 0;

  // 每个顶点的入度数量
  int inDegree[MAXVEX];
  // 初始入度为 0
  for (int i = 0; i < MAXVEX; i++) inDegree[i] = 0;

  // 计算每个顶点的初始入度
  for (int i = 0; i < G.vexNum; i++) {
    for (int j = 0; j < G.vexNum; j++) {
      if (G.arc[i][j] != INF) {
        // 行为出度，列为入度
        // 这里使用 j 代表列
        inDegree[j] = inDegree[j] + 1;
      }
    }
  }

  // 将所有入度为0的顶点下标加入栈中
  for (int i = 0; i < G.vexNum; i++) {
    if (inDegree[i] == 0) {
      Stack_Push(S, i);
    }
  }

  // 开始拓扑排序 栈不为空则进入循环
  while (!Stack_Empty(S)) {
    // 弹出栈顶
    int u;
    Stack_Pop(S, u);

    // 将当前出栈的顶点下标加入拓扑排序序列中
    topOrder[topOrderLen] = u;
    topOrderLen++;

    // 遍历当前顶点的邻接顶点
    for (int i = 0; i < G.vexNum; i++) {
      if (G.arc[u][i] != INF) {
        // 减少邻接顶点的入度
        inDegree[i]--;

        // 如果邻接顶点的入度为0了，则将其下标加入栈
        // 注意：加入栈的始终为下标，不是顶点名称
        if (inDegree[i] == 0) {
          Stack_Push(S, i);
        }
      }
    }
  }

  printf("\n拓扑排序顶点下标序列：");
  for (int i = 0; i < topOrderLen; i++) {
    printf("%d ", topOrder[i]);
  }
  // 如果拓扑排序后的序列长度不等于顶点数，说明拓扑排序失败，则不进行关键路径求解
  if (topOrderLen != G.vexNum) return false;

  // 求关键路径

  // 2.求所有时间的最早发生时间 ve
  int ve[MAXVEX];
  int veMax = 0;
  // 初始 ve 为 0
  for (int i = 0; i < G.vexNum; i++) ve[i] = 0;

  for (int i = 0; i < topOrderLen; i++) {
    // 根据拓扑序列，依次计算顶点最早开始时间
    int u = topOrder[i];
    // 对于每个顶点，依次遍历其所有的出边（邻接顶点）
    for (int j = 0; j < G.vexNum; j++) {
      // 其他顶点到达 u 的权值
      int weight = G.arc[j][u];
      // 检查是否通过顶点 j 到达顶点 u 的路径能够获得更早的开始时间
      if (
        weight != INF
        &&
        (ve[j] + weight) > ve[u]
      ) {
        // 更新最早开始时间
        ve[u] = ve[j] + weight;
        // 记录最大值，给第 3 步求所有事件的最迟发生时间使用
        if (ve[u] > veMax) veMax = ve[u];
      }
    }
  }

  // 3.求所有事件的最迟发生时间 vl
  // 按逆拓扑排序序列，依次求各个顶点的 vl
  int vl[MAXVEX];
  // 初始化最迟发生时间
  for (int i = 0; i < G.vexNum; i++) {
    vl[i] = veMax;
  }
  for (int i = topOrderLen - 1; i >= 0; i--) {
    int u = topOrder[i];
    for (int j = 0; j < G.vexNum; j++) {
      // u 到其它顶点的权值
      int weight = G.arc[u][j];
      if (
        weight != INF
        &&
        vl[j] - weight < vl[u]
      ) {
        vl[u] = vl[j] - weight;
      }
    }
  }

  int e[MAXVEX * 2]; // 因为是记录边，所以最大值为顶点 * 2
  int l[MAXVEX * 2];
  int d[MAXVEX * 2];
  int edgeLen = 0;
  printf("\n关键路径：");
  for (int i = 0; i < G.vexNum; i++) {
    for (int j = 0; j < G.vexNum; j++) {
      int weight = G.arc[i][j];
      // 边存在
      if (weight != INF) {
        // 4.求所有活动的最早发生时间(e)
        // 边活动最早发生时间等于其起点顶点的 ve
        e[edgeLen] = ve[i];

        // 5.求所有活动的最迟发生时间(l)
        // 边活动的最迟发生时间等于 其指向 顶点的 vl - 边权值
        l[edgeLen] = vl[j] - weight;

        // 6.求所有活动的时间余量(d)
        d[edgeLen] = l[edgeLen] - e[edgeLen];

        // 7.余量 d 为 0 的即关键边
        if (d[edgeLen] == 0) {
          printf("%d -> %d，", i, j);
        }
        edgeLen++;
      }
    }
  }

  printf("\n所有事件的最早发生时间(ve)：");
  for (int i = 0; i < G.vexNum; i++) {
    printf("%d ", ve[i]);
  }

  printf("\n所有事件的最迟发生时间(vl)：");
  for (int i = 0; i < G.vexNum; i++) {
    printf("%d ", vl[i]);
  }

  printf("\n所有活动的最早发生时间(e)：");
  for (int i = 0; i < edgeLen; i++) {
    printf("%d ", e[i]);
  }

  printf("\n所有活动的最迟发生时间(l)：");
  for (int i = 0; i < edgeLen; i++) {
    printf("%d ", l[i]);
  }

  printf("\n求所有活动的时间余量  (d)：");
  for (int i = 0; i < edgeLen; i++) {
    printf("%d ", d[i]);
  }

  // 关键路径即为 活动时间余量 d 为 0 的边
  return true;
}


int main () {
  MGraph G;
  // Graph_Create(G);
  G.vexs[0] = '1';
  G.vexs[1] = '2';
  G.vexs[2] = '3';
  G.vexs[3] = '4';
  G.vexs[4] = '5';
  G.vexs[5] = '6';
  G.vexNum = 6;

  // 初始化所有边为 无穷
  for (int i = 0; i < G.vexNum; i++) {
      for (int j = 0; j < G.vexNum; j++) {
      G.arc[i][j] = INF;
      }
  }
  G.arc[0][1] = 3;
  G.arc[0][2] = 2;
  G.arc[1][3] = 2;
  G.arc[1][4] = 3;
  G.arc[2][3] = 4;
  G.arc[2][5] = 3;
  G.arc[3][5] = 2;
  G.arc[4][5] = 1;
  G.edgeNum = 8;
  Graph_Show(G);

  // 求关键路径
  Critical_Path(G);
  return 0;
}