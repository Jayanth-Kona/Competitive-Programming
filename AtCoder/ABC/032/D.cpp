#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void meet_in_the_middle(int n , int c , vector<int> &w , vector<int> &v){
    vector<int> L , R;
    for(int i = 0 ; i < n ; i++){
        if(i % 2 == 0){
            L.push_back(i);
        }
        else{
            R.push_back(i);
        }
    }

    ll max_v = 0;

    int Lsize = L.size();
    vector<array<ll , 2>> leftsubsets;

    for(int mask = 0 ; mask < (1 << Lsize) ; mask++){
        ll tot_w = 0 , tot_v = 0;
        for(int i = 0 ; i < Lsize ; i++){
            if(mask >> i & 1){
                tot_w += w[L[i]];
                tot_v += v[L[i]];
            }
        }
        if(tot_w <= c){
            max_v = max(max_v , tot_v);
            leftsubsets.push_back({tot_w , tot_v});
        }
    }


    int Rsize = R.size();
    vector<array<ll , 2>> rightsubsets;

    for(int mask = 0 ; mask < (1 << Rsize) ; mask++){
        ll tot_w = 0 , tot_v = 0;
        for(int i = 0 ; i < Rsize ; i++){
            if(mask >> i & 1){
                tot_w += w[R[i]];
                tot_v += v[R[i]];
            }
        }
        if(tot_w <= c){
            max_v = max(max_v , tot_v);
            rightsubsets.push_back({tot_w , tot_v});
        }
    }

    sort(rightsubsets.begin() , rightsubsets.end());
    for(int i = 1 ; i < (int)rightsubsets.size() ; i++) rightsubsets[i][1] = max(rightsubsets[i][1] , rightsubsets[i - 1][1]);


    for(int i = 0 ; i < (int)leftsubsets.size() ; i++){
        ll rem_w = c - leftsubsets[i][0];

        if(rem_w > 0){
            int j = upper_bound(rightsubsets.begin() , rightsubsets.end() , array<ll , 2>{rem_w , (ll)1e18}) - rightsubsets.begin() - 1;
            if(j >= 0) max_v = max(max_v , leftsubsets[i][1] + rightsubsets[j][1]);
        }
    }
    

    cout << max_v << "\n";
}

void standard_knapsack(int n , int c , vector<int> &w , vector<int> &v){
    c = min(c , accumulate(w.begin() , w.end() , 0));

    vector<ll> dp(c + 1 , 0);

    for(int i = 0 ; i < n ; i++){
        for(int j = c ; j >= w[i] ; j--){
            dp[j] = max(dp[j] , v[i] + dp[j - w[i]]);
        }
    }

    cout << dp[c] << "\n";
}

void reverse_state_knapsack(int n , int c , vector<int> &w , vector<int> &v){
    int tot_v = accumulate(v.begin() , v.end() , 0);

    vector<ll> dp(tot_v + 1 , 1e18);
    dp[0] = 0;

    for(int i = 0 ; i < n ; i++){
        for(int j = tot_v ; j >= v[i] ; j--){
            dp[j] = min(dp[j] , w[i] + dp[j - v[i]]);
        }
    }

    ll max_v = 0;

    for(int v = tot_v ; v >= 0 ; v--){
        if(dp[v] <= c){
            max_v = v;
            break;
        }
    }

    cout << max_v << "\n";
}

int main(){
    int n , c ; cin >> n >> c;

    vector<int> w(n) , v(n);
    for(int i = 0 ; i < n ; i++) cin >> v[i] >> w[i];

    if(n <= 30){
        meet_in_the_middle(n , c , w , v);
    }
    else if(*max_element(w.begin() , w.end()) <= 1e3){
        standard_knapsack(n , c , w , v);
    }
    else if(*max_element(v.begin() , v.end()) <= 1e3){
        reverse_state_knapsack(n , c , w , v);
    }
    else{
        // Invalid Testcase
    }

    return 0;
}