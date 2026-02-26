#include<bits/stdc++.h>
using namespace std;
using ll = long long;

class SegmentTree{
private:
      vector<ll> Tree , Lazy;

public:
    SegmentTree(vector<int> &nums){
        int N = nums.size();
        Tree.resize(N << 2 | 2 , 0);
        Lazy.resize(N << 2 | 2 , 0);
        build(1 , 0 , N - 1 , nums);
    }

    ll merge(ll a , ll b){
        return a + b;
    }

    ll reject(){
        return 0;
    }

    ll build(int node , int low , int high , vector<int> &nums){
        if(low == high) return Tree[node] = nums[low];
        int mid = (low + high) >> 1;
        return Tree[node] = merge(build(node << 1 , low , mid , nums) , build(node << 1 | 1 , mid + 1 , high , nums));
    }

    ll query(int node , int low , int high , int ql , int qr){
        if(Lazy[node] != 0){
            Tree[node] += (high - low + 1) * 1LL * Lazy[node];
            if(low != high){
                Lazy[node << 1] += Lazy[node];
                Lazy[node << 1 | 1] += Lazy[node];
            }
            Lazy[node] = 0;
        }

        if(low >  qr || high <  ql) return reject();
        if(low >= ql && high <= qr) return Tree[node];

        int mid = (low + high) >> 1;
        return merge(query(node << 1 , low , mid , ql , qr) , query(node << 1 | 1 , mid + 1 , high , ql , qr));
    }

    ll update(int node , int low , int high , int ql , int qr , int val){
        if(Lazy[node] != 0){
            Tree[node] += (high - low + 1) * 1LL * Lazy[node];
            if(low != high){
                Lazy[node << 1] += Lazy[node];
                Lazy[node << 1 | 1] += Lazy[node];
            }
            Lazy[node] = 0;
        }

        if(low >  qr || high <  ql) return Tree[node];

        if(low >= ql && high <= qr){
            Tree[node] += (high - low + 1) * 1LL * val;
            if(low != high){
                Lazy[node << 1] += val;
                Lazy[node << 1 | 1] += val;
            }
            return Tree[node];
        }

        int mid = (low + high) >> 1;
        return Tree[node] = merge(update(node << 1 , low , mid , ql , qr , val) , update(node << 1 | 1 , mid + 1 , high , ql , qr , val));
    }

};


int main(){
    int n , q ; cin >> n >> q;

    vector<int> a(n);
    for(int &num : a) cin >> num;

    SegmentTree ST(a);

    for(int i = 1 ; i <= q ; i++){
        int t ; cin >> t;

        if(t == 1){
            int l , r , v ; cin >> l >> r >> v;
            ST.update(1 , 0 , n - 1 , l - 1 , r - 1 ,  v);
        }
        else{
            int l , r ; cin >> l >> r;
            ll sum = ST.query(1 , 0 , n - 1 , l - 1 , r - 1);
            cout << sum << "\n "[i == q];
        }
    }

    return 0;
}