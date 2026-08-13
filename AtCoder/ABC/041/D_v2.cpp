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
    
    vector<ll> DP(1 << 16 , 0);
    DP[0] = 1;

    for(int mask = 0 ; mask < (1 << n) ; mask++){
        for(int v = 0 ; v < n ; v++){
            if((mask >> v & 1 ^ 1) && (mask & reqd[v]) == reqd[v]){
                DP[mask | 1 << v] += DP[mask];
            }
        }
    }

    cout << DP[(1 << n) - 1];

    return 0;
}