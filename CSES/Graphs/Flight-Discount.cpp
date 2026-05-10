#include<bits/stdc++.h>
using namespace std;
using ll = long long;
 
struct edge{
    int u;
    int v;
    int w;
};
 
vector<ll> dijkstra(int n , int s , vector<vector<array<int , 2>>> &graph){
    vector<ll> dist(n + 1 , 1e18);
    dist[s] = 0;
 
    set<array<ll , 2>> set;
    set.insert({dist[s] , s});
    
    while(set.empty() == false){
        auto [dist_u , u] = *set.begin();
        set.erase(*set.begin());
 
        if(dist_u > dist[u]) continue;
 
        for(auto [v , dist_uv] : graph[u]){
            if(dist_u + dist_uv < dist[v]){
                dist[v] = dist_u + dist_uv;
                set.insert({dist[v] , v});
            }
        }
    }
 
    return dist;
}
 
int main(){
    int n , m ; cin >> n >> m;
 
    vector<vector<array<int , 2>>> graph1(n + 1) , graph2(n + 1);
 
    vector<edge> edges(m);
    for(edge &e : edges){
        cin >> e.u >> e.v >> e.w;
        graph1[e.u].push_back({e.v , e.w});
        graph2[e.v].push_back({e.u , e.w});
    }
 
    vector<ll> D1 = dijkstra(n , 1 , graph1);
    vector<ll> DN = dijkstra(n , n , graph2);
 
    ll ans = 1e18;
    
    for(edge &e : edges){
        ll curr = D1[e.u] + (e.w / 2) + DN[e.v];
        ans = min(ans , curr);
    }
 
    cout << ans;
 
    return 0;
}