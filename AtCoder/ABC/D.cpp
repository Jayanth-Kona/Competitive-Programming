#include<bits/stdc++.h>
using namespace std;

struct edge{
    int u;
    int v;
    int year;
};

struct query{
    int u;
    int id;
    int year;
};

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

    void join(int u , int v){
        u = parent(u);
        v = parent(v);
        if(u != v){
            if(s[u] < s[v]) swap(u , v);
            p[v] = u;
            s[u] += s[v];
        }
    }

    int groupsize(int u){
        return s[parent(u)];
    }

};

int main(){
    int n , m ; cin >> n >> m;

    vector<edge> edges(m);
    for(int i = 0 ; i < m ; i++) cin >> edges[i].u >> edges[i].v >> edges[i].year;

    sort(edges.begin() , edges.end() , [&](edge &e1 , edge &e2){
        return e1.year > e2.year;
    });

    int q ; cin >> q;

    vector<query> queries(q);
    for(int i = 0 ; i < q ; i++){
        cin >> queries[i].u >> queries[i].year;
        queries[i].id = i;
    }

    sort(queries.begin() , queries.end() , [&](query &q1 , query &q2){
        return q1.year > q2.year;
    });
    
    DisjointSet dsu(n);
    vector<int> ans(q);

    for(int i = 0 , j = 0 ; i < q ; i++){
        while(j < m && edges[j].year > queries[i].year){
            dsu.join(edges[j].u , edges[j].v);
            j++;
        }
        ans[queries[i].id] = dsu.groupsize(queries[i].u);
    }

    for(int num :  ans) cout << num << "\n";

    return 0;
}