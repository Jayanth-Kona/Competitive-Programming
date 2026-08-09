#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll n , s ; cin >> n >> s;

    vector<ll> L , R;
    for(int i = 0 ; i < n ; i++){
        ll num ; cin >> num;
        if(i < n / 2) L.push_back(num);
        else R.push_back(num);
    }

    ll ans = 0;
    map<ll , ll> sums;

    int nL = L.size();
    for(int mask = 0 ; mask < (1 << nL) ; mask++){
        ll sum = 0;
        for(int i = 0 ; i < nL ; i++){
            if(mask >> i & 1){
                sum += L[i];
            }
        }
        sums[sum]++;
    }

    int nR = R.size();
    for(int mask = 0 ; mask < (1 << nR) ; mask++){
        ll sum = 0;
        for(int i = 0 ; i < nR ; i++){
            if(mask >> i & 1){
                sum += R[i];
            }
        }
        if(sums.count(s - sum)) ans += sums[s - sum];
    }

    cout << ans;
    
    return 0;
}