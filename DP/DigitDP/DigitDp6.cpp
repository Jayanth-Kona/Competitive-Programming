#include<bits/stdc++.h>
using namespace std;


/*
    Balanced numbers : A positive integer is considered a balanced number if:

	Every even digit appears an odd number of times in its decimal representation
	Every odd digit appears an even number of times in its decimal representation
	For example, 77, 211, 6222 and 112334445555677 are balanced numbers while 351, 21, and 662 are not.

    Given an interval [A, B], your task is to find the amount of balanced numbers in [A, B]
    where 1 <= A <= B <= 10^19 
*/

long long dp[20][20][20][2];

long long F(string &num,int pos = 0,int e = 0,int o = 0,int tight = 1){
	if(num.size() == pos) return (e|o) && (!e|(e&1)) && (!o|(o&1^1));

	long long &res = dp[pos][e][o][tight];
	if(res != -1) return res;

	res = 0;
	int limit = tight ? num[pos]-'0' : 9;

	for(int d=0;d<=limit;d++)
		res += F(num,pos+1,e+(d&1^1 && (d|e|o)),o+(d&1),tight&(d==limit));

	return res;
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