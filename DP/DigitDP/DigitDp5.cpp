#include<bits/stdc++.h>
using namespace std;


/* count numbers without repeating digits in the range L R */

long long dp[18][1<<10][2][2];

long long F(string &num,int pos=0,int mask=0,int tight=1,int s=0){
	if(pos == num.size()) return s;	

	long long &cnt = dp[pos][mask][tight][s];
	if(cnt != -1) return cnt;

	cnt = 0;
	int limit = tight ? num[pos]-'0' : 9;

	for(int d=0;d<=limit;d++)
		if((mask>>d&1^1) || (d == 0 && s == 0))
			cnt += F(num,pos+1,mask|(s|d>0)<<d,tight&(d==limit),s|(d>0));

	return cnt;

}

int JAY(){
	int L , R;
	cin >> L >> R;

	memset(dp,-1,sizeof dp);
	string A = to_string(L-1);
	long long cnt1 = F(A);

	memset(dp,-1,sizeof dp);
	string B = to_string(R);
	long long cnt2 = F(B);

	return cnt2-cnt1;
	
}

int main(){
	int testcases;
	cin >> testcases;
	for(int testcase=1;testcase<=testcases;testcase++){
        cout << JAY();
		if(testcase != testcases) cout << endl;
	}
}