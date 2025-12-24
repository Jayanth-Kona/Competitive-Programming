#include<bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main(){
    int n , k;
    cin >> n >> k;
 
    ll x0 , a , b , c;
    cin >> x0 >> a >> b >> c;
 
    vector<int> x(n);
    x[0] = x0;
    for(int i = 1 ; i < n ; i++) x[i] = (a * x[i - 1] % c + b) % c;
 
    vector<int> p(n);
    p[0] = x[0];
    for(int i = 1 ; i < n ; i++){
        if(i % k == 0) p[i] = x[i];
        else p[i] = p[i - 1] | x[i];
    }
 
    vector<int> s(n);
    s[n - 1] = x[n - 1];
    for(int i = n - 2 ; i >= 0 ; i--){
        if(i % k == 0) s[i] = x[i];
        else s[i] = s[i + 1] | x[i];
    }
 
    ll xor_or = 0;
    for(int i = 0 ; i + k - 1 < n ; i++){
        int curr_or = s[i] | p[i + k - 1];
        xor_or ^= curr_or;
    }
 
    cout << xor_or;
 
    return 0;
}
