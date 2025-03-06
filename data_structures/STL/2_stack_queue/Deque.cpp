// 双向队列
#include <iostream>
#include <deque> // 引入 deque 库
using namespace std;

// 打印双向队列的辅助函数
void printDeque(deque<int> d) { // 注意：传值会导致原队列为空
    // 遍历双向队列元素并打印
    for (int num : d) {
        cout << num << " ";
    }
    cout << endl; // 打印换行
}

int main() {
    /* 初始化双向队列 */
    deque<int> d;

    /* 元素入队 */
    d.push_back(2);
    d.push_back(5);
    d.push_back(4);
    d.push_front(3);
    d.push_front(1);
    cout << "双向队列 deque = ";
    printDeque(d);

    /* 访问元素 */
    int front = d.front();
    cout << "队首元素 front = " << front << endl;
    int back = d.back();
    cout << "队尾元素 back = " << back << endl;

    /* 元素出队 */
    d.pop_front();
    cout << "队首出队元素 popFront = " << front << "，队首出队后 deque = ";
    printDeque(d);
    
    d.pop_back();
    cout << "队尾出队元素 popLast = " << back << "，队尾出队后 deque = ";
    printDeque(d);

    /* 获取双向队列的长度 */
    int size = d.size();
    cout << "双向队列长度 size = " << size << endl;

    /* 判断双向队列是否为空 */
    bool empty = d.empty();
    cout << "双向队列是否为空 = " << empty << endl;

    return 0;
}
