#include<bits/stdc++.h>
using namespace std;
using ll = long long;

struct project{
    int startTime = 0 , endTime = 0 , reward = 0;

    friend bool operator<(project &curr , project &other){
        return curr.endTime < other.endTime;
    }
};


int main(){
    int n ; cin >> n;

    vector<project> projects(n + 1);
    for(int i = 1 ; i <= n ; i++){
        cin >> projects[i].startTime >> projects[i].endTime >> projects[i].reward;
    }
    sort(projects.begin() , projects.end());

    function<int(int)> lastProject = [&](int currProject){
        int low = 0 , high = currProject - 1;
        int j = low;

        while(low <= high){
            int mid = (low + high) >> 1;
            if(projects[mid].endTime < projects[currProject].startTime){
                j = mid;
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }

        return j;
    };

    vector<ll> maxRewards(n + 1 , 0);
    
    for(int i = 1 ; i <= n ; i++){
        ll skip = maxRewards[i - 1];
        
        int j = lastProject(i);
        ll take = projects[i].reward + maxRewards[j];

        maxRewards[i] = max(take , skip);
    }

    cout << maxRewards[n];

    return 0;
}