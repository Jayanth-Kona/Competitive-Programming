#include<bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main(){
    int n , target;
    cin >> n >> target;
 
    vector<int> nums(n);
    for(int &num : nums) cin >> num;
 
    ll subarrays = 0 , sum = 0;
    map<ll , int> map = {{0 , +1}};
 
    for(int &num : nums){
        sum += num;
        if(map.count(sum - target)) subarrays += map[sum - target];
        map[sum]++;
    }
 
    cout << subarrays;
    
    return 0;
}
