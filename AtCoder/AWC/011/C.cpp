#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll n , k ; cin >> n >> k;

    ll size = 0 , team = 0;

    for(int i = 1 ; i <= n ; i++){
        ll num ; cin >> num;
        if((k | num) == k){
            size += 1;
            team |= num;
        }
    }

    if(team == k && size > 0) cout << size;
    else cout << "-1";

    return 0;
}