#include<bits/stdc++.h>
using namespace std;

int main(){
    int n , m ; cin >> n >> m;

    bool know[12][12]{};
    for(int i = 1 ; i <= m ; i++){
        int u , v ; cin >> u >> v;
        u-- , v--;
        know[u][v] = true;
        know[v][u] = true;
    }

    for(int u = 0 ; u < n ; u++){
        know[u][u] = true;
    }

    vector<bool> dp(1 << n , false);
    for(int u = 0 ; u < n ; u++) dp[1 << u] = true;

    int ans = 0;

    for(int mask = 0 ; mask < (1 << n) ; mask++){
        if(dp[mask] == true){
            for(int u = 0 ; u < n ; u++){
                if(mask >> u & 1 ^ 1){
                    int good = 1;
                    for(int v = 0 ; v < n && good ; v++){
                        if(mask >> v & 1){
                            good &= know[u][v];
                        }
                    }
                    if(good) dp[mask | (1 << u)] = true;
                }
            }
            ans = max(ans , __builtin_popcount(mask));
        }
    }

    cout << ans  << "\n";

    return 0;
}