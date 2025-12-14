#include<bits/stdc++.h>
using namespace std;

int main(){
    int n ; cin >> n;

    vector<int> coins(n);
    for(int &coin : coins) cin >> coin;

    int maxsum = accumulate(coins.begin() , coins.end() , 0);

    vector<bool> canMake(maxsum + 1 , false);
    canMake[0] = true;

    for(int coin : coins){
        for(int sum = maxsum ; sum >= coin ; sum--){
            if(canMake[sum - coin]){
                canMake[sum] = 1;
            }
        }
    }

    int distinctSums = count(canMake.begin() + 1 , canMake.end() , true);
    cout << distinctSums << endl;

    for(int sum = 1 ; sum <= maxsum ; sum++){
        if(canMake[sum] == true){
            cout << sum << " ";
        }
    }

    return 0;
}