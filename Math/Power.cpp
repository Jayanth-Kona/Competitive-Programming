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


int count()

int main(){
	cout << power(6 , mod - 2);
	return 0;
}



