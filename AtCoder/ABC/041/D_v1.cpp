#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int n , m ; cin >> n >> m;

    vector<int> reqd(n , 0);
    for(int i = 1 ; i <= m ; i++){
        int u , v ; cin >> u >> v;
        reqd[v - 1] |= 1 << (u - 1);
    }
    
    vector<ll> DP(1 << 16 , -1);

    function<ll(int , int)> DFS = [&](int pos , int mask){
        if(pos == n) return 1LL;

        if(DP[mask] != -1) return DP[mask];

        ll ans = 0;

        for(int v = 0 ; v < n ; v++){
            if((mask >> v & 1 ^ 1) && (mask & reqd[v]) == reqd[v]){
                ans += DFS(pos + 1 , mask | 1 << v);
            }
        }

        return DP[mask] = ans;
    };

    cout << DFS(0 , 0);

    return 0;
}