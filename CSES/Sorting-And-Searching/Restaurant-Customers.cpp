#include<bits/stdc++.h>
using namespace std;

int main(){
    int N ; cin >> N;

    vector<array<int , 2>> Events;
    for(int T = 1 ; T <= N ; T++){
        int startTime , endTime;
        cin >> startTime >> endTime;
        Events.push_back({startTime , +1});
        Events.push_back({endTime , -1});
    }

    sort(Events.begin() , Events.end());
    
    int currCustomers = 0 , maxCustomers = 0;

    for(int L = 0 , R = 0 ; L < 2 * N ; L = R){
        while(R < 2 * N && Events[L][0] == Events[R][0]){
            currCustomers += Events[R++][1];
        }
        maxCustomers = max(maxCustomers , currCustomers);
    }

    cout << maxCustomers;

    return 0;
}