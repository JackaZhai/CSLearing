//队列
#include <iostream>
#include <queue> // 引入 queue 库
using namespace std;

// 打印队列的辅助函数
void printQueue(queue<int> q) { // 注意：队列是先进先出，传值时会清空原队列
    // 临时存储队列元素以便打印
    queue<int> temp;
    while (!q.empty()) {
        cout << q.front() << " "; // 打印队首元素
        temp.push(q.front());      // 将队首元素存储到临时队列
        q.pop();                   // 出队
    }
    
    // 将元素重新放回原队列
    while (!temp.empty()) {
        q.push(temp.front());
        temp.pop();
    }
    cout << endl; // 打印换行
}

int main() {
    /* 初始化队列 */
    queue<int> q;

    /* 元素入队 */
    q.push(1);
    q.push(3);
    q.push(2);
    q.push(5);
    q.push(4);
    cout << "队列 queue = ";
    printQueue(q);

    /* 访问队首元素 */
    int front = q.front();
    cout << "队首元素 front = " << front << endl;

    /* 元素出队 */
    q.pop();
    cout << "出队元素 front = " << front << "，出队后 queue = ";
    printQueue(q);

    /* 获取队列的长度 */
    int size = q.size();
    cout << "队列长度 size = " << size << endl;

    /* 判断队列是否为空 */
    bool empty = q.empty();
    cout << "队列是否为空 = " << empty << endl;

    return 0;
}
