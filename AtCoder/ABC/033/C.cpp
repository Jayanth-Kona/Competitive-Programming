#include<bits/stdc++.h>
using namespace std;

int main(){
    string s ; cin >> s;
    s += "+";

    int ans = 0;
    int lastPlus = -1 , lastZero = -2;

    for(int i = 0 ; i < (int)s.size() ; i++){
        if(s[i] == '0'){
            lastZero = i;
        }
        else if(s[i] == '+'){
            if(lastZero < lastPlus) ans++;
            lastPlus = i;
        }
    }

    cout << ans << "\n";

    return 0;
}