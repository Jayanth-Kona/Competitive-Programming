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
 
    vector<int> timer(n + 1 , -1) , from(n + 1 , -1);
 
 
    function<int(int , int)> DFS = [&](int u , int currTime){
        if(timer[u] != -1){
            int nodes = currTime - timer[u];
            if(nodes >= 3){
                cout << nodes + 1 << "\n";
                for(int v = u ; nodes-- ; v = from[v]) cout << v << " ";
                cout << u;
                return 1;
            }
            else{
                return 0;
            }
        }
        else{
            timer[u] = currTime;
            for(int v : graph[u]){
                int oldfromv = from[v];
                from[v] = u;
                if(DFS(v , currTime + 1)) return 1;
                from[v] = oldfromv;
            }
            return 0;
        }
    };
 
    for(int u = 1 ; u <= n ; u++){
        if(timer[u] == -1 && DFS(u , 0)){
            return 0;
        }
    }
 
    cout << "IMPOSSIBLE";
 
    return 0;
}