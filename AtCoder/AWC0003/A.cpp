#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll n , k ; cin >> n >> k;

    ll ans = 0;

    for(int i = 1 ; i <= n ; i++){
        ll ai , bi ; cin >> ai >> bi;
        ans += ai * bi >= k;
    }

    cout << ans;

    return 0;
}