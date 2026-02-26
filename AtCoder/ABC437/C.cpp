#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int t ; cin >> t;

    while(t--){
        int n ; cin >> n;

        vector<array<ll , 2>> wp(n);
        for(auto &[w , p] : wp) cin >> w >> p;

        sort(wp.begin() , wp.end() , [&](array<ll , 2> &i , array<ll , 2> &j){
            return i[0] + i[1] < j[0] + j[1];
        });

        ll strength = 0 , weight = 0;
        for(auto &[w , p] : wp) strength += p;

        int canRide = 0;
        for(auto &[w , p] : wp){
            strength -= p;
            weight += w;
            if(strength < weight) break;
            canRide++;
        }
        
        cout << canRide << endl;
    }

    return 0;
}