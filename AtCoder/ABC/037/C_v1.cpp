#include<bits/stdc++.h>
using namespace std;
using ll = long long;

/*

Idea: Sliding Window

*/

int main(){
    int n , k ; cin >> n >> k;

    vector<int> a(n);
    for(int &num : a) cin >> num;

    ll sum = 0 , ans = 0;

    for(int i = 0 ; i < n ; i++){
        sum += a[i];
        if(i >= k - 1){
            ans += sum;
            sum -= a[i - k + 1];
        }
    }

    cout << ans;

    return 0;
}