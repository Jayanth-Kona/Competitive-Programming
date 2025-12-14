#include<bits/stdc++.h>
using namespace std;

int main(){
    int n ; cin >> n;

    vector<int> dp;
    
    for(int i = 1 ; i <= n ; i++){
        int num ; cin >> num;

        if(dp.empty() || dp.back() < num){
            dp.push_back(num);
        }
        
        else{
            int index = lower_bound(dp.begin() , dp.end() , num) - dp.begin();
            dp[index] = num;
        }
    }

    cout << dp.size();

    return 0;
}