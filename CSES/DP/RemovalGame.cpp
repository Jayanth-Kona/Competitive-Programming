#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll optimalDiff[5000][5000];

ll play(int L , int R , vector<int> &coins){
    if(L > R) return 0;
    if(optimalDiff[L][R] != -1e18) return optimalDiff[L][R];
    return optimalDiff[L][R] = max(coins[L] - play(L + 1 , R , coins) , coins[R] - play(L , R - 1 , coins));
}

int main(){
    int n ; cin >> n;

    for(int L = 0 ; L < n ; L++){
        for(int R = L ; R < n ; R++){
            optimalDiff[L][R] = -1e18;
        }
    }

    vector<int> coins(n);
    for(int &coin : coins) cin >> coin;

    ll diff = play(0 , n - 1 , coins); // alice - bob
    ll sum = accumulate(coins.begin() , coins.end() , 0LL); // alice + bob

    ll aliceScore = (diff + sum) / 2;
    cout << aliceScore;

    return 0;
}