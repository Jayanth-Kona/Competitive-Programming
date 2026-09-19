#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll n , m , k;
    cin >> n >> m >> k;

    ll x , y ; cin >> x >> y;

    vector<ll> a(n) , b(m);
    for(ll &num : a) cin >> num;
    for(ll &num : b) cin >> num;

    sort(a.begin() , a.end());
    sort(b.begin() , b.end());

    for(int i = 1 ; i < n ; i++) a[i] += a[i - 1];

    int ans = upper_bound(a.begin() , a.end() , x + y * k) - a.begin();

    ll change = 0;
    for(int i = 0 ; i < m ; i++){
        ll k_reqd = (b[i] + k - 1) / k;

        if(y < k_reqd) break;
        
        y -= k_reqd;
        change += k_reqd * k - b[i];

        int from_b = i + 1;
        int from_a = upper_bound(a.begin() , a.end() , x + y * k + change) - a.begin();

        ans = max(ans , from_a + from_b);
    }

    cout << ans;

    return 0;
}