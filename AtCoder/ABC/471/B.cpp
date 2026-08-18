#include<bits/stdc++.h>
using namespace std;

int main(){
    int n ; cin >> n;

    int ans = 0;
    map<string , int> map;

    for(int i = 1 ; i <= n ; i++){
        string s ; cin >> s;
        for(char &ch : s) ch = tolower(ch);
        ans = max(ans , ++map[s]);
    }

    cout << ans;

    return 0;
}