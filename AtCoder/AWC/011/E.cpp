#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int n , m ; cin >> n >> m;
    vector<vector<ll>> prefix(n + 2 , vector<ll>(m + 1 , 0)) , suffix(n + 2 , vector<ll>(m + 1 , 0));

    vector<int> a(n + 1) , b(n + 1);
    for(int i = 1 ; i <= n ; i++) cin >> a[i] >> b[i];

    for(int i = 1 ; i <= n ; i++){
        for(int w = 0 ; w <= m ; w++){
            prefix[i][w] = prefix[i - 1][w];
            if(a[i] <= w) prefix[i][w] = max(prefix[i][w] , b[i] + prefix[i - 1][w - a[i]]);
        }
    }

    for(int i = n ; i >= 1 ; i--){
        for(int w = 0 ; w <= m ; w++){
            suffix[i][w] = suffix[i + 1][w];
            if(a[i] <= w) suffix[i][w] = max(suffix[i][w] , b[i] + suffix[i + 1][w - a[i]]);
        }
    }

    ll optimal = prefix[n][m];

    for(int i = 1 ; i <= n ; i++){
        int good = 0;
        for(int pw = 0 ; pw <= m ; pw++){
            int sw = m - pw - a[i];
            if(sw >= 0 && prefix[i - 1][pw] + b[i] + suffix[i + 1][sw] == optimal){
                good = 1;
                break;
            }
        }
        cout << (good ? "Yes" : "No") << " \n"[i == n - 1];
    }

    return 0;
}