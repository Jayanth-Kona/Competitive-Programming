#include<bits/stdc++.h>
using namespace std;
const int INF = 2e9;

int main(){
    int n , m ; cin >> n >> m;

    vector<int> weight(n);
    for(int &wi : weight) cin >> wi;

    vector<array<int , 2>> DP(1 << n , {INF , INF});
    DP[0] = {1 , 0};

    for(int mask = 0 ; mask < (1 << n) ; mask++){
        for(int item = 0 ; item < n ; item++){
            if(mask >> item & 1 ^ 1){
                array<int , 2> next;
                if(DP[mask][1] + weight[item] <= m){
                    next = {DP[mask][0] , DP[mask][1] + weight[item]};
                }
                else{
                    next = {DP[mask][0] + 1 , weight[item]};
                }
                DP[mask | 1 << item] = min(DP[mask | 1 << item] , next);
            }
        }
    }

    cout << DP.back()[0];

    return 0;
}