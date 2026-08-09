#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int n ; cin >> n;

    ll ans = 0;

    for(int i = 1 , p = 0 ; i <= n ; i++){
        int num ; cin >> num;
        if(i > 1 && num > p) ans += num / 2;
        else ans += num;
        p = num;
    }

    cout << ans;

    return 0;
}