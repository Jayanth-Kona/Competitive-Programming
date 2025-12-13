#include<bits/stdc++.h>
using namespace std;
using ll = long long;

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
		if(N < R) return 0;
		return Fact[N] * InvFact[R] % mod * InvFact[N - R] % mod;
	}
};


int main(){
	FastNCR fast(1e5+5);
	return 0;
}