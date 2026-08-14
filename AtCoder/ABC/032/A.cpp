#include<bits/stdc++.h>
using namespace std;

int main(){
    int a , b , n;
    cin >> a >> b >> n;

    int x = lcm(a , b);

    cout << x * ((n + x - 1) / x) << "\n";

    return 0;
}