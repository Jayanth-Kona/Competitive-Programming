#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;

int main(){
    int a , b , c;
    cin >> a >> b >> c;

    cout << ((a * 1LL * b % mod) * 1LL * c) % mod;

    return 0;
}