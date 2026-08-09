#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll N , M , S , T;
    cin >> N >> M >> S >> T;

    ll L = min(S , T);
    ll R = max(S , T);

    ll total = 0;

    for(int i = 1 ; i <= M ; i++){
        ll P , V ; cin >> P >> V;
        if(L <= P && P <= R) total += V;
    }

    cout << total << "\n";

    return 0;
}