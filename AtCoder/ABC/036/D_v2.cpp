#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 1e9 + 7;

// For DisConnected Tree

int main(){
    int n ; cin >> n;

    vector<vector<int>> Tree(n + 1);
    for(int e = 1 ; e <= n - 1 ; e++){
        int u , v ; cin >> u >> v;
        Tree[u].push_back(v);
        Tree[v].push_back(u);
    }

    vector<bool> vis(n + 1 , false);
    vector<array<ll , 2>> DP(n + 1 , array<ll , 2>{0 , 0});

    function<void(int)> DFS = [&](int u){
        vis[u] = true;
        DP[u][0] = 1;
        DP[u][1] = 1;
        for(int v : Tree[u]){
            if(vis[v] == false){
                DFS(v);
                DP[u][0] *= (DP[v][0] + DP[v][1]) % mod;
                DP[u][0] %= mod;
                DP[u][1] *= (DP[v][0]) % mod;
                DP[u][1] %= mod;
            }
        }
    };

    ll ans = 1;

    for(int node = 1 ; node <= n ; node++){
        if(!vis[node]){
            DFS(node);
            ans *= (DP[node][0] + DP[node][1]) % mod;
            ans %= mod;
        }
    }

    cout << ans;

    return 0;
}