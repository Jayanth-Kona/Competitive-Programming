#include<bits/stdc++.h>
using namespace std;

int main(){
    int n ; cin >> n;

    vector<int> a(n);
    for(int &num : a) cin >> num;
    sort(a.begin() , a.end());

    int mincost = 1e9;

    for(int mid = -100 ; mid <= +100 ; mid++){
        int cost = 0;
        for(int num : a) cost += (num - mid) * (num - mid);
        mincost = min(mincost , cost);
    }

    cout << mincost;

    return 0;
}