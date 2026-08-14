#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int n , a ; cin >> n >> a;

    vector<int> x(n);
    for(int &num : x) cin >> num;

    int tot = accumulate(x.begin() , x.end() , 0);

    vector<vector<ll>> dp(n + 1 , vector<ll>(tot + 1 , 0));
    dp[0][0] = 1;

    for(int i = 0 ; i < n ; i++){
        for(int cnt = i + 1 ; cnt >= 1 ; cnt--){
            for(int sum = tot ; sum >= x[i] ; sum--){
                dp[cnt][sum] += dp[cnt - 1][sum - x[i]];
            }
        }
    }

    ll ways = 0;
    for(int cnt = 1 ; cnt <= n && cnt * a <= tot ; cnt++) ways += dp[cnt][cnt * a];

    cout << ways;
    
    return 0;
}