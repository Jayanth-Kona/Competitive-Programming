#include<bits/stdc++.h>
using namespace std;

class DisjointSet{
private:
    vector<int> p , s;

public:
    DisjointSet(int n){
        for(int i = 0 ; i <= n + 1 ; i++){
            p.push_back(i);
            s.push_back(1);
        }
    }

    int parent(int u){
        if(p[u] != u) p[u] = parent(p[u]);
        return p[u];
    }

    int isConnected(int u , int v){
        return parent(u) == parent(v);
    }

    void connect(int u , int v){
        u = parent(u);
        v = parent(v);
        if(u != v){
            if(s[u] < s[v]) swap(u , v);
            p[v] = u;
            s[u] += s[v];
        }
    }

};

int main(){
    int mod = 998244353;

    int n , m ; cin >> n >> m;

    vector<int> pow2(m + 1);
    pow2[0] = 1;

    vector<array<int , 3>> edges;

    for(int i = 1 ; i <= m ; i++){
        int u , v ; cin >> u >> v;
        edges.push_back({u , v , i});
        pow2[i] = 2LL * pow2[i - 1] % mod;
    }
    reverse(edges.begin() , edges.end());

    DisjointSet dsu(n + 1);
    int remove = 0 , comp = n;

    for(array<int , 3> &e : edges){
        auto [u , v , i] = e;
        if(dsu.isConnected(u , v) == false){
            if(comp > 2){
                comp -= 1;
                dsu.connect(u , v);
            }
            else{
                remove = (remove + pow2[i]) % mod;
            }
        }
    }

    cout << remove;

    return 0;
}