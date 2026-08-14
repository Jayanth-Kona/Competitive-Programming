#include<bits/stdc++.h>
using namespace std;

/*

Source: DeepSeek
Reason: Sum of squared deviations ∑(a_i - T)² is minimized at foor(mean) and ceil(mean)

*/


int main(){
    int n ; cin >> n;

    vector<int> a(n);
    for(int &num : a) cin >> num;
    
    int mincost = 1e9;
    int sum = accumulate(a.begin() , a.end() , 0);

    for(int mid : {sum / n , (sum + n - 1) / n}){
        int cost = 0;
        for(int num : a) cost += (num - mid) * (num - mid);
        mincost = min(mincost , cost);
    }

    cout << mincost;

    return 0;
}