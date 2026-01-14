#include<bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main(){
    int n ; cin >> n;
 
    vector<int> nums(n);
    for(int &num : nums) cin >> num;
 
    ll subarrays = 0 , remainder = 0;
    map<ll , int> map = {{0 , +1}};
 
    for(int &num : nums){
        remainder = ((remainder + num) % n + n) % n;
        if(map.count(remainder)) subarrays += map[remainder];
        map[remainder]++;
    }
 
    cout << subarrays;
    
    return 0;
}
