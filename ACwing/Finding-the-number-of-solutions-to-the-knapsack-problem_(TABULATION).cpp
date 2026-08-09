#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;

// Problem: https://www.acwing.com/problem/content/11/

int main(){
    int n , m ; cin >> n >> m;

    vector<int> w(n) , v(n);
    for(int i = 0 ; i < n ; i++) cin >> w[i] >> v[i];

    vector<vector<int>> dp(n + 1 , vector<int>(m + 1 , 0));
    vector<vector<int>> ways(n + 1 , vector<int>(m + 1 , 0));
    ways[0][0] = 1;

    for(int i = 1 ; i <= n ; i++){
        for(int j = 0 ; j <= m ; j++){
            dp[i][j] = dp[i - 1][j];
            ways[i][j] = ways[i - 1][j];

            if(j - w[i - 1] >= 0 && ways[i - 1][j - w[i - 1]] > 0){
                if(dp[i][j] == v[i - 1] + dp[i - 1][j - w[i - 1]]){
                    ways[i][j] += ways[i - 1][j - w[i - 1]];
                    if(ways[i][j] >= mod) ways[i][j] -= mod;
                }
                else if(dp[i][j] < v[i - 1] + dp[i - 1][j - w[i - 1]]){
                    dp[i][j] = v[i - 1] + dp[i - 1][j - w[i - 1]];
                    ways[i][j] = ways[i - 1][j - w[i - 1]];
                }
            }
        }
    }

    int maxVal = 0 , ans = 0;
    for(int j = 0 ; j <= m ; j++){
        if(dp[n][j] == maxVal){
            ans += ways[n][j];
            if(ans >= mod) ans -= mod;
        }
        else if(dp[n][j] > maxVal){
            maxVal = dp[n][j];
            ans = ways[n][j];
        }
    }

    cout << ans;

    return 0;
}