#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int n , m , t;
    cin >> n >> m >> t;

    vector<vector<array<ll , 2>>> graph(n + 1);
    for(int i = 1 ; i <= m ; i++){
        ll u , v , w;
        cin >> u >> v >> w;
        graph[u].push_back({v , w});
        graph[v].push_back({u , w});
    }

    vector<ll> Time(n + 1 , 1e18);

    using node = array<ll , 2>;
    priority_queue<node , vector<node> , greater<node>> minHeap;
    minHeap.push({Time[1] = 0 , 1});

    while(minHeap.empty() == false){
        auto [ut , u] = minHeap.top();
        minHeap.pop();

        if(ut > Time[u]) continue; // old entry -> no need to process, as we already have minimum for u and its neigh's

        if(u == t){
            cout << (2LL * ut);
            return 0;
        }

        for(auto &[v , w] : graph[u]){
            if(ut + w < Time[v]){
                minHeap.push({Time[v] = ut + w , v});
            }
        }
    }

    cout << "-1";

    return 0;
}