#include <iostream>

using namespace std;

/* 随机访问元素 */
int randomAccess(int *num, int size) {
    int randomIndex = rand() % size;
    return num[randomIndex];
}

/* 扩展数组长度 */
int* extend(int *num, int size, int add_size) {
    int* arr = new int[size + add_size]; 
    for (int i = 0; i < size; i++) {
        arr[i] = num[i];
    }
    delete[] num; // 释放旧数组内存
    return arr;
}

/* 在数组的索引 index 处插入元素 num */
void insert(int *num, int &size, int index, int nums) {
    for (int i = size; i > index; i--) {
        num[i] = num[i - 1]; // 注意要从 size 开始
    }
    num[index] = nums;
    size++; // 插入后数组大小增加
}

/* 删除索引 index 处的元素 */
void remove(int *num, int &size, int index) {
    for (int i = index; i < size - 1; i++) {
        num[i] = num[i + 1];
    }
    size--; // 删除后数组大小减小
}

/* 打印数组 */
void printArray(int *num, int size) {
    for (int i = 0; i < size; i++) {
        cout << num[i] << " ";
    }
    cout << endl;
}

/* 在数组中查找指定元素 */
void findElement(int *num, int size, int target) {
    for (int i = 0; i < size; i++) {
        if (num[i] == target) {
            cout << "Element " << target << " found at index: " << i << endl;
        }
    }
}

int main() {
    int *num = new int[5]; // 动态分配内存
    num[0] = 1;
    num[1] = 2;
    num[2] = 3;
    num[3] = 4;
    num[4] = 5;
    int size = 5;

    printArray(num, size);
    cout << "Random access element: " << randomAccess(num, size) << endl;

    cout << "Inserting 28 at index 3: ";
    insert(num, size, 3, 28);
    printArray(num, size);

    cout << "Removing element at index 3: ";
    remove(num, size, 3);
    printArray(num, size);

    cout << "Finding element 2: ";
    findElement(num, size, 2);

    num = extend(num, size, 5);
    // 增加元素，演示扩展后的使用
    for(int i = size; i < size + 5; i++) {
        num[i] = i + 1; // 添加新元素
    }
    size += 5; // 更新大小
    printArray(num, size);

    delete[] num; // 释放动态分配内存
    return 0;
}
