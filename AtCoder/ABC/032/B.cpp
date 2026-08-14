#include<bits/stdc++.h>
using namespace std;

int main(){
    string s ; cin >> s;
    int k ; cin >> k;

    set<string> passwords;
    for(int i = 0 ; i + k - 1 < (int)s.size() ; i++) passwords.insert(s.substr(i , k));

    cout << passwords.size() << "\n";

    return 0;
}