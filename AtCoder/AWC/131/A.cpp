#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int n ; cin >> n;

    ll presents = n , ans = 0;

    for(int i = 1 ; i <= n ; i++){
        ll stumbles ; cin >> stumbles;
        presents -= stumbles;
        ans += presents > 0;
        presents = max(0LL , presents - 1);
    }

    cout << ans;

    return 0;
}