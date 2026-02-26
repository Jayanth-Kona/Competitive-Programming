#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll n , m ; cin >> n >> m;

    for(int i = 1 ; i <= n ; i++){
        int num ; cin >> num;
        m -= num;
    }

    cout << (m <= 0 ? "Yes" : "No");

    return 0;
}