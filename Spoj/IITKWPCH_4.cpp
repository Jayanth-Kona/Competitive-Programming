#include<bits/stdc++.h>
using namespace std;
using ll = long long;

/*

Problem link: https://www.spoj.com/problems/IITKWPCH/ 

Submission 4: Using SOS DP (supersets) : O(n * 2^n)

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

        vector<int> superset = maskCnt;

        for(int d = 0 ; d < 10 ; d++){
            for(int mask = 1 ; mask < (1 << 10) ; mask++){
                if(mask >> d & 1 ^ 1){
                    superset[mask] += superset[mask | (1 << d)];
                }
            }
        }

        ll ans = 0;

        for(int mask = 1 ; mask < (1 << 10) ; mask++){
            ll cnt = superset[mask];
            ll pairs = cnt * (cnt - 1) / 2;

            if(__builtin_popcount(mask) % 2 == 1) ans += pairs;
            else ans -= pairs;
        }

        cout << ans;
        if(tc != t) cout << "\n";
    }

    return 0;
}