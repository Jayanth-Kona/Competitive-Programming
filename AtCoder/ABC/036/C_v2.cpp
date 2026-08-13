#include<bits/stdc++.h>
using namespace std;

int main(){
    int n ; cin >> n;

    vector<int> a(n);
    for(int &num : a) cin >> num;

    vector<int> b = a;
    sort(b.begin() , b.end());
    b.erase(unique(b.begin() , b.end()) , b.end());

    for(int num : a) cout << lower_bound(b.begin() , b.end() , num) - b.begin() << "\n";

    return 0;
}