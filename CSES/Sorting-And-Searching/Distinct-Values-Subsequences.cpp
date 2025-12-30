#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int main(){
    int N ; cin >> N;
 
    vector<int> nums(N);
    for(int &num : nums) cin >> num;
    sort(nums.begin() , nums.end());
 
    int subsets = 1;
 
    for(int L = 0 , R = 0 ; L < N ; L = R){
        while(R < N && nums[L] == nums[R]) R++;
        int ways = R - L + 1;
        subsets = (subsets * 1LL * ways) % mod;
    }

    subsets = (subsets - 1 + mod) % mod;
 
    cout << subsets;
 
    return 0;
}