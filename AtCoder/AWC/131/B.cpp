#include<bits/stdc++.h>
using namespace std;

int main(){
    int n , q ; cin >> n >> q;

    map<string , vector<int>> occurences;
    
    for(int i = 1 ; i <= n ; i++){
        string s ; cin >> s;
        occurences[s].push_back(i);
    }

    for(int i = 1 ; i <= q ; i++){
        int l , r ; cin >> l >> r;
        string t ; cin >> t;

        if(occurences.count(t)){
            vector<int> &ids = occurences[t];
            int L = lower_bound(ids.begin() , ids.end() , l) - ids.begin();
            int R = upper_bound(ids.begin() , ids.end() , r) - ids.begin() - 1;
            cout << R - L + 1 << "\n";
        }
        else{
            cout << "0\n";
        }
    }

    return 0;
}