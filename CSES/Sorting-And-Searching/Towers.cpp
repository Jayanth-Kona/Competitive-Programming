#include<bits/stdc++.h>
using namespace std;
 
int main(){
    int N ; cin >> N;

    vector<int> cubeTops;

    for(int T = 1 ; T <= N ; T++){
        int tower ; cin >> tower;

        if(cubeTops.empty() == true || tower >= cubeTops.back()){
            cubeTops.push_back(tower);
        }
        else{
            // find the cup on which you can be placed, i.e cubeTops[i] > tower --> so use upper_bound
            *(upper_bound(cubeTops.begin() , cubeTops.end() , tower)) = tower;
        }
    }

    cout << cubeTops.size();

    return 0;
}