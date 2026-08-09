#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll dist(int n , ll x , ll y){
    return abs((x - 1) / n - (y - 1) / n) + abs((x - 1) % n - (y - 1) % n);
}

int main(){
    ll n , m ; cin >> n >> m;
    ll s , t ; cin >> s >> t;

    m++;
    vector<ll> points(m);
    points[0] = s;
    for(int i = 1 ; i < m ; i++) cin >> points[i];

    vector<vector<ll>> dp(1 << m , vector<ll>(m , 1e18)); // {mask , last} -> cost
    dp[1][0] = 0; // from s: (mask=0000001)(index=0)

    for(int mask = 1 ; mask < (1 << m) ; mask++){
        for(int from = 0 ; from < m ; from++){
            if(mask >> from & 1){
                for(int to = 0 ; to < m ; to++){
                    if(mask >> to & 1 ^ 1){
                        int newmask = mask | 1 << to;
                        dp[newmask][to] = min(dp[newmask][to] , dist(n , points[from] , points[to]) + dp[mask][from]);
                    }
                }
            }
        }
    }

    ll mincost = 1e18;

    for(int last = 0 ; last < m ; last++) mincost = min(mincost , dist(n , points[last] , t) + dp[(1 << m) - 1][last]);

    cout << mincost;

    return 0;
}