#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll q , v ; cin >> q >> v;

    multiset<ll> set;

    for(int i = 1 ; i <= q ; i++){
        int qt ; cin >> qt;
        
        if(qt == 1){
            int t , w ; cin >> t >> w;
            set.insert(w - t);
        }
        else{
            ll t ; cin >> t;
            if(set.empty() == true){
                cout << "-1\n";
            }
            else{
                ll charge = *set.rbegin();
                set.extract(charge);
                cout << min(v , charge + t) << "\n";
            }
        }
    }

    return 0;
}