#include<bits/stdc++.h>
using namespace std;
 
int main(){
    int n ; cin >> n;

    vector<int> nums(n);
    for(int &num : nums) cin >> num;

    vector<int> nse(n) , stack;

    for(int i = 0 ; i < n ; i++){
        while(stack.empty() == false && nums[i] <= nums[stack.back()]) stack.pop_back();
        nse[i] = 1 + (stack.empty() == false ? stack.back() : -1);
        stack.push_back(i);
    }

    for(int pos : nse) cout << pos << " ";

    return 0;
}
