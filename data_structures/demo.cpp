#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;

// Function to generate the folded matrix
vector<vector<int>> generate_folded_matrix(int start, int n) {
    // Initialize n x n matrix with 0
    vector<vector<int>> matrix(n, vector<int>(n, 0));
    
    int current_num = start;
    
    // Iterate over the sum of indices from 0 to 2*(n-1)
    for(int sum = 0; sum <= 2*(n-1); sum++) {
        vector<pair<int, int>> cells;
        
        // Collect all cells where (i + j) == sum
        for(int i = 0; i < n; i++) {
            int j = sum - i;
            if(j >=0 && j < n){
                cells.emplace_back(i, j);
            }
        }
        
        // Always sort cells by row index ascending
        sort(cells.begin(), cells.end(), [](const pair<int,int> &a, const pair<int,int> &b) -> bool {
            return a.first < b.first;
        });
        
        // Assign numbers to the sorted cells
        for(auto it = cells.begin(); it != cells.end(); ++it){
            int i = it->first;
            int j = it->second;
            matrix[i][j] = current_num++;
        }
    }
    
    return matrix;
}

// Function to print the matrix with proper formatting
void print_matrix(const vector<vector<int>> &matrix) {
    int n = matrix.size();
    // Determine the maximum number to set width
    int max_num = 0;
    for(const auto &row : matrix){
        for(auto num : row){
            if(num > max_num){
                max_num = num;
            }
        }
    }
    int width = to_string(max_num).length() + 1; // +1 for spacing
    
    for(const auto &row : matrix){
        for(auto num : row){
            cout << setw(width) << num;
        }
        cout << endl;
    }
}

int main(){
    int start_number, order;
    
    // 输入起始数和方阵阶数
    cout << "请输入起始数（1 ≤ start ≤ 20）和方阵阶数（1 ≤ n ≤ 20）: ";
    cin >> start_number >> order;
    
    // 检查输入范围
    if(start_number < 1 || start_number > 20 || order < 1 || order > 20){
        cout << "输入超出范围。" << endl;
        return 1;
    }
    
    // 生成折叠方阵
    vector<vector<int>> folded_matrix = generate_folded_matrix(start_number, order);
    
    // 输出结果
    print_matrix(folded_matrix);
    
    return 0;
}
