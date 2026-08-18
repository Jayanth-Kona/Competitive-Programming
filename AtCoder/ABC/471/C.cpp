#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int n ; cin >> n;

    vector<int> a(n);
    for(int &num : a) cin >> num;

    sort(a.begin() , a.end());

    int r = upper_bound(a.begin() , a.end() , 0) - a.begin(); // a[r] > 0
    int l = r - 1; // a[l] <= 0

    ll ans = 0 , prev = 0;

    while(l >= 0 && r < n){
        ll dL = abs(prev - a[l]);
        ll dR = abs(prev - a[r]);

        if(dL == dR || dL < dR){
            ans += dL;
            prev = a[l];
            l -= 1;
        }
        else{
            ans += dR;
            prev = a[r];
            r += 1;
        }
    }

    while(l >= 0){
        ll dL = abs(prev - a[l]);
        ans += dL;
        prev = a[l];
        l -= 1;
    }

    while(r < n){
        ll dR = abs(prev - a[r]);
        ans += dR;
        prev = a[r];
        r += 1;
    }

    cout << ans;

    return 0;
}