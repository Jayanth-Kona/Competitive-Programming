#include<bits/stdc++.h>
using namespace std;

int main(){
    int n ; cin >> n;

    if(n & 1) cout << n + 1 << "\n";
    else cout << n - 1 << "\n";
    
    return 0;
}