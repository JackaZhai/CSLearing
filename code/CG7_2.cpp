#include<iostream>
using namespace std;
#include<map>

int main(){
    map<string,int> m;
    int t;
    string color;
    cin>>t;
    while (t){
        while(t--){
            cin>>color;
            m[color]++;
        }
        int maxn=0;
        string s;
        
        // 查找出现次数最多的气球颜色
        for(map<string, int>::iterator it = m.begin(); it != m.end(); it++){
            if(it->second > maxn){
                maxn = it->second;
                s = it->first;
            }
        }

        cout<<s<<endl;
        m.clear();
        cin>>t;
    }
    return 0;
}
