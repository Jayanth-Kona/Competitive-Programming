#include<bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main(){
    int n , k;
    cin >> n >> k;
 
    ll x0 , a , b , c;
    cin >> x0 >> a >> b >> c;
 
    vector<ll> x(n);
    x[0] = x0;
    for(int i = 1 ; i < n ; i++) x[i] = (a * x[i - 1] % c + b) % c;
    
 
    ll curr_xor = 0;
    for(int i = 0 ; i < k - 1 ; i++) curr_xor ^= x[i];
 
    ll xor_xor = 0;
    for(int i = k - 1 ; i < n ; i++){
        curr_xor ^= x[i];
        xor_xor  ^= curr_xor;
        curr_xor ^= x[i - k + 1];
    }
 
    cout << xor_xor;
 
    return 0;
}