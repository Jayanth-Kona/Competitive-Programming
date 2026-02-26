#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main(){
    int n ; cin >> n;

    vector<int> p(n + 1);
    for(int i = 1 ; i <= n ; i++){
        cin >> p[i];
    }

    ll pairs = 0;
    
    for(int i = 1; i <= n; i++){
        ll len = 0;
        while(p[i] != i){
            swap(p[i] , p[p[i]]);
            pairs += ++len;
        }
    }

    cout << pairs << endl;

    return 0;
}