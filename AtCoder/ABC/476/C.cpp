#include<bits/stdc++.h>
using namespace std;

int main(){
    int n ; cin >> n;
    
    int a[3] = {0 , 0 , 0};

    for(int i = 1 ; i <= n ; i++){
        int num ; cin >> num;

        if(num >= a[0]){
            a[2] = a[1];
            a[1] = a[0];
            a[0] = num;
        }
        else if(num >= a[1]){
            a[2] = a[1];
            a[1] = num;
        }
        else if(num > a[2]){
            a[2] = num;
        }

        if(i >= 3) cout << a[2] << "\n";
    }

    return 0;
}