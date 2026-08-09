#include<bits/stdc++.h>
using namespace std;

// Problem: https://www.acwing.com/problem/content/5/

int main(){
    int n , m ; cin >> n >> m;

    vector<int> w , v;

    for(int i = 0 ; i < n ; i++){
        int wi , vi , ti;
        cin >> wi >> vi >> ti;

        for(int p = 1 ; p <= ti ; p <<= 1){
            w.push_back(p * wi);
            v.push_back(p * vi);
            ti -= p;
        }

        if(ti > 0){
            w.push_back(ti * wi);
            v.push_back(ti * vi);
        }
    }

    int totalItems = w.size();
    vector<long long> maxValue(m + 1 , 0);

    for(int i = 0 ; i < totalItems ; i++){
        for(int j = m ; j >= w[i] ; j--){
            maxValue[j] = max(maxValue[j] , v[i] + maxValue[j - w[i]]);
        }
    }

    cout << maxValue[m];

    return 0;
}