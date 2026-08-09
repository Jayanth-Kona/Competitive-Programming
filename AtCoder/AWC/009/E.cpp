#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int maxi;
    int mini;

    Node(){
        maxi = -2e9;
        mini = +2e9;
    }

    Node(int num){
        maxi = num;
        mini = num;
    }

    friend Node operator+(const Node &u , const Node &v){
        Node uv;
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
    int n , q ; cin >> n >> q;

    vector<int> a(n);
    for(int &num : a) cin >> num;

    SegmentTree ST(n , a);

    for(int i = 1 ; i <= q ; i++){
        int L , R ; cin >> L >> R;
        Node LR = ST.Query(1 , 0 , n - 1 , L - 1 , R - 1);
        cout << LR.maxi - LR.mini << "\n "[i == q];
    }

    return 0;
}