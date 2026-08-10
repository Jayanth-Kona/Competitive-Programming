#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll DP[20][154][10][2][2];

ll DFS(string &num , int k , int pos = 0 , int p = 0 , int t = 1 , int s = 0){
    if(k < 0) return 0;
    if(pos == num.size()) return s > 0 && k == 0;

    ll &ans = DP[pos][k][p][t][s];
    if(ans != -1) return ans;

    ans = 0;
    int limit = t ? num[pos] - '0' : 9;

    for(int d = 0 ; d <= limit ; d++){
        ans += DFS(num , k - (s ? abs(p - d) : 0) , pos + 1 , s | (d > 0) ? d : p , t & (d == limit) , s | (d > 0));
    }

    return ans;
}

int main(){
    memset(DP , -1 , sizeof DP);
    
    int k;
    string num;
    cin >> num >> k;

    cout << DFS(num , k);

    return 0;
}