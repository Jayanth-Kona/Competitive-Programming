#include<bits/stdc++.h>
using namespace std;


/*

A number is said to be a ‘Palindromic Prime’ if it satisfies the following conditions:

All the digits in a number should be prime (‘2’, ‘3’, ‘5’ or ‘7’).
Rearranging its digits gives a palindrome.

For example: “23235” is a Palindromic Prime Number because we can rearrange its digits to turn it into “23532” which is a palindrome.
You are given two integers ‘L’ and ‘R’. You have to count the number of Palindromic Prime Numbers from ‘L’ to ‘R’.



Your task is to count the number of Palindromic Prime Numbers from ‘L’ to ‘R’ and return it.



Example: ‘L’ = 200 ‘R’ = 300

The Palindromic Prime Numbers from ‘200’ to ‘300’ are: (‘222’, ‘223’, ‘225’, ‘227’, ‘232’, ‘233’, ‘252’, ‘255’, ‘272’, and ‘277’).

The count of these numbers is ‘10’.


Solution : dp[pos][tight][started][xor_mask]
	     mask represents the Freq of each prime number i.e either as (even/odd)
	     for a palindromic number , we can have atmost one odd freq number
	     so , at pos == num.size() , mask is said to be valid if setBits(mask) <= 1

*/

int use[5] = {0 , 2 , 3 , 5 , 7};

int dp[10][2][2][16]; 


int F(string &num , int pos = 0 , int t = 1 , int s = 0 , int mask = 0){
   if(pos == num.size()) return s && __builtin_popcount(mask) <= 1;

   int &ans = dp[pos][t][s][mask];
   if(ans != -1) return ans;

   ans = 0;
   int limit = t ? num[pos]-'0' : 9;

   for(int i = s ; i < 5 && use[i] <= limit ; i++){
      ans += F(num , pos + 1 , t & (use[i] == limit) , s | (i > 0) , mask ^ (i > 0) << i);
   }

   return ans;
}


int palindromicPrimeNumber(int l , int r){
   string lString = to_string(l);
   memset(dp , -1 , sizeof dp);
   l = F(lString);

   string rString = to_string(r);
   memset(dp , -1 , sizeof dp);
   r = F(rString);

   return r - l;
}

int main(){
	int t ; cin >> t;
	while(t--){
		int l , r ; cin >> l >> r;
		cout << palindromicPrimeNumber(l , r) << endl;
	}
	return 0;
}