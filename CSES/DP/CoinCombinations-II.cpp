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

    for(int coin : coins){
        for(int sum = coin ; sum <= target ; sum++){
            ways[sum] = (ways[sum] + ways[sum - coin]) % mod;
        }
    }

    cout << ways[target];

    return 0;
}