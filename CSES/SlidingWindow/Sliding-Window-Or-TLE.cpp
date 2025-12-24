#include<bits/stdc++.h>
using namespace std;
using ll = long long;
 
int bit[32];
 
void add(int num){
    for(int pos = 31 ; pos >= 0 ; pos--) if(num >> pos & 1) bit[pos]++;
}
 
void rem(int num){
    for(int pos = 31 ; pos >= 0 ; pos--) if(num >> pos & 1) bit[pos]--;
}
 
ll val(){
    ll OR = 0;
    for(int pos = 31 ; pos >= 0 ; pos--) if(bit[pos]) OR |= 1 << pos;
    return OR;
}
 
int main(){
    int n , k;
    cin >> n >> k;
 
    ll x0 , a , b , c;
    cin >> x0 >> a >> b >> c;
 
    vector<ll> x(n);
    x[0] = x0;
    for(int i = 1 ; i < n ; i++) x[i] = (a * x[i - 1] % c + b) % c;
    
    for(int i = 0 ; i < k - 1 ; i++) add(x[i]);
 
    ll xor_or = 0;
    for(int i = k - 1 ; i < n ; i++){
        add(x[i]);
        xor_or  ^= val();
        rem(x[i]);
    }
 
    cout << xor_or;
 
    return 0;
}