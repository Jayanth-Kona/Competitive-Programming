#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int n , k ; cin >> n >> k;

    vector<int> a(n);
    for(int &num : a) cin >> num;
    sort(a.begin() , a.end());
    
    cout << accumulate(a.begin() , a.begin() + n - k , 0LL) + k;

    return 0;
}