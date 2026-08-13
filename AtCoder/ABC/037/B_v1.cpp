#include<bits/stdc++.h>
using namespace std;

/*

Idea: Brute Force

*/

int main(){
    int n , q ; cin >> n >> q;

    vector<int> ans(n);

    for(int i = 1 ; i <= q ; i++){
        int L , R , T;
        cin >> L >> R >> T;
        for(int pos = L ; pos <= R ; pos++) ans[pos - 1] = T;
    }

    for(int num : ans) cout << num << "\n";

    return 0;
}