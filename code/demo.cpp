#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;
const int N = 10;
int n;
int st[N],path[N];//path 记录数组，st记录是否选过


void dfs(int u){
    if (u>n){
        for (int i=1;i<=n;i++){
            printf("%d ",i);    
        }
        printf("\n");
        return;
    }
    
    for (int i = 1;i<=n;i++){
        if (!st[i]){
            path[u] = i;
            st[i=1];
            dfs(u+1);
            st[i] = 0;
        }
    }
}

int main(){
    scanf("%d",n);
    dfs(1);
    return 0;
    
}