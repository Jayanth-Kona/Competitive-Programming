#include<bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main(){
    int N ; cin >> N;

    vector<int> sticks(N);
    for(int &stick : sticks) cin >> stick;
    sort(sticks.begin() , sticks.end());

    ll minCost = 0 , median = sticks[N / 2];
    for(int &stick : sticks) minCost += abs(stick - median);

    cout << minCost;

    return 0;
}