#include<bits/stdc++.h>
using namespace std;
using ll = long long;

/*
    
Idea: Contribution method

count how many subarrays of size k can contain a[i]

let's say s be the start of the subarray containing a[i]
then:
    s <= i <= s + k - 1

    s <= i
    s >= i - k + 1

also we know,
    s >= 0
    s <= n - k

so, 
    s >= max(0 , i - k + 1) --> min_start
    s <= min(i , n - k)     --> max_start

total = max_start - min_start + 1

so,
    contribution = a[i] * total
    
*/

int main(){
    int n , k ; cin >> n >> k;

    ll ans = 0;

    for(int i = 0 ; i < n ; i++){
        int num ; cin >> num;

        int min_start = max(0 , i - k + 1);
        int max_start = min(i , n - k);
        int total = max_start - min_start + 1;
        
        ans += num * 1LL * total;
    }

    cout << ans;

    return 0;
}