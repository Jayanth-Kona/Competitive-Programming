#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll n , k , m ; cin >> n >> k >> m;

    vector<ll> p(n + 1);
    p[0] = 0;

    for(int i = 1 ; i <= n ; i++){
        cin >> p[i];
        p[i] += p[i - 1];
    }

    ll pairs = 0;

    for(int l = 1 , r = k ; r <= n ; r++){
        while(r - l + 1 >= k && p[r] - p[l - 1] >= m) l++;
        pairs += l - 1;            
    }

    cout << pairs;

    return 0;
}