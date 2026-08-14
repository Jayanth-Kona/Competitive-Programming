#include<bits/stdc++.h>
using namespace std;

int main(){
    string s ; cin >> s;

    int n = s.size();
    array<int , 2> ans = {-1 , -1};

    for(int i = 0 ; i < n ; i++){
        if(i + 1 < n && s[i] == s[i + 1]){
            ans[0] = i + 1;
            ans[1] = i + 2;
            break;
        }
        if(i + 2 < n && s[i] == s[i + 2]){
            ans[0] = i + 1;
            ans[1] = i + 3;
            break;
        }
    }

    cout << ans[0] << " " << ans[1];

    return 0;
}