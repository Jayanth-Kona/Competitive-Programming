#include<bits/stdc++.h>
using namespace std;

/*
	Problem - Count numbers in the range [L,R] whose sum of digits is "D", Where 0 <= L , R <= 10^18
*/

int dp[20][2][180];

long long F(string &num,int digitSum,int pos=0,int tight=1){
	if(digitSum < 0) return 0;
	if(pos == num.size()) return digitSum == 0;
	if(dp[pos][tight][digitSum] != -1) return dp[pos][tight][digitSum];
	long long ans = 0;
	int limit = tight ? num[pos]-'0' : 9;
	for(int digit=0;digit<=limit;digit++){
       ans += F(num,digitSum-digit,pos+1,tight&(digit==limit));
	}
	return dp[pos][tight][digitSum] = ans;
}


long long G(long long A,int D){
	if(A < 0) return 0;
	string num = to_string(A);
	memset(dp,-1,sizeof dp);
	return F(num,D);
}


void JAY(){
	long long L , R;
	int D;
	cin >> L >> R;
	cin >> D;
	cout << (G(R,D) - G(L-1,D));
}

int main(){
	int testcases;
	cin >> testcases;
	for(int testcase=1;testcase<=testcases;testcase++){
        JAY();
		if(testcase != testcases) cout << endl;
	}
}