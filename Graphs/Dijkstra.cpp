#include<bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> Disjkstra(int n , int s , vector<vector<array<int, 2>>> &graph){
    using node = array<ll , 2>;

    vector<ll> dist(n + 1 , -1e18);

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
    return 0;
}