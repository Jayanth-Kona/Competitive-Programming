#include<bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main(){
    int n , reqd ; cin >> n >> reqd;

    vector<int> times(n);
    for(int &time : times) cin >> time;

    ll minTime = 1 , maxTime = *max_element(times.begin() , times.end()) * 1LL * reqd;
    ll actualTime = maxTime;

    while(minTime <= maxTime){
        ll currTime = (minTime + maxTime) >> 1;

        ll productMade = 0;
        for(int time : times){
            productMade += currTime / time;
            if(productMade >= reqd) break;
        }

        if(productMade < reqd){
            minTime = currTime + 1;
        }
        else{
            maxTime = currTime - 1;
            actualTime = currTime;
        }
    }

    cout << actualTime;

    return 0;
}
