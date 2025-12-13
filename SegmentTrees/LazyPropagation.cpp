#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
class lazyPropagation{
public:
  vector<int> tree , lazy;
  lazyPropagation(int n){
    tree.resize(4*n);
    lazy.resize(4*n);
  }

  void build(int node,int low,int high,vector<int> &nums){
    if(low == high) { tree[node] = nums[low] ; return ;}
    int mid = low + (high-low)/2;
    build(node<<1,low,mid,nums);
    build(node<<1|1,mid+1,high,nums);
    tree[node] = tree[node<<1] + tree[node<<1|1];
  }

  int answerQuery(int node,int node_left,int node_right,int query_left,int query_right){

    // Before answering processing the previous updates and propagating it to children
    if(lazy[node] != 0){
      tree[node] += (node_right-node_left+1)*lazy[node];
      if(node_left != node_right){
        lazy[node<<1] += lazy[node];
        lazy[node<<1|1] += lazy[node];
      }
      lazy[node] = 0;
    }

    // no overlap
    if(node_left > query_right || node_right < query_left) return 0;

    // complete overlap
    if(node_left >= query_left && node_right <= query_right) return tree[node];

    // partial overlap
    int mid = node_left + (node_right-node_left)/2;
    return answerQuery(node<<1,node_left,mid,query_left,query_right) + 
           answerQuery(node<<1|1,mid+1,node_right,query_left,query_right);
  }

  void rangeUpdate(int node,int node_left,int node_right,int query_left,int query_right,int value){

    // processing the previous updates and propagating it to children
    if(lazy[node] != 0){
      tree[node] += (node_right-node_left+1)*lazy[node];
      if(node_left != node_right){
        lazy[node<<1] += lazy[node];
        lazy[node<<1|1] += lazy[node];
      }
      lazy[node] = 0;
    }

    // no overlap
    if(node_left > query_right || node_right < query_left) return ;
    
    // complete overlap
    if(node_left >= query_left && node_right <= query_right){
      tree[node] +=  (node_right-node_left+1) * value;
      if(node_left != node_right){
        lazy[node<<1] += value;
        lazy[node<<1|1] += value;
      }
      lazy[node] = 0;
      return;
    }

    // partial overlap
    int mid = node_left + (node_right-node_left)/2;
    rangeUpdate(node<<1,node_left,mid,query_left,query_right,value);
    rangeUpdate(node<<1|1,mid+1,node_right,query_left,query_right,value);    
    tree[node] = tree[node<<1] + tree[node<<1|1];

  }
};

int main() {
  int n;
  cin >> n;
  vector<int> nums(n);
  for(int i=0;i<n;i++) cin >> nums[i];
  lazyPropagation seg(n);
  seg.build(1,0,n-1,nums);
  cout << seg.answerQuery(1,0,n-1,1,1) << endl;
  seg.rangeUpdate(1,0,n-1,1,1,500);
  cout << seg.answerQuery(1,0,n-1,1,1) << endl;
  return 0;
}