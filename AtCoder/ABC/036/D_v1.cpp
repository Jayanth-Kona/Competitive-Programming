
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 1e9 + 7;

// For Connected Tree

int main(){
    int n ; cin >> n;

    vector<vector<int>> Tree(n + 1);
    for(int e = 1 ; e <= n - 1 ; e++){
        int u , v ; cin >> u >> v;
        Tree[u].push_back(v);
        Tree[v].push_back(u);
    }

    vector<array<ll , 2>> DP(n + 1 , array<ll , 2>{0 , 0});

    function<void(int , int)> DFS = [&](int u , int p){
        DP[u][0] = 1;
        DP[u][1] = 1;
        for(int v : Tree[u]){
            if(v ^ p){
                DFS(v , u);
                DP[u][0] *= (DP[v][0] + DP[v][1]) % mod;
                DP[u][0] %= mod;
                DP[u][1] *= (DP[v][0]) % mod;
                DP[u][1] %= mod;
            }
        }
    };

    DFS(1 , 0);

    cout << (DP[1][0] + DP[1][1]) % mod;

    return 0;
}