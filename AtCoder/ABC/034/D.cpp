#include<bits/stdc++.h>
using namespace std;

// Took Help from DeepSeek wrt to concentrations-mixing logic

int main(){
    int n , k ; cin >> n >> k;

    vector<array<double , 2>> wp(n);
    for(auto &[wi , pi] : wp) cin >> wi >> pi;

    double low = 0 , high = 100;
    double ans = 0;

    for(int iter = 1 ; iter <= 72 ; iter++){
        double mid = (low + high) / 2.0;

        vector<double> concentrations;
        for(int i = 0 ; i < n ; i++) concentrations.push_back(wp[i][0] * wp[i][1] / 100.0 - wp[i][0] * mid / 100.0);

        sort(concentrations.rbegin() , concentrations.rend());

        double curr = 0;
        for(int i = 0 ; i < k ; i++) curr += concentrations[i];

        if(curr >= 0) low = mid;
        else high = mid;
    }

    cout << fixed << setprecision(8) << low << "\n";

    return 0;
}