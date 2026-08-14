#include<bits/stdc++.h>
using namespace std;

int mask(int n){
    int m = 0;
    while(n > 0){
        m |= 1 << (n % 10);
        n /= 10;
    }
    return m;
}

int main(){
    int n , k ; cin >> n >> k;

    int dislike = 0;
    for(int i = 1 ; i <= k ; i++){
        int d ; cin >> d;
        dislike |= 1 << d;
    }

    while(mask(n) & dislike) n++;

    cout << n;

    return 0;
}