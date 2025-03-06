#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 树存储结构
typedef struct HTNode {
  int weight; // 权值
  char data; // 待编码字符
  int parent; // 父节点
  int lchild, rchild; // 左右孩子
} HTNode, * HuffmanTree;

typedef char **HuffmanCode; // 字符指针数组中存储的元素类型

// 查找在 0 到 i 中的两个最小值，且没有被处理过(parent == 0)
void Select(HuffmanTree &HT, int n, int &min1, int &min2) {
    int min;
    // 找到第一个最小值
    for (int i = 0; i < n; i++) {
        if (HT[i].parent == 0) {
            min = i;
            break;
        }
    }
    for (int i = min + 1; i < n; i++) {
        if (
            HT[i].parent == 0 &&
            HT[i].weight < HT[min].weight
        ) {
            min = i;
        }
    }
    min1 = min; // 第一个最小值给 s1
    // 找第二个最小值
    for (int i = 0; i < n; i++) {
        if (HT[i].parent == 0 && i != min1) {
            min = i;
            break;
        }
    }
    for (int i = min + 1; i < n; i++) {
        if (
            HT[i].parent == 0 &&
            HT[i].weight < HT[min].weight &&
            i != min1
        ) {
            min = i;
        }
    }
    min2 = min; // 第二个最小值
}


// 构建哈夫曼树 HT=哈夫曼树、w=权值、n=待编码数量
void Huffman_Create (HuffmanTree &HT, int *w, char *data, int n) {
  int m = 2 * n - 1; // 哈夫曼树的节点总数为 2n-1
  HT = (HuffmanTree)calloc(m, sizeof(HTNode)); // 创建 m 个结点，注意malloc和calloc区别
  for (int i = 0; i < n; i++) {
      HT[i].weight = w[i]; // 权值给 n 个叶子结点
      HT[i].data = data[i];
  }
  for (int i = n; i < m; i++) {
      int min1, min2;
      // 找到权值最小的两个结点，期中min1权值小于min2的权值
      Select(HT, i, min1, min2);
      // 新结点的左右权值为两个最小树的权值之和
      HT[i].weight = HT[min1].weight + HT[min2].weight;
      HT[min1].parent = i;
      HT[min2].parent = i;
      // 较小的为左孩子
      HT[i].lchild = min1;
      HT[i].rchild = min2;
  }
}


// 生成哈夫曼编码 HT=哈夫曼树、HC=编码结果保存(相当于二维数组)、n=待编码字符个数
void Huffman_Coding (HuffmanTree &HT, HuffmanCode &HC, int n) {
    // 开辟需要编码的个数空间(编码串地址)
    HC = (HuffmanCode)malloc(sizeof(char *) * n);
    // 辅助空间(编码串)，编码最长为n-1
    char *code = (char*)malloc(sizeof(char) * n); // 字符串最后一位\0表示结束
    code[n - 1] = '\0';
    for (int i = 0; i < n; i++) {
        int j = i; // 当前第i个数据的编码
        int p = HT[j].parent; // 找到该数据的根结点
        // 由于是从编码结点一直向上找父，所以编码顺序是相反的
        int start = n - 1; // 那么存储编码的时候从最后面开始存即编码正序了
        // 直到父结点为0，即父结点为根节点时停止
        while (p) {
            // 如果该节点是其父结点的左孩子，则编码为0，否则为1
            if (HT[p].lchild == j)
                code[--start] = '0';
            else
                code[--start] = '1';
            j = p; // 继续向上进行编码
            p = HT[j].parent; // j 的父节点
        }
        // 由于code是整个n长度，所以这里从新根据编码长度开辟存储编码的空间
        HC[i] = (char*)malloc(sizeof(char) * (n - start));
        strcpy(HC[i], &code[start]); // 字符串拷贝
    }
    free(code); // 释放辅助空间
}


// 打印哈夫曼树，n=编码节点个数
void HuffmanTree_Print(HuffmanTree HT, int n) {
  printf("哈夫曼树为:>\n");
  printf("下标   字符   权值     父结点   左孩子   右孩子\n");
  for (int i = 0; i < n; i++) {
    printf("%-4d   %-4c   %-6d   %-6d   %-6d   %-6d\n", i, HT[i].data, HT[i].weight, HT[i].parent, HT[i].lchild, HT[i].rchild);
  }
  printf("\n");
}

void HuffmanCode_Print (HuffmanTree HT, HuffmanCode HC, int n) {
  for (int i = 0; i < n; i++) {
    printf("数据%c的编码为:%s\n", HT[i].data, HC[i]);
  }
}

int main() {
  int n = 4;
  HuffmanTree HT;
  int w[] = {7, 5, 2, 4};
  char data[] = {'a', 'b', 'c', 'd'};
  Huffman_Create(HT, w, data, n);
  HuffmanTree_Print(HT, n);

  HuffmanCode HC;
  Huffman_Coding(HT, HC, n);
  HuffmanCode_Print(HT, HC, n);
  return 0;
}