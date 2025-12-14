#include<bits/stdc++.h>
using namespace std;
using ll = long long;
 
ll DP[20][12][2];
 
ll count(string &num , int i = 0 , int p = 10 , int t = 1){
	if(i == num.size()) return 1;
 
	if(DP[i][p][t] != -1) return DP[i][p][t];
 
	ll ans = 0;
 
	int limit = t ? num[i] - '0' : 9;
	for(int d = 0 ; d <= limit ; d++) if(p ^ d) ans += count(num , i + 1 , p == 10 && d == 0 ? p : d , t & (d == limit));
 
	return DP[i][p][t] = ans;
}
 
ll F(ll n){
	if(n < 0) return 0;
	memset(DP , -1 , sizeof DP);
	string num = to_string(n);
	return count(num);
}
 
int main(){
	ll a , b ; cin >> a >> b;
	cout << F(b) - F(a - 1);
}
