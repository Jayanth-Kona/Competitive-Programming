#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int main(){
    int n ; cin >> n;

    vector<int> ways(n + 1 , 0);
    ways[0] = 1;

    for(int sum = 1 ; sum <= n ; sum++){
        for(int dice = 1 ; dice <= min(sum , 6) ; dice++){
            ways[sum] = (ways[sum] + ways[sum - dice]) % mod;
        }
    }

    cout << ways[n];
}