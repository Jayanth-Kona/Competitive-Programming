#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int mod = 1e9 + 7;

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
	if(N < R) return 0;
	ll res = 1;
	for(ll i = 1 ; i <= R ; i++){
		res = (res * (N - i + 1)) % mod;
		res = (res * power(i , mod - 2)) % mod;
	}
	return res;
}

int main(){
	cout << NCR(144 , 12);
	return 0;
}