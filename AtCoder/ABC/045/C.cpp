#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    string num ; cin >> num;

    ll ans = 0;

    for(int mask = 0 , n = (int)num.size() ; mask < (1 << (n - 1)) ; mask++){
        ll curr = 0;

        for(int i = 0 ; i < n ; i++){
            curr = (curr * 10 + num[i] - '0');
            
            if(mask >> i & 1){
                ans += curr;
                curr = 0;
            }
        }

        ans += curr;
    }

    cout << ans;

    return 0;
}