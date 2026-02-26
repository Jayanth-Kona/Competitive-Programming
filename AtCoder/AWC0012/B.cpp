#include<bits/stdc++.h>
using namespace std;

int main(){
    int n , t , c , d;
    cin >> n >> t >> c >> d;

    int defect = 0;

    for(int i = 1 ; i <= n ; i++){
        int temp ; cin >> temp;
        if(temp >= t) defect++;
    }

    cout << defect * 1LL * min(c , d);

    return 0;
}