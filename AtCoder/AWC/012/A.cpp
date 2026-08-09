#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int n , t; cin >> n >> t;

    vector<int> h(n) , c(n);
    for(int &num : h) cin >> num;
    for(int &num : c) cin >> num;
        
    ll cost = 0;

    for(int i = 0 ; i < n ; i++) if(h[i] <= t) cost += c[i];

    cout << cost;

    return 0;
}