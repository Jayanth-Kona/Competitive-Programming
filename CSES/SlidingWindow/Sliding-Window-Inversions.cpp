#include<bits/stdc++.h>
using namespace std;

class SegmentTree{
private:
      vector<int> Tree;

public:
    SegmentTree(int n){
        Tree.resize(n << 2 | 2 , 0);
    }

    int Query(int node , int low , int high , int qL , int qR){
        if(low >  qR || high <  qL) return 0;
        if(low >= qL && high <= qR) return Tree[node];
        int mid = (low + high) >> 1;
        return Query(node << 1 , low , mid , qL , qR) + Query(node << 1 | 1 , mid + 1 , high , qL , qR);
    }

    int Update(int node , int low , int high , int index , int val){
        if(low == high) return Tree[node] += val;
        int mid = (low + high) >> 1;
        if(index <= mid) Update(node << 1 , low , mid , index , val);
        else Update(node << 1 | 1 , mid + 1 , high , index , val);
        return Tree[node] = Tree[node << 1] + Tree[node << 1 | 1];
    }
};   


void compress(vector<int> &nums){
    map<int , int> map;
    for(int &num : nums) map[num] = 1;

    int newID = 1;
    for(auto &[num , ID] : map) ID = newID++;

    for(int &num : nums) num = map[num];
}

int main(){
    int n , k ; cin >> n >> k;

    vector<int> x(n);
    for(int &xi : x) cin >> xi;

    compress(x);

    int maxN = n + 5;
    SegmentTree ST(maxN);

    long long inversions = 0;
    
    for(int i = 0 ; i < n ; i++){
        inversions += ST.Query(1 , 0 , maxN - 1 , x[i] + 1 , maxN - 1);
        ST.Update(1 , 0 , maxN - 1 , x[i] , +1);

        if(i >= k - 1){
            cout << inversions << " ";

            inversions -= ST.Query(1 , 0 , maxN - 1 , 0 , x[i - k + 1] - 1);
            ST.Update(1 , 0 , maxN - 1 , x[i - k + 1] , -1);
        }
    }

    return 0;
}