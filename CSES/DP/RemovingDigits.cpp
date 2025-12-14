#include<bits/stdc++.h>
using namespace std;


int main(){
    int n ; cin >> n;

    vector<int> minSteps(n + 1 , 1e9);
    minSteps[0] = 0;

    for(int number = 1 ; number <= n ; number++){
        for(char digit : to_string(number)){
            minSteps[number] = min(minSteps[number] , 1 + minSteps[number - (digit - '0')]);
        }
    }

    cout << minSteps[n];

    return 0;
}