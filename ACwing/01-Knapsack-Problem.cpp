#include<bits/stdc++.h>
using namespace std;

// Problem: https://www.acwing.com/problem/content/2/

int main(){
    int n , m ; cin >> n >> m;

    vector<int> w(n) , v(n);
    for(int i = 0 ; i < n ; i++) cin >> w[i] >> v[i];

    vector<int> maxValue(m + 1 , 0);

    for(int i = 0 ; i < n ; i++){
        for(int j = m ; j >= w[i] ; j--){
            maxValue[j] = max(maxValue[j] , v[i] + maxValue[j - w[i]]);
        }
    }

    cout << maxValue[m];

    return 0;
}