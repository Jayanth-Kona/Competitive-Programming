#include<bits/stdc++.h>
using namespace std;
using ll = long long;

/*

Problem link: https://www.spoj.com/problems/IITKWPCH/ 

Submission 2: Iterating over all supersets : O(4^n)

*/

int main(){
    int t ; cin >> t;

    for(int tc = 1 ; tc <= t ; tc++){
        int n ; cin >> n;

        vector<int> maskCnt(1024 , 0);

        for(int i = 1 ; i <= n ; i++){
            ll num ; cin >> num;

            int mask = 0;
            while(num > 0){
                mask |= 1 << (num % 10);
                num /= 10;
            }

            maskCnt[mask]++;
        }

        ll ans = 0;

        for(int mask = 1 ; mask < (1 << 10) ; mask++){
            ll cnt = 0;

            for(int superset = 1 ; superset < (1 << 10) ; superset++){
                if((superset & mask) == mask){
                    cnt += maskCnt[superset];
                }
            }

            ll pairs = cnt * (cnt - 1) / 2;

            if(__builtin_popcount(mask) % 2 == 1) ans += pairs;
            else ans -= pairs;
        }

        cout << ans;
        if(tc != t) cout << "\n";
    }

    return 0;
}