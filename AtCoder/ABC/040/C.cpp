#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int n ; cin >> n;

    vector<int> a(n);
    for(int &num : a) cin >> num;

    ll dp2 = 0;
    ll dp1 = abs(a[0] - a[1]);

    for(int i = 2 ; i < n ; i++){
        ll dp = min(dp1 + abs(a[i] - a[i - 1]) , dp2 + abs(a[i] - a[i - 2]));
        dp2 = dp1;
        dp1 = dp;
    }

    cout << dp1;

    return 0;
}