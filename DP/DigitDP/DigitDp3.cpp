#include<bits/stdc++.h>
using namespace std;

/*
	Problem : Count the Palindrome free numbers in the range [L,R] 
	          Where 0 <= L , R <= 10^18
	          Palindrome free Numbers are the numbers whose consecutive digits do not
	          form palidrome of len greater than 1. 
	          Valid - 123 , 8621 , 56908176 
	          Invalid - 1217890 , 9871142 , 78812320209
*/

long long dp[20][12][12][2][2];

long long F(string &num,int pos = 0,int last1 = 10,int last2 = 10,int tight = 1,int started = 0){
	if(pos == num.size()) return 1;	

	if(dp[pos][last1][last2][tight][started] != -1) return dp[pos][last1][last2][tight][started];

	int limit = tight ? num[pos]-'0' : 9;
	long long ans = 0;
	for(int digit=0;digit<=limit;digit++){
		if(digit == last1 || digit == last2) continue;
		int newTight = tight & (digit == limit);
		int newStarted = started | (digit > 0);
		if(newStarted) ans += F(num,pos+1,digit,last1,newTight,newStarted);
		else ans += F(num,pos+1,last1,last2,newTight,newStarted);
	}
	return dp[pos][last1][last2][tight][started] = ans;
}

long long G(long long A){
	if(A < 0) return 0;
	string num = to_string(A);
	memset(dp,-1,sizeof dp);
      return F(num);
}

void JAY(){
	long long L , R;
	cin >> L >> R;
	cout << (G(R)-G(L-1));
}


int main(){
	int testcases;
	cin >> testcases;
	for(int testcase=1;testcase<=testcases;testcase++){
        JAY();
		if(testcase != testcases) cout << endl;
	}
}
