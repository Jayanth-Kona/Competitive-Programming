#include<bits/stdc++.h>
using namespace std;
 
const int mod = 1e9 + 7;
 
int StandardApproach(int n , vector<int> &nums){
    int total_lis = 0;
    vector<int> endingAt(n , 1);
 
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < i ; j++){
            if(nums[j] < nums[i]){
                endingAt[i] = (endingAt[i] + endingAt[j]) % mod;
            }
        }
        total_lis = (total_lis + endingAt[i]) % mod;
    }
 
    return total_lis;
}
        
void compress(vector<int> &nums){
    map<int , int> map;
    for(int &num : nums) map[num] = 1;
 
    int newID = 1;
    for(auto &[num , ID] : map) ID = newID++;
 
    for(int &num : nums) num = map[num];
}
 
int main(){
    int n ; cin >> n;
 
    vector<int> nums(n);
    for(int &num : nums) cin >> num;
 
    compress(nums);
 
    cout << StandardApproach(n , nums);
 
    return 0;
}