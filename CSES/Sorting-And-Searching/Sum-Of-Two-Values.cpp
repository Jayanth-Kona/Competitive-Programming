#include<bits/stdc++.h>
using namespace std;
 
int main(){
    int n , sum ; cin >> n >> sum;

    map<int , int> map;

    for(int pos = 1 ; pos <= n ; pos++){
        int num ; cin >> num;
        if(map.count(sum - num)){
            cout << map[sum - num] << " " << pos;
            return 0;
        }
        else{
            map[num] = pos;
        }
    }

    cout << "IMPOSSIBLE";

    return 0;
}
