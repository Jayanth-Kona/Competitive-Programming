#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;

/*

Idea: Ordered DP calculation --> sort

*/

int main(){
    int n , m ; cin >> n >> m;

    vector<vector<int>> grid(n , vector<int>(m));
    for(vector<int> &row : grid) for(int &cell : row) cin >> cell;

    vector<int> order(n * m);
    iota(order.begin() , order.end() , 0);
    sort(order.begin() , order.end() , [&](int i , int j){
        return grid[i / m][i % m] < grid[j / m][j % m];
    });

    int delta[5] = {-1 , 0 , +1 , 0 , -1};

    int ans = 0;
    vector<vector<int>> dp(n , vector<int>(m));

    for(int cell : order){
        int r = cell / m;
        int c = cell % m;

        dp[r][c] = 1;

        for(int d = 0 ; d < 4 ; d++){
            int nr = r + delta[d];
            int nc = c + delta[d + 1];
            if(min(nr , nc) >= 0 && nr < n && nc < m && grid[nr][nc] < grid[r][c]){
                dp[r][c] += dp[nr][nc];
                if(dp[r][c] >= mod) dp[r][c] -= mod;
            }
        }

        ans += dp[r][c];
        if(ans >= mod) ans -= mod;
    }

    cout << ans;

    return 0;
}