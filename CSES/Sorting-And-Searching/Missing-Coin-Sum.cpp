#include<bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main(){
    int N ; cin >> N;

    vector<int> coins(N);
    for(int &coin : coins) cin >> coin;
    sort(coins.begin() , coins.end());

    ll nextReqdCoin = 1;
    for(int &coin : coins){
        if(coin > nextReqdCoin) break;
        nextReqdCoin += coin;
    }

    cout << nextReqdCoin;

    return 0;
}