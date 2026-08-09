#include<bits/stdc++.h>
using namespace std;
using ll = long long;

// I have figured out that answer is just number of inversions

vector<int> Tree;

int query(int node , int low , int high , int ql , int qr){
    if(low >  qr || high <  ql) return 0;
    if(low >= ql && high <= qr) return Tree[node];
    int mid = (low + high) >> 1;
    return query(node << 1 , low , mid , ql , qr) + query(node << 1 | 1 , mid + 1 , high , ql , qr);
}

int update(int node , int low , int high , int index , int val){
    if(low == high) return Tree[node] = val;
    int mid = (low + high) >> 1;
    if(index <= mid) update(node << 1 , low , mid , index , val);
    else update(node << 1 | 1 , mid + 1 , high , index , val);
    return Tree[node] = Tree[node << 1] + Tree[node << 1 | 1];
}

int main(){
    int n ; cin >> n;

    int N = n + 5;
    Tree.resize(N << 2 | 2 , 0);

    ll inversions = 0;
    
    for(int i = 1 ; i <= n ; i++){
        int num ; cin >> num;
        inversions += query(1 , 0 , N - 1 , num + 1 , n);
        update(1 , 0 , N - 1 , num , 1);
    }

    cout << inversions;

    return 0;
}


// case1
// 3 2 1 -> 2 adj swap for 3
// 2 1 3 -> 1 adj swap for 1
// 1 2 3 -> good

// 3 -> has 2 inversions
// 2 -> has 1 inversions


// case2
// 3 1 2 -> 2 adj swaps for 3
// 1 2 3 -> good

// 3-> has 2 inversions