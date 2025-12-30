#include<bits/stdc++.h>
using namespace std;
 

int main(){
    int N ; cin >> N;

    vector<int>  pos(N + 1);
    for(int T = 1 ; T <= N ; T++){
        int num ; cin >> num;
        pos[num] = T;
    }

    int rounds = 0 , curr = 1e9;
    for(int num = 1 ; num <= N ; num++){
        rounds += pos[num] < curr;
        curr = pos[num];
    }

    cout << rounds;

    return 0;
}