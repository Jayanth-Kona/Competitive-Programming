#include<bits/stdc++.h>
using namespace std;

int main(){
    int n ; cin >> n;

    vector<int> a(n);
    for(int &num : a) cin >> num;

    vector<int> order(n);
    iota(order.begin() , order.end() , 0);
    sort(order.begin() , order.end() , [&](int i , int j){
        return a[i] > a[j];
    });

    for(int pos : order) cout << pos + 1 << "\n";

    return 0;
}