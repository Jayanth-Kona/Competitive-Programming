#include<bits/stdc++.h>
using namespace std;
using ll = long long;

/*

Problem link: https://www.spoj.com/problems/EASYMATH/

Submission: Using Standard Inclusion-Exclusion Principle over subsets and divisiblity logic

*/

ll lcm(ll a , ll b){
    return a / __gcd(a , b) * b;
}

int main(){
    int t ; cin >> t;

    while(t--){
        ll n , m , a , d;
        cin >> n >> m >> a >> d;

        ll total = m - n + 1;
        n -= 1;

        ll divisible = 0;

        for(int mask = 1 ; mask < (1 << 5) ; mask++){

            int bits = 0;
            ll divisor_n = 1 , divisor_m = 1;

            for(int i = 0 ; i < 5 ; i++){
                if(mask >> i & 1){
                    bits += 1;

                    ll num = a + i * d;

                    if(num <= n && divisor_n <= n){
                        divisor_n = lcm(divisor_n , num);
                        divisor_n = min(divisor_n , n + 1);
                    }
                    else{
                        divisor_n = n + 1;
                    }

                    if(num <= m && divisor_m <= m){
                        divisor_m = lcm(divisor_m , num);
                        divisor_m = min(divisor_m , m + 1);
                    }
                    else{
                        divisor_m = m + 1;
                    }
                }
            }

            ll cnt_n = n / divisor_n;
            ll cnt_m = m / divisor_m;

            if(bits % 2 == 1) divisible += (cnt_m - cnt_n);
            else divisible -= (cnt_m - cnt_n);
        }

        ll nondivisible = total - divisible;
        cout << nondivisible;

        if(t != 0) cout << "\n";
    }

    return 0;
}