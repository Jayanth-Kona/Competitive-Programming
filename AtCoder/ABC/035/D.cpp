#include<bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> Dijsktra(int s , int n , vector<vector<array<int , 2>>> &graph){
    vector<ll> dist(n + 1 , 2e18);

    using type = array<ll , 2>;
    priority_queue<type , vector<type> , greater<type>> minHeap;

    minHeap.push({dist[s] = 0 , s});

    while(minHeap.empty() == false){
        auto [d_u , u] = minHeap.top();
        minHeap.pop();

        if(d_u > dist[u]) continue;

        for(auto &[v , d_uv] : graph[u]){
            if(d_u + d_uv < dist[v]){
                minHeap.push({dist[v] = d_u + d_uv , v});
            }
        }
    }

    return dist;
}

int main(){
    int n , m , t;
    cin >> n >> m >> t;

    vector<int> a(n + 1);
    for(int node = 1 ; node <= n ; node++) cin >> a[node];

    vector<vector<array<int , 2>>> graph1(n + 1) , graph2(n + 1);

    for(int e = 1 ; e <= m ; e++){
        int u , v , w;
        cin >> u >> v >> w;
        graph1[u].push_back({v , w});
        graph2[v].push_back({u , w});
    }

    vector<ll> d1 = Dijsktra(1 , n , graph1);
    vector<ll> d2 = Dijsktra(1 , n , graph2);

    ll ans = 0;

    for(int node = 1 ; node <= n ; node++){
        ll Arrive = d1[node];
        ll Return = d2[node];

        ll stay = t - Arrive - Return;

        if(stay > 0){
            ans = max(ans , stay * a[node]);
        }
    }

    cout << ans << "\n";

    return 0;
}