#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 2;
const int inf = 1e9;

int n;
vector<int> a;
vector<pair<int,int>> tree;

pair<int,int> merge(pair<int,int> lc,pair<int,int> rc){
    int minId = a[lc.first] < a[rc.first] ? lc.first : rc.first;
    int maxId = a[lc.second] > a[rc.second] ? lc.second : rc.second;
    return make_pair(minId,maxId);
}

void build(int node,int l,int h){
    if(l == h){tree[node] = make_pair(l,l); return;}
    int m = l + h >> 1;
    build(node<<1,l,m);
    build(node<<1|1,m+1,h);
    tree[node] = merge(tree[node<<1],tree[node<<1|1]);
}

pair<int,int> qu(int node,int l,int r,int ql,int qr){
    if(ql > r || qr < l) return {n,n+1};
    if(l >= ql && r <= qr) return tree[node];
    int m = l + r >> 1;
    return merge(qu(node<<1,l,m,ql,qr),qu(node<<1|1,m+1,r,ql,qr));
}


void F(){
    cin >> n;
    a.resize(n+2);
    a[n] = +inf , a[n+1] = -inf;
    for(int i=0;i<n;i++) cin >> a[i];
    tree.resize(n<<2|1);
    build(1,0,n-1);
    int q; cin >> q;
    while(q--){
        int l , r;
        cin >> l >> r;
        pair<int,int> p = qu(1,0,n-1,l-1,r-1);
        if(a[p.first] != a[p.second]){
          cout << p.first+1 << " " << p.second+1;  
        } 
        else cout << "-1 -1";
        cout << endl;
    }
}


int main(){
    int t;
    cin >> t;
    while(t--){
        F();
        cout <<"\n";
    }
    return 0;
}