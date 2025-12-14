#include<bits/stdc++.h>
using namespace std;

int main(){
    int n , target;
    cin >> n >> target;

    vector<int> coins(n);
    for(int &coin : coins) cin >> coin;

    vector<int> minCoins(target + 1 , 1e9);
    minCoins[0] = 0;

    for(int coin : coins){
        for(int sum = coin ; sum <= target ; sum++){
            minCoins[sum] = min(minCoins[sum] , 1 + minCoins[sum - coin]);
        }
    }

    if(minCoins[target] == 1e9) minCoins[target] = -1;
    cout << minCoins[target];

    return 0;
}