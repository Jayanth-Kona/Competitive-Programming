#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int n , k ; cin >> n >> k;

    vector<int> a(n) , b(n);
    for(int i = 0 ; i < n ; i++) cin >> a[i] >> b[i];

    vector<int> order(n);
    iota(order.begin() , order.end() , 0);
    sort(order.begin() , order.end() , [&](int i , int j){
        return (a[i] - b[i]) > (a[j] - b[j]);
    });

    ll ans = 0;

    for(int i = 0 ; i < n ; i++){
        ans += i < k ? b[order[i]] : a[order[i]];
    }

    cout << ans;

    return 0;
}