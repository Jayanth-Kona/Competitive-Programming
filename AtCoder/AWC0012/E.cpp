#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int n , k ; cin >> n >> k;

    deque<int> dq;
    vector<ll> dp(n);

    for(int i = 0 ; i < n ; i++){
        if(dq.empty() == false && dq.front() == i - k - 1) dq.pop_front();

        cin >> dp[i];
        if(dq.empty() == false) dp[i] += dp[dq.front()];

        while(dq.empty() == false && dp[dq.back()] <= dp[i]) dq.pop_back();
        dq.push_back(i);
    }

    cout << dp[n - 1];

    return 0;
}