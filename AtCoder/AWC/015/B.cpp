#include<bits/stdc++.h>
using namespace std;

int main(){
    int n , k ; cin >> n >> k;

    int logId = -1;

    for(int i = 1 ; i <= n ; i++){
        int severity ; cin >> severity;
        if(severity >= k && logId == -1){
            logId = i;
        }
    }

    cout << logId;

    return 0;
}