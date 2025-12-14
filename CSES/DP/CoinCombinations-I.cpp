#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int main(){
    int n , target;
    cin >> n >> target;

    vector<int> coins(n);
    for(int &coin : coins) cin >> coin;

    vector<int> ways(target + 1 , 0);
    ways[0] = 1;

    for(int sum = 1 ; sum <= target ; sum++){
        for(int coin : coins){
            if(coin <= sum){
                ways[sum] = (ways[sum] + ways[sum - coin]) % mod;
            }
        }
    }

    cout << ways[target];

    return 0;
}