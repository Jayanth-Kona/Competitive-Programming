#include<bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main(){
    int n , k;
    cin >> n >> k;
 
    ll x0 , a , b , c;
    cin >> x0 >> a >> b >> c;
 
    vector<ll> x(n);
    x[0] = x0;
    for(int i = 1 ; i < n ; i++) x[i] = (a * x[i - 1] % c + b) % c;
    
    deque<int> dq;
    ll xor_min = 0;
 
    for(int i = 0 ; i < n ; i++){
        while(dq.empty() == false && x[i] <= x[dq.back()]) dq.pop_back();
        dq.push_back(i);
        if(i >= k - 1){
            xor_min ^= x[dq.front()];
            while(dq.empty() == false && dq.front() <= i - k + 1) dq.pop_front();
        }
    }
 
    cout << xor_min;
 
    return 0;
}