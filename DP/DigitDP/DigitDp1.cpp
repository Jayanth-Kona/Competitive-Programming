#include<bits/stdc++.h>
using namespace std;


/*
	Problem : Count the occurences of Digit "D" for the numbers in the range [L,R] 
	          Where 0 <= L , R <= 10^18
*/


long long dp[20][2][2][20];

long long F(string &num,int D,int pos = 0,int started = 0,int tight = 1,int freq = 0){
    if(pos == num.size()) return freq;

    if(dp[pos][started][tight][freq] != -1) return dp[pos][started][tight][freq];

    int limit = tight ? num[pos]-'0' : 9;
    long long ans = 0;
    for(int digit=0;digit<=limit;digit++){
    	int newStarted = started | (digit > 0);
    	int newTight = tight & (digit == limit);
    	int canCount = newStarted & (digit == D);
    	ans += F(num,D,pos+1,newStarted,newTight,freq+canCount);

    }
    return dp[pos][started][tight][freq] = ans;
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
	cin >> L >> R >> D;
	cout << (G(R,D)-G(L-1,D));
}



int main(){
	int testcases;
	cin >> testcases;
	for(int testcase=1;testcase<=testcases;testcase++){
        JAY();
		if(testcase != testcases) cout << endl;
	}
}