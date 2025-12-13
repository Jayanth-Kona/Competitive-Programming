#include<bits/stdc++.h>
using namespace std;

struct DataNode{
    int m1 , m2 , f1 , f2;
    DataNode(){}
    DataNode(int m11,int m22,int f11,int f22){
        m1 = m11 , m2 = m22 , f1 = f11 , f2 = f22;
    }
};

class SegmentTree{
private:
    vector<DataNode> tree;
public:
    SegmentTree(int n){
       tree.resize(4*n);
    }
    DataNode merge(DataNode d1,DataNode d2){
        int m1 = 0 , m2 = 0 , f1 = 0 , f2 = 0;
        for(DataNode d : {d1,d2}){
            if(d.m1 == m1) f1 += d.f1;
            else if(d.m1 > m1) m2 = m1 , f2 = f1 , m1 = d.m1 , f1 = d.f1;
            else if(d.m1 == m2) f2 += d.f1;
            else if(d.m1 > m2) m2 = d.m1 , f2 = d.f1;

            if(d.m2 == m1) f1 += d.f2;
            else if(d.m2 > m1) m2 = m1 , f2 = f1 , m1 = d.m2 , f1 = d.f2;
            else if(d.m2 == m2) f2 += d.f2;
            else if(d.m2 > m2) m2 = d.m2 , f2 = d.f2;
        }
        return DataNode(m1,m2,f1,f2);
    }
    void build(int node,int low,int high,vector<int> &nums){
        if(low == high) {tree[node] = DataNode(nums[low],0,1,0); return;}
        int mid = low + (high-low)/2;
        build(node<<1,low,mid,nums);
        build(node<<1|1,mid+1,high,nums);
        tree[node] = merge(tree[node<<1],tree[node<<1|1]);
    }

    void update(int node,int low,int high,int index,int value){
      if(low == high){
        tree[node] = DataNode(value,0,1,0);
        return ;
      }
      int mid = low + (high-low)/2;
      if(index <= mid) update(node<<1,low,mid,index,value);
      else update(node<<1|1,mid+1,high,index,value);
      tree[node] = merge(tree[node<<1],tree[node<<1|1]);
    }

    DataNode query(int node,int low,int high,int qlow,int qhigh){
       if(high < qlow || low > qhigh) return DataNode(0,0,0,0);
       if(low >= qlow && high <= qhigh) return tree[node];
       int mid = low + (high-low)/2;
       return merge(query(node<<1,low,mid,qlow,qhigh),query(node<<1|1,mid+1,high,qlow,qhigh));
    }
};

int main(){
    int n , q;
    cin >> n >> q;
    vector<int> nums(n);
    for(int &num : nums) cin >> num;
    SegmentTree seg(n);
    seg.build(1,0,n-1,nums);
    while(q--){
        int t , a , b;
        cin >> t >> a >> b;
        if(t == 1) seg.update(1,0,n-1,a-1,b);
        else{
            int cnt = seg.query(1,0,n-1,a-1,b-1).f2;
            cout << cnt << endl;
        }
    }
  return 0;
}


