#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int n , q ; cin >> n >> q;

    vector<int> vals(n + 1);
    for(int node = 1 ; node <=n ; node++) cin >> vals[node];

    vector<vector<int>> children(n + 1);
    
    for(int child = 2 ; child <= n ; child++){
        int parent ; cin >> parent;
        children[parent].push_back(child);
    }

    vector<ll> cumsum(n + 1 , 0);

    function<void(int , ll)> DFS = [&](int node , ll sum){
        sum += vals[node];
        cumsum[node] = sum;
        for(int child : children[node]) DFS(child , sum);
        sum -= vals[node];
    };

    DFS(1 , 0);

    for(int i = 1 ; i <= q ; i++){
        int node ; cin >> node;
        cout << cumsum[node] << "\n "[i == q];
    }

    return 0;
}