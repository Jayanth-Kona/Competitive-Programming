#include<bits/stdc++.h>
using namespace std;
using ll = long long;

/*
	Problem : Find Sum of Digits of numbers in the range [L,R] , Where 0 <= L , R <= 10^18
*/

ll dp[20][2][180];

ll F(string &num,int pos = 0,int tight = 1,int sum = 0){
	if(pos == num.size()) return sum;
	
	if(dp[pos][tight][sum] != -1)  return dp[pos][tight][sum];

	int limit = tight ? num[pos]-'0' : 9;
      ll ans = 0;

	for(int digit = 0 ; digit <= limit ; digit++) 
		ans += F(num , pos + 1 , tight & (digit == limit) , sum+digit);
 
      return dp[pos][tight][sum] = ans;
}

ll G(ll A){
	if(A < 0) return 0;
	string num = to_string(A);
	memset(dp,-1,sizeof dp);
	return F(num);
}

void JAY(){
	ll L , R;
	cin >> L >> R;
	cout << (G(R) - G(L-1));
}


int main(){
	int testcases;
	cin >> testcases;
	for(int testcase=1;testcase<=testcases;testcase++){
        JAY();
		if(testcase != testcases) cout << endl;
	}
}