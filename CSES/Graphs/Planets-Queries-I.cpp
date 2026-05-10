#include<bits/stdc++.h>
using namespace std;
 
int up[200001][33];
 
int main(){
    int n , q ; cin >> n >> q;
    for(int p = 1 , c ; p <= n ; p++){
        cin >> c;
        up[p][0] = c;
    }
 
    int maxK = 1;
    vector<array<int , 2>> queries;
    for(int i = 1 ; i <= q ; i++){
        int u , k ; cin >> u >> k;
        queries.push_back({u , k});
        maxK = max(maxK , k);
    }
 
    int maxLevel = 1 + log2(maxK);
 
    for(int level = 1 ; level <= maxLevel ; level++){
        for(int u = 1 ; u <= n ; u++){
            up[u][level] = up[up[u][level - 1]][level - 1];
        }
    }
 
    for(auto [u , k] : queries){
        for(int bit = 0 ; bit <= maxLevel ; bit++){
            if(k >> bit & 1){
                u = up[u][bit];
            }
        }
        cout << u << "\n";
    }
 
    return 0;
}