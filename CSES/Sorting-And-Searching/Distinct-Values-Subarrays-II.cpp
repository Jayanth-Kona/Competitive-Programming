#include<bits/stdc++.h>
using namespace std;

int main(){
    int N , K ; cin >> N >> K;

    vector<int> nums(N);
    for(int &num : nums) cin >> num;
    
    long long distinct = 0;
    map<int , int> map;

    for(int L = 0 , R = 0 ; R < N ; R++){
        map[nums[R]]++;
        while(map.size() > K){
            int leftmost = nums[L++];
            if(--map[leftmost] == 0) map.erase(leftmost);
        }
        distinct += R - L + 1;
    }

    cout << distinct;

    return 0;
}