#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll n , m ; cin >> n >> m;

    vector<ll> a(n) , b(m);
    for(ll &num : a) cin >> num;
    for(ll &num : b) cin >> num;

    sort(a.begin() , a.end());
    sort(b.begin() , b.end());

    ll b_left_sum = 0;
    ll b_right_sum = accumulate(b.begin() , b.end() , 0LL);

    ll diffSum = 0;

    for(int a_ptr = 0 , b_ptr = 0 ; a_ptr < n ; a_ptr++){
        /*
            b[0....b_ptr) <= a[a_ptr]
            
            Contribution for a[a_ptr]:

                left_part   : a[a_ptr] * b_ptr - sum(b[0...(b_ptr - 1)]) 
                            : a[a_ptr] * b_ptr - b_left_sum
                
                right_part  : sum(b[(b_ptr - 1)...(m - 1)]) - a[a_ptr] * (m - b_ptr)
                            : b_right_sum - a[a_ptr] * (m - b_ptr)
            
        */

        while(b_ptr < m && b[b_ptr] <= a[a_ptr]){
            b_left_sum += b[b_ptr];
            b_right_sum -= b[b_ptr];
            b_ptr++;
        }

        ll Contribution = (a[a_ptr] * b_ptr - b_left_sum) + (b_right_sum - a[a_ptr] * (m - b_ptr));
        diffSum = (diffSum + Contribution) % 998244353;

    }

    cout << diffSum;

    return 0;
}