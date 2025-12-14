#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int main(){
    int n ; cin >> n;

    int summation = n * (n + 1) / 2;

    if(summation & 1){
        cout << 0;
    }
    else{
        int target = summation / 2;

        vector<int> ways(target + 1 , 0);
        ways[0] = 1;

        for(int coin = 1 ; coin <= n ; coin++){
            for(int sum = target ; sum >= coin ; sum--){
                ways[sum] = (ways[sum] + ways[sum - coin]) % mod;
            }
        }

        int uniqueWays = ways[target] * 1LL * ((mod + 1) / 2) % mod;
        cout << uniqueWays;
    }

    return 0;
}