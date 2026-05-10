#include<bits/stdc++.h>
using namespace std;
using ll = long long;
 
 
/*
 
mistakes:
1. Took vector<edge> edges(n)  ---> 'n' instead of 'm'
2. we are using bellman ford algorithm and it detects if there is any negative any cycle
    - But this is wrong here, because here we are only intrested maximum score to reach 'n'
    - But if there's a cycle, which gives infinitely +ve score, but it does not lead to 'n',
      then maximum score to reach 'n' might still be finite (we missed this)
 
 
what we can do:
- we know relaxation takes atmost n steps to spread
- note score of 'n' at iteration '1n' = Dn1
- note score of 'n' at iteration '2n' = Dn2
 
if Dn1 < Dn2?
    then it means, we have infinite cycle
    which can relax edges for forever and increase tge score of 'n'
 
 
No, This is also wrong. Assume have a small cycle with 2 nodes and 1 unit weight.
    Now also there's an direct edge from 1 to n, with 10^9 weight,
    Even though the cycle with 2 nodes, can create infinite score for node 'n',
    It won't be detected in just 2 * n cycles, (I will need 10^9 iterations to propagate)
 
 
Correct Approach:
 
In the n-th iteration, ateast one node will be updated (either it could be part of cycle or reachable from cycle)
So, by this observation you can have of these nodes, from nth iteration,
and if these nodes can reach 'n', it means, 'n' can have infinite score
 
To check this, you can build a reverse graph, and do a DFS from 'n'
and if see if you could reach any such node?
 
*/
 
 
struct edge{
    int u;
    int v;
    int w;
};
 
int main(){
    int n , m ; cin >> n >> m;
 
    vector<edge> edges(m);
    for(edge &e : edges) cin >> e.u >> e.v >> e.w;
 
    vector<ll> dist(n + 1 , -1e18);
    dist[1] = 0;
    
    vector<bool> isCycleNode(n + 1 , false);
 
    for(int iter = 1 ; iter <= n ; iter++){
        for(edge &e : edges){
            if(dist[e.u] != -1e18 && dist[e.u] + e.w > dist[e.v]){
                dist[e.v] = dist[e.u] + e.w;
                if(iter == n) isCycleNode[e.v] = true;
            }
        }
    }
 
    vector<vector<int>> graph(n + 1);
    for(edge &e : edges) graph[e.v].push_back(e.u);
 
    vector<bool> vis(n + 1 , false);
 
    function<int(int)> reachCycle = [&](int u){
        if(isCycleNode[u]) return 1;
        vis[u] = 1;
        for(int v : graph[u]){
            if(!vis[v] && reachCycle(v)){
                return 1;
            }
        }
        return 0;
    };
    
    if(reachCycle(n)){
        cout << "-1";
    }
    else{
        cout << dist[n];
    }
 
    return 0;
}