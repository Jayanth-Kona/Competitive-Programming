#include<bits/stdc++.h>
using namespace std;

int main(){
    string s ; cin >> s;

    int mask = 0 , odd = 0;

    for(char ch : s){
        mask ^= 1 << (ch - 'a');
        odd += mask >> (ch - 'a') & 1 ? +1 : -1;
    }

    if(odd == 0) cout << "Yes";
    else cout << "No";

    return 0;
}