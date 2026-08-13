#include<bits/stdc++.h>
using namespace std;
using ll = long long;

/*

Idea: use dsu to find next unmarked position

Example:
imagine 2 have queries [a , b , c] , [b , d]

first mark a
set parent[a] = b

then mark b
set parent[b] = c

then mark c
set parent[c] = d

now if you call [b , d]
parent[b] -> c -> parent[c] = d --> d (path compression handles this)

so mark d
set parent[d] = e

*/

class DisjointSet{
public:
    vector<int> parent;
    
    DisjointSet(int n){
        parent.resize(n + 2);
        iota(parent.begin() , parent.end() , 0);
    }
    
    int find(int x){
        if(parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }
    
    void mark(int x){
        parent[x] = find(x + 1);
    }
};

int main(){
    int n , q ; cin >> n >> q;

    vector<array<int , 3>> queries(q);
    for(auto &[L , R , T] : queries) cin >> L >> R >> T;

    DisjointSet dsu(n);
    vector<int> ans(n);

    for(int i = q - 1 ; i >= 0 ; i--){
        auto [L , R , T] = queries[i];
        for(int pos = dsu.find(L) ; pos <= R ; pos = dsu.find(pos)){
            ans[pos - 1] = T;
            dsu.mark(pos);
        }
    }

    for(int num : ans) cout << num << "\n";

    return 0;
}