#include<bits/stdc++.h>
using namespace std;

int main(){
    int m ; cin >> m;

    double km = m / 1000.0;

    int vv;

    if(km < 0.1){
        vv = 0;
    }
    else if(km <= 5.0){
        vv = (km * 10);
    }
    else if(km <= 30.0){
        vv = (km + 50);
    }
    else if(km <= 70.0){
        vv = ((km - 30) / 5 + 80);
    }
    else{
        vv = 89;
    }

    printf("%02d\n", vv);

    return 0;
}