#include<bits/stdc++.h>
using namespace std;

int minswaps(vector<int> a , int swaps = 0 , int vis = 0){
    for(int i = 0 ; i < (int)a.size() ; i++){
        if(a[i] != i && (vis >> i & 1 ^ 1)){
            int j = i;
            int len = 0;
            while(vis >> j & 1 ^ 1){
                len += 1;
                vis |= 1 << j;
                j = a[j];
            }
            swaps += max(0 , len - 1);
        }
    }
    return swaps;
}

int main(){
    int n , k ; cin >> n >> k;

    vector<vector<int>> c(n , vector<int>(n));

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            cin >> c[i][j];
        }
    }

    vector<int> order(n);
    iota(order.begin() , order.end() , 0);

    int ans = 0;

    do{
        if(minswaps(order) <= k){
            int curr = 0;
            for(int i = 0 ; i < n ; i++){
                int x = order[i];
                int y = order[(i + 1) % n];
                curr += c[x][y];
            }
            ans = max(ans , curr);
        }
    }while(next_permutation(order.begin() , order.end()));

    cout << ans;

    return 0;
}