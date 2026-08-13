#include<bits/stdc++.h>
using namespace std;

int main(){
    int n ; cin >> n;

    vector<array<int , 2>> a(n);
    for(auto &[h , w] : a){
        cin >> h >> w;
        w *= -1;
    }
    sort(a.begin() , a.end());

    vector<int> dp;
    for(int i = 0 ; i < n ; i++){
        int num = -a[i][1];
        if(dp.empty() || dp.back() < num) dp.push_back(num);
        else *lower_bound(dp.begin() , dp.end() , num) = num;
    }

    cout << dp.size();

    return 0;
}