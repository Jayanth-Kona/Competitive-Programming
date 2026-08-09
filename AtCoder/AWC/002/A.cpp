#include<bits/stdc++.h>
using namespace std;

int main(){
    int n , k ; cin >> n >> k;
    
    int index = -1;

    for(int i = 1 ; i <= n ; i++){
        int num ; cin >> num;
        if(num == k && index == -1) index = i;
    }

    cout << index;
    
    return 0;
}