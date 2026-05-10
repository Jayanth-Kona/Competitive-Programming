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
 
    vector<int> color(n + 2 , 0);
 
    queue<int> queue;
    for(int i = 1 ; i <= n ; i++){
        if(color[i] == 0){
            color[i] = 1;
            queue.push(i);
            while(queue.empty() == false){
                int k = queue.size();
                while(k--){
                    int u = queue.front();
                    queue.pop();
                    for(int v : graph[u]){
                        if(color[v] == 0){
                            queue.push(v);
                            color[v] = color[u] ^ 1 ^ 2;
                        }
                        else if(color[v] == color[u]){
                            cout << "IMPOSSIBLE";
                            return 0;
                        }
                    }
                }
            }
        }
    }
 
    for(int i = 1 ; i <= n ; i++) cout << color[i] << " ";
 
    return 0;
}