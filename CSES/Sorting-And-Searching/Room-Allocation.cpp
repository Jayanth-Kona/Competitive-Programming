#include<bits/stdc++.h>
using namespace std;
 
int main(){
    int n ; cin >> n;
 
    vector<array<int , 2>> times(n);
    for(int i = 0 ; i < n ; i++) cin >> times[i][0] >> times[i][1];
 
    vector<int> order(n);
    iota(order.begin() , order.end() , 0);
 
    sort(order.begin() , order.end() , [&](int i , int j){
        return times[i][1] < times[j][1];
    });
 
    int roomID = 0;
    vector<int> roomAllocated(n);
 
    multiset<array<int , 2>> occupied; // {endTime , roomID}
 
    for(int customer : order){
        if(occupied.empty() == false && (*occupied.begin())[0] < times[customer][0]){
            auto it = prev(occupied.lower_bound({times[customer][0] , 0}));
            roomAllocated[customer] = (*it)[1];
            occupied.erase(it);
            occupied.insert({times[customer][1] , roomAllocated[customer]});
 
        }
        else{
            roomID++;
            roomAllocated[customer] = roomID;
            occupied.insert({times[customer][1] , roomID});
        }
    }
 
    cout << roomID << endl;
 
    for(int customer = 0 ; customer < n ; customer++){
      cout << roomAllocated[customer] << " ";
    }
 
    return 0;
}
