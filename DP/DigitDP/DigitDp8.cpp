#include<bits/stdc++.h>
using namespace std;


/*
    Problem : Count the numbers in the range [L,R] , Where no two adjacent Digits are same 
*/

long long dp[20][12][2][2];

long long F(string &num,int pos = 0,int last = 10,int tight = 1,int isStarted = 0,string temp=""){
    if(pos == num.size()){
        cout << temp << endl;
      return 1;  
    } 
    if(dp[pos][last][tight][isStarted] != -1) return dp[pos][last][tight][isStarted];
    long long cnt = 0;
    int limit = tight ? num[pos]-'0' : 9;
    for(int digit=0;digit<=limit;digit++){
        if(last == digit) continue;
        int newIsStarted = isStarted | (digit > 0);
        int newLast = (newIsStarted ? digit : last);
        cnt += F(num,pos+1,newLast,tight&(digit==limit),newIsStarted,temp+to_string(digit));
    }
    return dp[pos][last][tight][isStarted] = cnt;
}

long long G(long long X){
    string num = to_string(X);
    memset(dp,-1,sizeof dp);
    return F(num);
}

void JAY(){
    long long a , b;
    cin >> a >> b;
    long long R = G(b);
    long long L = G(a-1);
    cout << (R-L);
}

int main(){
    int testcases;
    cin >> testcases;
    for(int testcase=1;testcase<=testcases;testcase++){
        JAY();
        if(testcase != testcases) cout << endl;
    }
}