#include<bits/stdc++.h>
using namespace std;

int main(){
    int n ; cin >> n;

    vector<int> nums(n);
    for(int &num : nums) cin >> num;
    sort(nums.begin() , nums.end());

    int distinct = 1;

    for(int i = 1 ; i < n ; i++) distinct += nums[i] != nums[i - 1];

    cout << distinct;

    return 0;
}