#include<bits/stdc++.h>
using namespace std;
using ll = long long;

class Node{
public:
      ll sum;
      ll xorr;
      ll maxi;
      ll mini;

      Node(){
            sum = 0;
            xorr = 0;
            maxi = -1e18;
            mini = +1e18;
      }

      Node(ll num){
            sum = num;
            xorr = num;
            maxi = num;
            mini = num;
      }

      friend Node operator+(const Node &u , const Node &v){
            Node uv;
            uv.sum = u.sum + v.sum;
            uv.xorr = u.xorr ^ v.xorr;
            uv.maxi = max(u.maxi , v.maxi);
            uv.mini = min(u.mini , v.mini);
            return uv;
      }

};

class SegmentTree{
private:
      vector<Node> Tree;

public:
      SegmentTree(int N , vector<int> &A){
            Tree.resize(N << 2 | 2);
            Build(1 , 0 , N - 1 , A);
      }

      Node Build(int node , int low , int high , vector<int> &A){
            if(low == high) return Tree[node] = Node(A[low]);
            int mid = (low + high) >> 1;
            return Tree[node] = Build(node << 1 , low , mid , A) + Build(node << 1 | 1 , mid + 1 , high , A);
      }

      Node Query(int node , int low , int high , int qL , int qR){
            if(high < qL || low > qR) return Node();
            if(qL <= low && high <= qR) return Tree[node];
            int mid = (low + high) >> 1;
            return Query(node << 1 , low , mid , qL , qR) + Query(node << 1 | 1 , mid + 1 , high , qL , qR);
      }
};


int main(){
      cout << "let's go !!" << endl;
}