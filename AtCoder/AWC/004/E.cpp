#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll n , k ; cin >> n >> k;

    ll sum = 0 , pairs = 0;
    map<ll , ll> map = {{0 , 1}};

    for(int i = 1 ; i <= n ; i++){
        int num ; cin >> num;
        sum += num;
        if(map.count(sum - k)) pairs += map[sum - k];
        map[sum]++;
    }

    cout << pairs;

    return 0;
}