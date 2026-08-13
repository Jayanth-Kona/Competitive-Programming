#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int n ; cin >> n;

    ll ans = 0;

    for(int i = 1 , l = 0 , p = 0 ; i <= n ; i++){
        int num ; cin >> num;
        l = p < num ? l + 1 : 1;
        ans += l;
        p = num;
    }

    cout << ans;

    return 0;
}