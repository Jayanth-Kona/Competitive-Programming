#include<bits/stdc++.h>
using namespace std;
 
int main(){
    int N , X ; cin >> N >> X;

    vector<int> nums(N);
    for(int &num : nums) cin >> num;
    sort(begin(nums) , end(nums));

    int gondolas = 0;

    for(int L = 0 , R = N - 1 ; L <= R ; R--){
        if(nums[L] + nums[R] <= X) L++;
        gondolas++;
    }

    cout << gondolas;

    return 0;
}
