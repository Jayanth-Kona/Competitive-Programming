#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll n , s ; cin >> n >> s;

    if(s > n){
        cout << "-1";
        return 0;
    }

    if(s == n){
        cout << (n + 1);
        return 0;
    }

    for(ll b = 2 ; b <= min(n , (ll)1e6) ; b++){
        ll sum = 0;
        for(ll num = n ; num > 0 ; num /= b){
            sum += num % b;
        }
        if(sum == s){
            cout << b;
            return 0;
        }
    }

    ll min_base = 1e18;

    for(ll F = 1 ; F * F <= n - s ; F++){
        if((n - s) % F == 0){
            for(ll b : {F + 1 , (n - s) / F + 1}){
                ll c2 = (n - s) / (b - 1);
                ll c1 = s - c2;
                if(0 <= c1 && max(c1 , c2) < b && c1 + c2 == s && c1 + c2 * b == n){
                    min_base = min(min_base , b);
                }
            }
        }
    }

    if(min_base == 1e18){
        cout << "-1";
    }
    else{
        cout << min_base;
    }

    return 0;
}