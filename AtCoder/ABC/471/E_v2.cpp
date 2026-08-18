#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 998244353;

ll power(ll a , ll b){
    ll res = 1;
    while(b){
        if(b & 1) res = (res * a) % mod;
        a = (a  * a) % mod;
        b >>= 1;
    }
    return res;
}

ll NCR(ll N , ll R){
    if(N < R || R < 0) return 0;
    ll res = 1;
    for(ll i = 1 ; i <= R ; i++){
        res = (res * (N - i + 1)) % mod;
        res = (res * power(i , mod - 2)) % mod;
    }
    return res;
}


int main(){
    int N , K ; cin >> N >> K;
    
    vector<ll> A(N);
    ll sumA = 0,  sumA2 = 0;
    
    for(ll &num : A){
        cin >> num;
        sumA = (sumA + num) % mod;
        sumA2 = (sumA2 + num * num) % mod;
    }

    ll term1 = NCR(N - 1 , K - 1) * sumA2 % mod;
    ll term2 = NCR(N - 2 , K - 2) * ((sumA * sumA % mod - sumA2 + mod) % mod) % mod;
    
    cout << (term1 + term2) % mod;

    return 0;
}