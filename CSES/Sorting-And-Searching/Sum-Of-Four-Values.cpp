#include<bits/stdc++.h>
using namespace std;

int main(){
    int n , sum;
    cin >> n >> sum;

    vector<int> nums(n);
    for(int &num : nums) cin >> num;

    map<int , array<int , 2>> sums;

    for(int x3 = 0 ; x3 <= n - 2 ; x3++){

        for(int x4 = x3 + 1 ; x4 <= n - 1 ; x4++){
            int reqd = sum - (nums[x3] + nums[x4]);
            if(sums.count(reqd)){
                int x1 = sums[reqd][0];
                int x2 = sums[reqd][1];
                cout << (1 + x1) << " " << (1 + x2) << " " << (1 + x3) << " " << (1 + x4);
                return 0;
            }

        }

        for(int x2 : {x3}){
            for(int x1 = x2 - 1 ; x1 >= 0 ; x1--){
                if(!sums.count(nums[x1] + nums[x2])){
                    sums[nums[x1] + nums[x2]] = {x1 , x2};
                }
            }
        }
    }

    cout << "IMPOSSIBLE";

    return 0;
}