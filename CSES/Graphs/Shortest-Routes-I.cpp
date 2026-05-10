#include<bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main(){
    int n , m ; cin >> n >> m;
 
    using Node = array<ll , 2>;
    vector<vector<Node>> graph(n + 1);
 
    for(int i = 1 ; i <= m ; i++){
        int u , v , w;
        cin >> u >> v >> w;
        graph[u].push_back({v , w});
    }
 
 
    vector<ll> dist(n + 1 , 1e18);
    priority_queue<Node , vector<Node> , greater<Node>> minHeap;
    minHeap.push({dist[1] = 0 , 1});
 
    while(minHeap.empty() == false){
        auto [d , u] = minHeap.top();
        minHeap.pop();
 
        if(d > dist[u]) continue;
 
        for(auto [v , uv] : graph[u]){
            if(d + uv < dist[v]){
                minHeap.push({dist[v] = d + uv , v});
            }
        }
    }
 
    for(int u = 1 ; u <= n ; u++) cout << dist[u] << " ";
 
    return 0;
}