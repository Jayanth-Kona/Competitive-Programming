#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 998244353;

class FastNCR{
public:
    vector<ll> Fact , InvFact;
    
    FastNCR(int N){
        Fact.resize(N + 5);
        Fact[0] = 1;
        for(ll num = 1 ; num <= N ; num++) Fact[num] = num * Fact[num - 1] % mod;

        InvFact.resize(N + 5);
        InvFact[N] = power(Fact[N] , mod - 2);
        for(ll num = N - 1 ; num >= 0 ; num--) InvFact[num] = (num + 1) * InvFact[num + 1] % mod;
    }
    
    ll power(ll a , ll b){
        ll res = 1;
        while(b){
            if(b & 1) res = (res * a) % mod;
            a = (a  * a) % mod;
            b >>= 1;
        }
        return res % mod;
    }

    ll NCR(ll N , ll R){
        if(N < R || R < 0) return 0;
        return Fact[N] * InvFact[R] % mod * InvFact[N - R] % mod;
    }
};


int main(){
    int N , K ; cin >> N >> K;
    
    vector<ll> A(N);
    ll sumA = 0,  sumA2 = 0;
    
    for(ll &num : A){
        cin >> num;
        sumA = (sumA + num) % mod;
        sumA2 = (sumA2 + num * num) % mod;
    }

    FastNCR fast(N + 1);

    ll term1 = fast.NCR(N - 1 , K - 1) * sumA2 % mod;
    ll term2 = fast.NCR(N - 2 , K - 2) * ((sumA * sumA % mod - sumA2 + mod) % mod) % mod;
    
    cout << (term1 + term2) % mod;

    return 0;
}