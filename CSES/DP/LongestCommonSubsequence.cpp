#include<bits/stdc++.h>
using namespace std;

int main(){

    int n , m ; cin >> n >> m;

    vector<int> a(n) , b(n);

    for(int &num : a) cin >> num;
    for(int &num : b) cin >> num;

    vector<vector<int>> dp(n + 1 , vector<int>(m + 1));

    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= m ; j++){
            if(a[i - 1] != b[j - 1]){
                dp[i][j] = max(dp[i - 1][j] , dp[i][j - 1]);
            }
            else{
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
        }
    }

    int i = n , j = m;
    vector<int> sequence;

    while(min(i , j) > 0){
        if(a[i - 1] == b[j - 1]){
            sequence.push_back(a[i - 1]);
            i--;
            j--;
        }
        else{
            if(dp[i - 1][j] > dp[i][j - 1]){
                i--;
            }
            else{
                j--;
            }
        }
    }
    reverse(sequence.begin() , sequence.end());

    cout << dp[n][m] << endl;
    
    for(int num : sequence) cout << num << " ";

    return 0;
}