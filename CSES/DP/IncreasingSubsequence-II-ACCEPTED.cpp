#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

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
        return (Query(node << 1 , low , mid , qL , qR) + Query(node << 1 | 1 , mid + 1 , high , qL , qR)) % mod;
    }

    int Update(int node , int low , int high , int index , int val){
        if(low == high) return Tree[node] = val;
        int mid = (low + high) >> 1;
        if(index <= mid) Update(node << 1 , low , mid , index , val);
        else Update(node << 1 | 1 , mid + 1 , high , index , val);
        return Tree[node] = (Tree[node << 1] + Tree[node << 1 | 1]) % mod;
    }
};   


int OptimalApproach(int n , vector<int> &nums){
    int total_lis = 0;
    vector<int> endingAt(n + 1);

    SegmentTree ST(n);
 
    for(int num : nums){
        int endingAt_j = ST.Query(1 , 0 , n , 0 , num - 1);
        total_lis = (total_lis + endingAt_j + 1) % mod;

        endingAt[num] = (endingAt[num] + endingAt_j + 1) % mod;
        ST.Update(1 , 0 , n , num , endingAt[num]);
    }
 
    return total_lis;
}

void compress(vector<int> &nums){
    map<int , int> map;
    for(int &num : nums) map[num] = 1;

    int newID = 1;
    for(auto &[num , ID] : map) ID = newID++;

    for(int &num : nums) num = map[num];
}

int main(){
    int n ; cin >> n;

    vector<int> nums(n);
    for(int &num : nums) cin >> num;

    compress(nums);
    
    cout << OptimalApproach(n , nums);
    
    return 0;
}