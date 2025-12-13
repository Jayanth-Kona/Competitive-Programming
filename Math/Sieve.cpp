#include<bits/stdc++.h>
using namespace std;

class Sieve{
public:
    vector<int> primes , isPrime , spf;

    Sieve(int n){
        isPrime.resize(n + 10 , 1);
        isPrime[0] = isPrime[1] = 0;

        spf.resize(n + 10 , 1);

        for(int num = 2 ; num * num <= n ; num++){
            if(isPrime[num]){
                for(int f = num * num ; f <= n ; f += num){
                    isPrime[f] = 0;
                    if(spf[f] == 1) spf[f] = num;
                }
            }
        }

        for(int num = 2 ; num <= n ; num++){
            if(isPrime[num]) primes.push_back(num);
        }

    }
};

int main(){
    return 0;
}