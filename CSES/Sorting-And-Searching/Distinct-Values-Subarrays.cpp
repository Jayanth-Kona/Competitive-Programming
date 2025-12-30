#include<bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main(){
    int N ; cin >> N;
 
    vector<int> nums(N);
    for(int &num : nums) cin >> num;
 
    map<int , int> seenAt;
    ll distinctValueSubarrays = 0;
 
    for(int L = 0 , R = 0 ; R < N ; R++){
        if(seenAt.count(nums[R])) L = max(L , 1 + seenAt[nums[R]]);
        distinctValueSubarrays += R - L + 1;
        seenAt[nums[R]] = R;
    }
 
    cout << distinctValueSubarrays;
 
    return 0;
}