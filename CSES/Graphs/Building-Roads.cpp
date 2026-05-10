#include<bits/stdc++.h>
using namespace std;
 
int main(){
    int n , m ; cin >> n >> m;
 
    vector<vector<int>> graph(n + 1);
 
    for(int E = 1 ; E <= m ; E++){
        int u , v ; cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
 
    vector<bool> vis(n + 1 , false);
 
    auto DFS = [&](auto &&self, int u) -> void{
        vis[u] = true;
        for(int v : graph[u]) if(!vis[v]) self(self , v);
    };
 
    vector<int> heads;
 
    for(int u = 1 ; u <= n ; u++){
        if(!vis[u]){
            heads.push_back(u);
            DFS(DFS , u);
        }
    }
 
    cout << heads.size() - 1 << endl;
 
    for(int i = 1 ; i < (int)heads.size() ; i++){
        cout << heads[i - 1] << " " << heads[i] << endl;
    }
 
    return 0;
}