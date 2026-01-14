#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N , K ; cin >> N >> K;

    vector<int> nums(N);
    for(int &num : nums) cin >> num;

    ll minSum = *max_element(nums.begin() , nums.end()); // when K = 1
    ll maxSum = accumulate(nums.begin() , nums.end() , 0LL); // when K = N

    ll optimalSum = maxSum;

    while(minSum <= maxSum){
        ll threshold = (minSum + maxSum) >> 1;

        ll subarrays = 1 , currSum = 0;

        for(int num : nums){
            if(currSum + num > threshold){
                currSum = num;
                subarrays++;
            }
            else{
                currSum += num;
            }
        }

        if(subarrays <= K) maxSum = (optimalSum = threshold) - 1;
        else minSum = threshold + 1;
    }
    
    cout << optimalSum;

    return 0;
}