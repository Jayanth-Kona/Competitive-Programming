#include<bits/stdc++.h>
using namespace std;
using ll = long long;

/*

Problem link: https://www.spoj.com/problems/KPRIMESB/

Submission: Using Standard Inclusion-Exclusion Principle over subsets and lcm logic

*/

ll lcm(ll a , ll b){
    return a / __gcd(a , b) * b;
}

int main(){
    const int maxN = 1e6 + 5;

    vector<bool> isPrime(maxN + 1 , true);
    isPrime[0] = isPrime[1] = false;

    for(int num = 2 ; num * num <= maxN ; num++){
        if(isPrime[num]){
            for(int f = num * num ; f <= maxN ; f += num){
                isPrime[f] = false;
            }            
        }
    }

    vector<int> primesCnt(maxN + 1 , 0);
    for(int num = 2 ; num <= maxN ; num++){
        primesCnt[num] = isPrime[num] + primesCnt[num - 1];
    }

    int t ; cin >> t;

    for(int tc = 1 ; tc <= t ; tc++){

        int n , r ; cin >> n >> r;

        int exluded = 0;

        vector<int> a(r);
        for(int &num : a){
            cin >> num;
            exluded += num <= n;
        }

        int divisible = 0;

        for(int mask = 1 ; mask < (1 << r) ; mask++){
            ll common = 1 , bits = 0;
            for(int i = 0 ; i < r ; i++){
                if(mask >> i & 1){
                    bits += 1;
                    common = lcm(common , a[i]);
                    if(common > n) break;
                }
            }

            int cnt = n / common;

            if(bits % 2 == 1) divisible += cnt;
            else divisible -= cnt;
        }


        int not_divisible = (n - divisible) + (exluded) - (primesCnt[n]) - (n >= 1 ? 1 : 0);
        cout << "Case " << tc << ": " << not_divisible;

        if(tc != t) cout << "\n";
    }

    return 0;
}