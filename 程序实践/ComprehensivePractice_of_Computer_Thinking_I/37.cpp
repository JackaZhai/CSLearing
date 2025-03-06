#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[n];
    bool flag = true;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    if(n == 1) {
        cout << "Jolly" << endl;
        return 0;
    }
    int diff[n-1];
    for(int i = 0; i < n-1; i++) {
        diff[i] = abs(arr[i+1] - arr[i]);
    }
    sort(diff, diff + n -1);
    for(int i = 0; i < n-1; i++) {
        if(diff[i] != i+1) {
            flag = false;
            break;
        }
    }
    if(flag)
        cout << "Jolly" << endl;
    else
        cout << "Not jolly" << endl;
    return 0;
}