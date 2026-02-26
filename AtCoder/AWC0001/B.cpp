#include<bits/stdc++.h>
using namespace std;

int main(){
    int n  , l , r ;  cin >> n >> l >> r;

    int id = -1 , maxi = -1;

    for(int i = 1 ; i <= n ; i++){
        int curr ; cin >> curr;
        if(l <= curr && curr <= r && maxi < curr){
            id = i;
            maxi = curr;
        }
    }
    
    cout << id;

    return 0;
}