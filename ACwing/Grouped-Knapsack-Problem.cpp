#include<bits/stdc++.h>
using namespace std;

// Problem: https://www.acwing.com/problem/content/9/

int main(){
    int n , m ; cin >> n >> m;

    vector<int> maxValue(m + 1 , 0) , prevmaxValue(m + 1 , 0);

    for(int i = 0 ; i < n ; i++){
        int groupsize ; cin >> groupsize;

        for(int item = 1 ; item <= groupsize ; item++){
            int wi , vi ; cin >> wi >> vi;

            for(int j = m ; j >= wi ; j--){
                maxValue[j] = max(maxValue[j] , vi + prevmaxValue[j - wi]);
            }
        }
        
        prevmaxValue = maxValue;
    }

    cout << maxValue[m];

    return 0;
}