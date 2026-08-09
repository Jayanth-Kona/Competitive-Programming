#include<bits/stdc++.h>
using namespace std;

// Problem: https://www.acwing.com/problem/content/12/

int main(){
    int n , m ; cin >> n >> m;

    vector<int> w(n + 1) , v(n + 1);
    for(int i = 1 ; i <= n ; i++){
        cin >> w[i] >> v[i];
    }

    vector<vector<int>> dp(n + 2 , vector<int>(m + 2 , 0));

    for(int i = n ; i >= 1 ; i--){
        for(int j = 0 ; j <= m ; j++){
            dp[i][j] = dp[i + 1][j];
            if(j - w[i] >= 0) dp[i][j] = max(dp[i][j] , v[i] + dp[i + 1][j - w[i]]);
        }
    }

    vector<int> ans;

    int reqd = dp[1][m];
    int item = 1 , capacity = m;

    while(reqd > 0){
        if(capacity - w[item] >= 0 && v[item] + dp[item + 1][capacity - w[item]] == reqd){
            ans.push_back(item);
            capacity -= w[item];
            reqd -= v[item];
            item += 1;
        }
        else{
            item += 1;
        }
    }

    for(int item : ans) cout << item << " ";

    return 0;
}