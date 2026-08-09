#include<bits/stdc++.h>
using namespace std;

// Problem: https://www.acwing.com/problem/content/4/

int main(){
    int n , m ; cin >> n >> m;

    vector<int> w(n) , v(n) , t(n);
    for(int i = 0 ; i < n ; i++) cin >> w[i] >> v[i] >> t[i];

    vector<int> maxValue(m + 1 , 0) , prevmaxValue(m + 1 , 0);

    for(int i = 0 ; i < n ; i++){
        for(int times = 1 ; times <= t[i] && w[i] * times <= m ; times++){
            for(int j = m ; j >= w[i] * times ; j--){
                maxValue[j] = max(maxValue[j] , v[i] * times + prevmaxValue[j - w[i] * times]);
            }
        }
        prevmaxValue = maxValue;
    }

    cout << maxValue[m];

    return 0;
}