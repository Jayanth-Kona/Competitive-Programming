#include<bits/stdc++.h>
using namespace std;

class SegmentTree{
private:
    int N;
    vector<int> Tree;

public:
    SegmentTree(int N){
        this->N = N;
        Tree.resize(N << 2 | 2 , 0);
    }

    int query(int node , int low , int high , int ql , int qr){
        if(low >  qr || high <  ql) return 0;
        if(low >= ql && high <= qr) return Tree[node];
        int mid = (low + high) >> 1;
        return max(query(node << 1 , low , mid , ql , qr) , query(node << 1 | 1 , mid + 1 , high , ql , qr));
    }

    int query(int ql , int qr){
        return query(1 , 0 , N - 1 , ql , qr);
    }

    int update(int node , int low , int high , int index , int val){
        if(low == high) return Tree[node] = val;
        int mid = (low + high) >> 1;
        if(index <= mid) update(node << 1 , low , mid , index , val);
        else update(node << 1 | 1 , mid + 1 , high , index , val);
        return Tree[node] = max(Tree[node << 1] , Tree[node << 1 | 1]);
    }

    int update(int index , int val){
        return update(1 , 0 , N - 1 , index , val);
    }

    int maxi(){
        return Tree[1];
    }
};

int main(){
    int n ; cin >> n;

    vector<array<int , 2>> a(n);
    for(auto &[h , w] : a){
        cin >> h >> w;
        w *= -1;
    }
    sort(a.begin() , a.end());

    int N = a.back()[0] + 5;

    vector<int> dp(N);
    SegmentTree seg(N);

    for(int i = 0 ; i < n ; i++){
        int num = -a[i][1];
        dp[num] = 1 + seg.query(0 , num - 1);
        seg.update(num , dp[num]);
    }

    cout << seg.maxi();

    return 0;
}