#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;

/*

Idea: Ordered DP calculation --> DAG

*/

int main(){
    int n , m ; cin >> n >> m;

    vector<vector<int>> grid(n , vector<int>(m));
    for(vector<int> &row : grid) for(int &cell : row) cin >> cell;

    int delta[5] = {-1 , 0 , +1 , 0 , -1};

    queue<array<int , 2>> queue;
    vector<vector<int>> indegree(n , vector<int>(m , 0));

    for(int r = 0 ; r < n ; r++){
        for(int c = 0 ; c < m ; c++){
            for(int d = 0 ; d < 4 ; d++){
                int nr = r + delta[d];
                int nc = c + delta[d + 1];
                if(min(nr , nc) >= 0 && nr < n && nc < m && grid[r][c] > grid[nr][nc]){
                    indegree[r][c]++;
                }
            }
            if(indegree[r][c] == 0) queue.push({r , c});
        }
    }

    int ans = 0;
    vector<vector<int>> dp(n , vector<int>(m));

    while(queue.empty() == false){
        auto [r , c] = queue.front();
        queue.pop();

        dp[r][c] = 1;

        for(int d = 0 ; d < 4 ; d++){
            int nr = r + delta[d];
            int nc = c + delta[d + 1];

            if(min(nr , nc) >= 0 && nr < n && nc < m){

                if(grid[r][c] > grid[nr][nc]){
                    dp[r][c] += dp[nr][nc];
                    if(dp[r][c] >= mod) dp[r][c] -= mod;
                }

                if(grid[r][c] < grid[nr][nc] && --indegree[nr][nc] == 0){
                    queue.push({nr , nc});
                }

            }
        }

        ans += dp[r][c];
        if(ans >= mod) ans -= mod;
    }

    cout << ans;

    return 0;
}