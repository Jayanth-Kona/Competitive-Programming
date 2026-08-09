#include<bits/stdc++.h>
using namespace std;

// ai + bi * d >= m
// d >= (m - ai) / bi

int main(){
    int n  , m ; cin >> n >> m;

    int d = 0;

    for(int i = 1 ; i <= n ; i++){
        int ai , bi ; cin >> ai >> bi;
        int di = (m - ai + bi - 1) / bi;
        d = max(d , di);
    }

    cout << d;

    return 0;
}