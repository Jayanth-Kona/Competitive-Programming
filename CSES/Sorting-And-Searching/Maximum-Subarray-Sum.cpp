#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N ; cin >> N;

    ll sum = 0 , maxSum = -1e18;
    ll minPrefix = 0;

    for(int T = 1 ; T <= N ; T++){
        int num ; cin >> num;
        sum += num;
        maxSum = max(maxSum , sum - minPrefix);
        minPrefix = min(minPrefix , sum);
    }

    cout << maxSum;

    return 0;
}