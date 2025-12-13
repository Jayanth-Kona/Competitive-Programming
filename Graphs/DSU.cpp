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

    void join(int u , int v){
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
    return 0;
}