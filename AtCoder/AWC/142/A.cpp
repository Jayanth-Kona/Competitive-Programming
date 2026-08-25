#include<bits/stdc++.h>
using namespace std;

int main(){
    int n ; cin >> n;

    int ans = 0;
    for(int i = 1 ; i <= n ; i++){
        double temp ; cin >> temp;
        ans += round(max(0.0 , temp - 37.0) * 10.0); // round because of precision errors
    }

    cout << ans;

    return 0;
}