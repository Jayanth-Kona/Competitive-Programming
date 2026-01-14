#include<bits/stdc++.h>
using namespace std;
 
int main(){
    int n , k ; cin >> n >> k;
 
    vector<array<int,2>> times(n);
    for(int i = 0 ; i < n ; i++) cin >> times[i][0] >> times[i][1];
 
    sort(times.begin() , times.end() , [&](array<int,2> &t1 , array<int,2> &t2){
        return t1[1] < t2[1];
    });
 
    multiset<int> free;
    for(int i = 1 ; i <= k ; i++) free.insert(0);
 
    int count = 0;
 
    for(int i = 0 ; i < n ; i++){
        if(free.empty() == false && *free.begin() <= times[i][0]){
            auto it = prev(free.upper_bound(times[i][0]));
            free.erase(it);
            free.insert(times[i][1]);
            count++;
        }
    }
 
    cout << count;
    return 0;
}