#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;

// Problem: https://www.acwing.com/problem/content/11/

int main(){
    int n , m ; cin >> n >> m;

    vector<int> w(n) , v(n);
    for(int i = 0 ; i < n ; i++) cin >> w[i] >> v[i];

    vector<int> maxValue(m + 1 , 0) , solutions(m + 1 , 1);

    for(int i = 0 ; i < n ; i++){
        for(int j = m ; j >= w[i] ; j--){
            if(solutions[j - w[i]] > 0){
                int new_maxValue = v[i] + maxValue[j - w[i]];
                if(new_maxValue == maxValue[j]){
                    solutions[j] += solutions[j - w[i]];
                    if(solutions[j] >= mod) solutions[j] -= mod;
                }
                else if(new_maxValue > maxValue[j]){
                    maxValue[j] = new_maxValue;
                    solutions[j] = solutions[j - w[i]];
                }
            }
        }
    }

    cout << solutions[m];

    return 0;
}