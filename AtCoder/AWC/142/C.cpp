#include<bits/stdc++.h>
using namespace std;

int main(){
    int n , m , d , t;
    cin >> n >> m >> d >> t;

    vector<array<int , 3>> street; // {t , on/off , who}

    for(int i = 0 ; i < n ; i++){
        int ai ; cin >> ai;
        street.push_back({ai , +1 , 0});
        street.push_back({ai + d , -1 , 0});
    }

    for(int i = 0 ; i < m ; i++){
        int bi ; cin >> bi;
        street.push_back({bi , +1 , 1});
        street.push_back({bi + d , -1 , 1});
    }

    street.push_back({t + 1 , -1 , -1});
    sort(street.begin() , street.end());

    int ans = 0;
    int takahashi = 0 , aoki = 0;

    for(int i = 0 , j = 0 , p = 1 ; i < (int)street.size() ; i = j){
        if(takahashi > aoki) ans += street[i][0] - p;

        if(street[i][2] == -1) break;

        while(j < (int)street.size() && street[i][0] == street[j][0]){
            if(street[j][2] == 0){
                takahashi += street[j][1];
            }
            else if(street[j][2] == 1){
                aoki += street[j][1];
            }
            j++;
        }

        p = street[i][0];
    }

    cout << ans;

    return 0;
}