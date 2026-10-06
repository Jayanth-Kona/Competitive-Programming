#include<bits/stdc++.h>
using namespace std;

int main(){
    int q ; cin >> q;

    string s , t ; cin >> s >> t;

    int n = s.size();
    int m = t.size();

    vector<int> startpoints;
    for(int i = 0 ; i + m - 1 < n ; i++){
        if(s.substr(i , m) == t){
            startpoints.push_back(i + 1);
        }
    }

    for(int i = 1 ; i <= q ; i++){
        int l , r ; cin >> l >> r;
        
        if(startpoints.empty() || startpoints.back() < l){
            cout << "No\n";
        }
        else{
            int j = *lower_bound(startpoints.begin() , startpoints.end() , l);
            if(l <= j && j + m - 1 <= r){
                cout << "Yes\n";
            }
            else{
                cout << "No\n";
            }
        }
    }

    return 0;
}