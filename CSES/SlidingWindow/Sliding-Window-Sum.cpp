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
    
 
    ll sum = 0;
    for(int i = 0 ; i < k - 1 ; i++) sum += x[i];
 
    ll xor_sum = 0;
    for(int i = k - 1 ; i < n ; i++){
        sum += x[i];
        xor_sum ^= sum;
        sum -= x[i - k + 1];
    }
 
    cout << xor_sum;
 
    return 0;
}