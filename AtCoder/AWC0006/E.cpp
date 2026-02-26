#include<bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> Tree;

ll build(int node , int low , int high , vector<int> &a){
    if(low == high) return Tree[node] = a[low];
    int mid = (low + high) >> 1;
    return Tree[node] = build(node << 1 , low , mid , a) + build(node << 1 | 1 , mid + 1 , high , a);
}

ll query(int node , int low , int high , int ql , int qr){
    if(low >  qr || high <  ql) return 0;
    if(low >= ql && high <= qr) return Tree[node];
    int mid = (low + high) >> 1;
    return query(node << 1 , low , mid , ql , qr) + query(node << 1 | 1 , mid + 1 , high , ql , qr);
}

ll update(int node , int low , int high , int index , int val){
    if(low == high) return Tree[node] = val;
    int mid = (low + high) >> 1;
    if(index <= mid) update(node << 1 , low , mid , index , val);
    else update(node << 1 | 1 , mid + 1 , high , index , val);
    return Tree[node] = Tree[node << 1] + Tree[node << 1 | 1];
}

int main(){
    int n , q ; cin >> n >> q;

    vector<int> a(n);
    for(int &num : a) cin >> num;

    Tree.resize(n << 2 | 2 , 0);
    build(1 , 0 , n - 1 , a);
    
    for(int i = 1 ; i <= q ; i++){
        int t , x , y ; cin >> t >> x >> y;
        if(t == 1){
            cout << query(1 , 0 , n - 1 , x - 1 , y - 1) << "\n";
        }
        else{
            update(1 , 0 , n - 1 , x - 1 , y);
        }
    }

    return 0;
}