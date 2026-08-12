#include <bits/stdc++.h>
using namespace std;

int main(){
    int n , k ; cin >> n >> k;
    
    vector<int> a(n);
    for(int &num : a) cin >> num;

    sort(a.begin() , a.end());
    
    double rating = 0.0;
    for(int i = n - k ; i < n ; i++) rating = (rating + a[i]) / 2.0;
    
    cout << fixed << setprecision(10) << rating << "\n";
    
    return 0;
}