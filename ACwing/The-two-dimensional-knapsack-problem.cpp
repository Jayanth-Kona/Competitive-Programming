#include<bits/stdc++.h>
using namespace std;

// Problem: https://www.acwing.com/problem/content/8/

int main(){
    int n , v , m;
    cin >> n >> v >> m;

    vector<int> volume(n) , weight(n) , value(n);
    for(int i = 0 ; i < n ; i++) cin >> volume[i] >> weight[i] >> value[i];

    vector<vector<int>> maxValue(v + 1 , vector<int>(m + 1 , 0));

    for(int i = 0 ; i < n ; i++){
        for(int vol = v ; vol >= volume[i] ; vol--){
            for(int wei = m ; wei >= weight[i] ; wei--){
                maxValue[vol][wei] = max(maxValue[vol][wei] , value[i] + maxValue[vol - volume[i]][wei - weight[i]]);
            }
        }
    }

    cout << maxValue[v][m];

    return 0;
}