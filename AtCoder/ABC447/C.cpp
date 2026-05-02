#include<bits/stdc++.h>
using namespace std;

int main(){
    string s , t ; cin >> s >> t;

    int ans = 0;
    int i = 0 , n = s.size();
    int j = 0 , m = t.size();

    while(i < n && j < m){
        if(s[i] == t[j]){
            i++;
            j++;
            continue;
        }
        else if(s[i] == 'A'){
            i++;
            ans++;
        }
        else if(t[j] == 'A'){
            j++;
            ans++;
        }
        else{
            cout << "-1";
            return 0;
        }
    }

    while(i < n){
        if(s[i] == 'A'){
            i++;
            ans++;
        }
        else{
            cout << "-1";
            return 0;
        }
    }

    while(j < m){
        if(t[j] == 'A'){
            j++;
            ans++;
        }
        else{
            cout << "-1";
            return 0;
        }
    }

    cout << ans;

    return 0;
}