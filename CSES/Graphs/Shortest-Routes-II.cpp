#include<bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main(){
    int n , m , q;
    cin >> n >> m >> q;
 
    vector<vector<ll>> dist(n + 1 , vector<ll>(n + 1 , 1e18));
 
    for(int i = 1 ; i <= m ; i++){
        int u , v , w;
        cin >> u >> v >> w;
        dist[u][v] = min(dist[u][v] , 1LL * w);
        dist[v][u] = min(dist[v][u] , 1LL * w);
 
    }
 
    for(int i = 1 ; i <= n ; i++) dist[i][i] = 0;
 
    for(int k = 1 ; k <= n ; k++){
        for(int u = 1 ; u <= n ; u++){
            for(int v = 1 ; v <= n ; v++){
                dist[u][v] = min(dist[u][v] , dist[u][k] + dist[k][v]);
            }
        }
    }
 
    while(q--){
        int u , v ; cin >> u >> v;
        if(dist[u][v] == 1e18) cout << "-1\n";
        else cout << dist[u][v] << "\n";
    }
 
    return 0;
}