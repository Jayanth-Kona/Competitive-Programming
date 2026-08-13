#include<bits/stdc++.h>
using namespace std;

int main(){
    int N ; cin >> N;

    int ans = 2e9;

    for(int i = 1 ; i * i <= N ; i++){
        int H = i;
        int W = N / i;
        int A = H * W;
        ans = min(ans , N - A + abs(H - W));
    }

    cout << ans;

    return 0;
}