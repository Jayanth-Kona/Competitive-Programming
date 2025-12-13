#include<bits/stdc++.h>
using namespace std;

class SegmentTree{
private:
      vector<int> Tree;

public:
      SegmentTree(vector<int> &nums){
            int N = nums.size();
            Tree.resize(N << 2 | 2);
            build(1 , 0 , N - 1 , nums);
      }

      int merge(int a , int b){
            return a + b;
      }

      int reject(){
            return 0;
      }

      int build(int node , int low , int high , vector<int> &nums){
            if(low == high) return Tree[node] = nums[low];
            int mid = (low + high) >> 1;
            return Tree[node] = merge(build(node << 1 , low , mid , nums) , build(node << 1 | 1 , mid + 1 , high , nums));
      }

      int query(int node , int low , int high , int ql , int qr){
            if(low >  qr || high <  ql) return reject();
            if(low >= ql && high <= qr) return Tree[node];
            int mid = (low + high) >> 1;
            return merge(query(node << 1 , low , mid , ql , qr) , query(node << 1 | 1 , mid + 1 , high , ql , qr));
      }

      int update(int node , int low , int high , int index , int val){
            if(low == high) return Tree[node] = val;
            int mid = (low + high) >> 1;
            if(index <= mid) update(node << 1 , low , mid , index , val);
            else update(node << 1 | 1 , mid + 1 , high , index , val);
            return Tree[node] = merge(Tree[node << 1] , Tree[node << 1 | 1]);
      }

};

int main(){
      
      return 0;
}