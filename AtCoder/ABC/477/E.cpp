#include<bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> Dijkstra(int n , int s , vector<vector<array<int , 2>>> &graph){
    vector<ll> dist(n + 1 , 2e18);

    using node = array<ll , 2>;
    priority_queue<node , vector<node> , greater<node>> minHeap;

    minHeap.push({dist[s] = 0 , s});

    while(minHeap.empty() == false){
        auto [du , u] = minHeap.top();
        minHeap.pop();

        if(dist[u] < du) continue;

        for(auto &[v , duv] : graph[u]){
            if(du + duv < dist[v]){
                minHeap.push({dist[v] = du + duv , v});
            }
        }
    }

    return dist;
}

int main(){
    int n , q ; cin >> n >> q;

    vector<vector<array<int , 2>>> graph(n + 2);

    vector<ll> p(n + 1);
    p[0] = 0;

    for(int u = 1 ; u <= n ; u++){
        int v = u % n + 1;
        int w ; cin >> w;
        graph[u].push_back({v , w});
        graph[v].push_back({u , w});

        p[u] = p[u - 1] + w;
    }

    for(int u = 1 ; u <= n ; u++){
        int v = n + 1;
        int w ; cin >> w;
        graph[u].push_back({v , w});
        graph[v].push_back({u , w});
    }

    vector<ll> minDist = Dijkstra(n + 1 , n + 1 , graph);

    for(int i = 1 ; i <= q ; i++){
        int u , v ; cin >> u >> v;

        if(v == n + 1){
            cout << minDist[u] << "\n";
        }
        else{
            ll uv1 = p[v - 1] - p[u - 1];
            ll uv2 = p[n] - uv1;
            ll uv3 = minDist[u] + minDist[v];
            cout << min({uv1 , uv2 , uv3}) << "\n";
        }
    }

    return 0;
}