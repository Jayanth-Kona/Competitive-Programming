#include<bits/stdc++.h>
using namespace std;

int main(){
    string s ; cin >> s;

    int F[26] = {0} , maxi = 0;
    
    for(char ch : s) maxi = max(maxi , ++F[ch - 'a']);
    for(char ch : s) if(F[ch - 'a'] != maxi) cout << ch;

    return 0;
}