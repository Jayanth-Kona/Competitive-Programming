#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int n , m , k ; cin >> n >> m >> k;

    vector<vector<ll>> dp(n + 1 , vector<ll>(m + 1 , -1e18));
    dp[0][0] = 0;

    vector<ll> a(n + 1) , b(n + 1);
    for(int i = 1 ; i <= n ; i++) cin >> a[i] >> b[i];

    ll profit = 0;

    for(int i = 1 ; i <= n ; i++){
        for(int spent = b[i] ; spent <= m ; spent++){
            dp[i][spent] = a[i];
            for(int j = max(0 , i - k) ; j <= i - 1 ; j++){
                dp[i][spent] = max(dp[i][spent] , a[i] + dp[j][spent - b[i]]);
            }
            profit = max(profit , dp[i][spent]);
        }
    }

    cout << profit;

    return 0;
}