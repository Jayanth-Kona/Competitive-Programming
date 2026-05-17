#include<bits/stdc++.h>
using namespace std;

class RollingHash{
public:
    using ll = long long;

    ll M = 1e9 + 7;
    vector<ll> PH , POWER;

    RollingHash(vector<int> &S , ll P){
        int N = S.size();
        PH.resize(N + 1 , 0) , POWER.resize(N + 1 , 1);
        for(ll i = 1 ; i <= int(S.size()) ; i++){
            PH[i] = (PH[i - 1] * P % M + S[i - 1]) % M;
            POWER[i] = POWER[i - 1] * P % M;
        }
    }

    ll hashValue(int L , int R){
        return (PH[R + 1] - PH[L] * POWER[R - L + 1] % M + M) % M;
    }
};

int main(){

    return 0;
}