#include<bits/stdc++.h>
using namespace std;

int main(){
    int n , m ; cin >> n >> m;
    int x , y ; cin >> x >> y;

    set<int> a , b;

    for(int i = 1 ; i <= n ; i++){
        int num ; cin >> num;
        a.insert(num);
    }

    for(int i = 1 ; i <= m ; i++){
        int num ; cin >> num;
        b.insert(num);
    }

    int roundsTrips = 0 , num = 0;

    while(true){
        auto it1 = a.lower_bound(num);
        if(it1 == a.end()) break;

        auto it2 = b.lower_bound(*it1 + x);
        if(it2 == b.end()) break;

        roundsTrips += 1;

        auto it3 = a.lower_bound(*it2 + y);
        if(it3 == a.end()) break;

        num = *it3;
    }

    cout << roundsTrips << "\n";

    return 0;
}