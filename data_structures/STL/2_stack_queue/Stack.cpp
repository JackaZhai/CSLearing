//栈
#include <iostream>
#include <stack> // 引入 stack 库
using namespace std;

// 打印栈的辅助函数
void printStack(stack<int> s) { // 注意：栈会在传值时被清空，所以使用值传递
    // 临时存储栈元素以便打印
    stack<int> temp;
    while (!s.empty()) {
        temp.push(s.top()); // 将栈顶元素存储到临时栈
        s.pop();            // 出栈
    }
    
    // 打印元素
    while (!temp.empty()) {
        cout << temp.top() << " "; // 打印元素
        s.push(temp.top());         // 将元素重新放回原栈
        temp.pop();                 // 清空临时栈
    }
    cout << endl;
}

int main() {
    /* 初始化栈 */
    stack<int> stack;

    /* 元素入栈 */
    stack.push(1);
    stack.push(3);
    stack.push(2);
    stack.push(5);
    stack.push(4);
    cout << "栈 stack = ";
    printStack(stack);

    /* 访问栈顶元素 */
    int top = stack.top();
    cout << "栈顶元素 top = " << top << endl;

    /* 元素出栈 */
    stack.pop(); // 出栈操作，移除栈顶元素
    cout << "出栈元素 pop = " << top << "，出栈后 stack = ";
    printStack(stack);

    /* 获取栈的长度 */
    int size = stack.size();
    cout << "栈的长度 size = " << size << endl;

    /* 判断是否为空 */
    bool empty = stack.empty();
    cout << "栈是否为空 = " << empty << endl;

    return 0;
}
