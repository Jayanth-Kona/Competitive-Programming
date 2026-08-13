#include<bits/stdc++.h>
using namespace std;
using ll = long long;

/*

Idea: Use set to only get and mark unmarked postions

*/

int main(){
    int n , q ; cin >> n >> q;

    vector<array<int , 3>> queries(q);
    for(auto &[L , R , T] : queries) cin >> L >> R >> T;

    set<int> unmarked;
    for(int pos = 1 ; pos <= n ; pos++) unmarked.insert(pos);

    vector<int> ans(n);

    for(int i = q - 1 ; i >= 0 ; i--){
        auto [L , R , T] = queries[i];
        for(auto it = unmarked.lower_bound(L) ; it != unmarked.end() && *it <= R ; it = unmarked.erase(it)){
            ans[*it - 1] = T;
        }
    }

    for(int num : ans) cout << num << "\n";

    return 0;
}