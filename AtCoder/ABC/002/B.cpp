#include<bits/stdc++.h>
using namespace std;

int main(){
    string s ; cin >> s;

    for(char ch : s){
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') continue;
        else cout << ch;
    }

    cout << "\n";
    
    return 0;
}