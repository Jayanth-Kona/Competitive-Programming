#include<bits/stdc++.h>
using namespace std;
 
int main(){
    int n , m ; cin >> n >> m;
 
    vector<vector<int>> graph(n + 1);
    for(int i = 1 ; i <= m ; i++){
        int u , v ; cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
 
    vector<int> parent(n + 1 , 0);
    parent[n] = n;
 
    queue<int> queue;
    queue.push(n);
 
    for(int level = 0 ; queue.empty() == false ; level++){
        int k = queue.size();
 
        while(k--){
            int u = queue.front();
            queue.pop();
 
            if(u == 1){
                cout << level + 1 << "\n";
                for(int v = u ; v != n ; v = parent[v]){
                    cout << v << " ";
                }
                cout << n;
                return 0;
            }
 
            for(int v : graph[u]){
                if(parent[v] == 0){
                    queue.push(v);
                    parent[v] = u;
                }
            }
        }
 
    }
 
    cout << "IMPOSSIBLE";
 
    return 0;
}