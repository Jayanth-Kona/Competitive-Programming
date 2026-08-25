#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll Dijkstra(int n , int maxp , vector<int> &p , vector<vector<array<int , 2>>> &graph){
    vector<ll> dist(n , 1e18);

    priority_queue<array<ll , 2> , vector<array<ll , 2>> , greater<array<ll , 2>>> minHeap;
    minHeap.push({dist[0] = 0 , 0});

    while(minHeap.empty() == false){
        auto [du , u] = minHeap.top();
        minHeap.pop();

        if(u == n - 1) break;

        if(dist[u] < du) continue;

        for(auto &[v , uv] : graph[u]){
            if(p[v] <= maxp && du + uv < dist[v]){
                minHeap.push({dist[v] = du + uv , v});
            }
        }
    }

    return dist[n - 1];
}

int main(){
    int n , m , t;
    cin >> n >> m >> t;

    vector<int> p(n);
    for(int &pi : p) cin >> pi;

    vector<vector<array<int , 2>>> graph(n);

    for(int i = 1 ; i <= m ; i++){
        int u , v , w;
        cin >> u >> v >> w;
        graph[u - 1].push_back({v - 1 , w});
        graph[v - 1].push_back({u - 1 , w});
    }

    vector<int> space = p;
    sort(space.begin() , space.end());
    space.erase(unique(space.begin() , space.end()) , space.end());

    int low = lower_bound(space.begin() , space.end() , max(p[0] , p[n - 1])) - space.begin() , high = space.size() - 1;
    int ans = high;

    while(low <= high){
        int mid = (low + high) >> 1;

        if(Dijkstra(n , space[mid] , p , graph) <= t) high = (ans = mid) - 1;
        else low = mid + 1;
    }

    cout << space[ans];

    return 0;
}