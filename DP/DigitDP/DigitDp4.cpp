

/*
	Problem : count the number of integers in the range [A, B] which are divisible by K and
              the sum of its digits is also divisible by K.
               1 ≤ A ≤ B < 2^31 and 0 < K < 10000

    DP Transition States : DP[digitPosition][remainder][tight]

    1. 0 ≤ Digit Position ≤ 9 :
	   1 ≤ A ≤ B < 2^31 < (9*10^9)
	   And Digits required to represent 9*10^9 = 9

	2. 0 ≤ digitSum ≤ 80 :
	   1 ≤ sum Of Digits ≤ 81

	   since 0 < K < 10000 : 
		   if(k > 81) :
			    answer = 0 
			    because k is greater than maximumSumofDigits 
			    and 
			    irrespective of k => (remainder(sumOfDigits,k) equals sumOfDigits) which is never 0
			    Hence maximum remainder we can have is 80.(when k == 81 && sumOfDigits == 80)

    3. 0 ≤ tight ≤ 1

    4. 0 ≤ isStarted ≤ 1 : Can be optimised used DigitSum
*/




#include<bits/stdc++.h>
using namespace std;

int mod = 1e9 + 7;
int dp[10][82][100][2];

int F(string &num,int k,int pos = 0,int digitSum = 0,int s=0,int tight = 1){
  
    if(pos == num.size()) return digitSum && (digitSum%k == 0) && s == 0;

    if(dp[pos][digitSum][s][tight] != -1) return dp[pos][digitSum][s][tight];

    long long res = 0;
    int limit = tight ? num[pos]-'0' : 9;

    for(int digit=0;digit<=limit;digit++)
        res += F(num,k,pos+1,digitSum+digit,(s*10+digit)%k,tight&(digit==limit))%mod;

    return dp[pos][digitSum][s][tight] = res ;
}

long long G(string num,int k){
	memset(dp,-1,sizeof dp);
	return F(num,k);
}


int codingChallenge(string input1,string input2,int input3){
	if(input3 == 0) return 0;
	if(input3 == 1) return stoi(input2)-stoi(input1)+1;
	int sum = 0;
	for(char d : input1) sum += d-'0';
	return ((G(input2,input3) - G(input1,input3) + (sum%input3==0))%mod+mod)%mod;
}



int main(){
	string s1 , s2;
	int k;
	cin >> s1 >> s2 >> k;
	cout << codingChallenge(s1,s2,k);
}