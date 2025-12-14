#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int main(){
    int n , m ; cin >> n >> m;

    vector<int> nums(n);
    for(int &num : nums) cin >> num;

    vector<int> prevWays(m + 1 , 0) , currWays(m + 1 , 0);

    if(nums[0] == 0){
        for(int place = 1 ; place <= m ; place++) prevWays[place] = 1;
    }
    else{
        prevWays[nums[0]] = 1;
    }

    for(int i = 1 ; i < n ; i++){

        if(nums[i] != 0){
            for(int place = 1 ; place <= m ; place++){
                if(place == nums[i]){
                    currWays[place] = 0;
                    for(int prev = max(1 , place - 1) ; prev <= min(m , place + 1) ; prev++){
                        currWays[place] = (currWays[place] + prevWays[prev]) % mod;
                    }
                }
                else{
                    currWays[place] = 0;
                }
            }
        }

        else{
            for(int place = 1 ; place <= m ; place++){
                currWays[place] = 0;
                for(int prev = max(1 , place - 1) ; prev <= min(m , place + 1) ; prev++){
                    currWays[place] = (currWays[place] + prevWays[prev]) % mod;
                }
            }
        }

        prevWays = currWays;
    }

    int totalways = 0;
    for(int place = 1 ; place <= m ; place++) totalways = (totalways + prevWays[place]) % mod;

    cout << totalways;

    return 0;
}