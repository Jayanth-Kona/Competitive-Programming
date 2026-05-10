#include<bits/stdc++.h>
using namespace std;
using ll = long long;
 
struct edge{
    int u;
    int v;
    int w;
};
 
int main(){
    int n , m ; cin >> n >> m;
 
    vector<edge> edges(m);
    for(edge &e : edges) cin >> e.u >> e.v >> e.w;
 
    vector<ll> dist(n + 1 , +1e18);
    vector<bool> isCycleNode(n + 1 , false);
    vector<int> from(n + 1 , -1);
    
    for(int node = 1 ; node <= n ; node++){
        if(from[node] == -1){
            dist[node] = 0;
            from[node] = -1;
 
            for(int iter = 1 ; iter <= n ; iter++){
                bool any = false;
                for(edge &e : edges){
                    if(dist[e.u] != +1e18 && dist[e.u] + e.w < dist[e.v]){
                        dist[e.v] = dist[e.u] + e.w;
                        from[e.v] = e.u;
                        any = true;
                        if(iter == n) isCycleNode[e.v] = true;
                    }
                }
                if(any == false) break;
            }
 
            if(count(isCycleNode.begin() , isCycleNode.end() , true) >= 1){
                for(int i = 1 ; i <= n ; i++){
                    if(isCycleNode[i]){
                        cout << "YES\n";
 
                        int u = i;
                        for(int T = 1 ; T <= n ; T++) u = from[u];
 
                        vector<int> cycle;
                        for(int v = u ; v != -1 ; v = from[v]){
                            cycle.push_back(v);
                            if(v == u && cycle.size() > 1) break;
                        }
 
                        reverse(cycle.begin() , cycle.end());
                        for(int node : cycle) cout << node << " ";
                        return 0;
                    }
                }
            }
        }
    }
 
    cout << "NO";
 
    return 0;
}