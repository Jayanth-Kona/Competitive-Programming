#include<bits/stdc++.h>
using namespace std;

int main(){
    int n ; cin >> n;

    int awkward = 0;
    char prevL = '#'  , prevR = '#';

    for(int i = 1 ; i <= n ; i++){
        char currL , currR; cin >> currL >> currR;
        awkward += prevR == currL;
        prevL = currL;
        prevR = currR;
    }

    cout << awkward;

    return 0;
}