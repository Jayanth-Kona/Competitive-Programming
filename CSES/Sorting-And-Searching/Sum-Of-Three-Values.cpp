#include<bits/stdc++.h>
using namespace std;

int main(){
    int n , sum;
    cin >> n >> sum;

    vector<int> nums(n);
    for(int &num : nums) cin >> num;

    vector<int> order(n , 0);
    iota(order.begin() , order.end() , 0);
    sort(order.begin() , order.end() , [&](int i , int j){
        return nums[i] < nums[j];
    });

    for(int i = 0 ; i <= n - 3 ; i++){
        int j = i + 1;
        int k = n - 1;
        while(j < k){
            int currSum = nums[order[i]] + nums[order[j]] + nums[order[k]];
            if(currSum == sum){
                cout << (1 + order[i]) << " " << (1 + order[j]) << " " << (1 + order[k]);
                return 0;
            }
            else if(currSum < sum){
                j++;
            }
            else{
                k--;
            }
        }
    }

    cout << "IMPOSSIBLE";

    return 0;
}