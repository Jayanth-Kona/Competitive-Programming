#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define FOR(i , n) for(int i = 0 ; i < n ; i++)

int mod = 1e9 + 7;
 
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
    FastNCR fast(10000);

    int r , c ; cin >> r >> c;
    int x , y ; cin >> x >> y;
    int d , l ; cin >> d >> l;

    int ways = 0;

    FOR(top , 2) FOR(bottom , 2) FOR(left , 2) FOR(right , 2){
        int nx = x - top - bottom;
        int ny = y - left - right;

        if(min(nx , ny) <= 0) continue;

        int cellsAvailable = nx * ny;
        int emptyBorders = top + bottom + left + right;

        int curr = fast.NCR(cellsAvailable , d + l);
        curr = curr * fast.Fact[d + l] % mod;
        curr = curr * fast.InvFact[d]  % mod;
        curr = curr * fast.InvFact[l]  % mod;

        if(emptyBorders & 1) ways += mod - curr;
        else ways += curr;

        if(ways >= mod) ways -= mod;
    }

    int rectangles = (r - x + 1) * (c - y + 1);
    ways = ways * 1LL * rectangles % mod;

    cout << ways << "\n";

    return 0;
}