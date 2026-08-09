#include<bits/stdc++.h>
using namespace std;

vector<int> Tree;

int build(int node , int low , int high , vector<int> &nums){
    if(low == high) return Tree[node] = nums[low];
    int mid = (low + high) >> 1;
    return Tree[node] = max(build(node << 1 , low , mid , nums) , build(node << 1 | 1 , mid + 1 , high , nums));
}

int query(int node , int low , int high , int ql , int qr){
    if(low >  qr || high <  ql) return 0;
    if(low >= ql && high <= qr) return Tree[node];
    int mid = (low + high) >> 1;
    return max(query(node << 1 , low , mid , ql , qr) , query(node << 1 | 1 , mid + 1 , high , ql , qr));
}

int main(){
    int n  , q ; cin >> n >> q;

    vector<int> nums(n);
    for(int &num : nums) cin >> num;
    
    Tree.resize(n << 2 | 2);
    build(1 , 0 , n - 1 , nums);

    for(int i = 1 ; i <= q ; i++){
        int l , r ; cin >> l >> r;
        cout << query(1 , 0 , n - 1 , l - 1 , r - 1) << "\n";
    }

    return 0;
}