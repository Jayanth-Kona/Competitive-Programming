#include<bits/stdc++.h>
using namespace std;
using ll = long long;

/*

Problem link: https://www.spoj.com/problems/IITKWPCH/ 

Submission 1: Using bitsets O(2^n * n * bitset_complexity<maxN>)

*/

const int maxN = 1e6 + 5;

int main(){
    int t ; cin >> t;

    for(int tc = 1 ; tc <= t ; tc++){
        int n ; cin >> n;

        vector<bitset<maxN>> numberHavingDigit(10 , 0);

        for(int i = 1 ; i <= n ; i++){
            ll num ; cin >> num;

            bitset<maxN> curr;
            while(num > 0){
                numberHavingDigit[num % 10].set(i);
                num /= 10;
            }
        }

        ll ans = 0;

        for(int mask = 1 ; mask < (1 << 10) ; mask++){
            bitset<maxN> common;
            common.set();

            int bits = 0;

            for(int digit = 0 ; digit <= 9 ; digit++){
                if(mask >> digit & 1){
                    common &= numberHavingDigit[digit];
                    bits += 1;
                }
            }

            ll cnt = common.count();
            ll pairs = cnt * (cnt - 1) / 2;

            if(bits % 2 == 1) ans += pairs;
            else ans -= pairs;
        }

        cout << ans;
        if(tc != t) cout << "\n";
    }

    return 0;
}