#include<bits/stdc++.h>
using namespace std;

int main(){
    int n , q ; cin >> n >> q;

    vector<int> line(n + 1 , 0);

    for(int i = 1 ; i <= q ; i++){
        int l , r ; cin >> l >> r;
        line[l - 1] ^= 1;
        line[r] ^= 1;
    }

    cout << line[0];

    for(int i = 1 ; i < n ; i++){
        line[i] ^= line[i - 1];
        cout << line[i];
    }
    
    cout << "\n";
    
    return 0;
}