#include<bits/stdc++.h>
using namespace std;
 
int main(){
    int n ; cin >> n;
 
    vector<array<int , 3>> ranges(n);
    for(int i = 0 ; i < n ; i++){
        cin >> ranges[i][0] >> ranges[i][1];
        ranges[i][2] = i;
    }
 
 
    // Is any range inside me !?
    {
        sort(ranges.begin() , ranges.end() , [&](array<int , 3> &r1 , array<int , 3> &r2){
            return r1[1] == r2[1] ? r1[0] > r2[0] : r1[1] < r2[1];
        });
 
        int rightmost_start = 0;
        vector<int> Anyone_inside_me(n , 0);
 
        for(auto [start , end , index] : ranges){
            if(start <= rightmost_start) Anyone_inside_me[index] = 1;
            rightmost_start = max(rightmost_start , start);
        }
 
        for(int status : Anyone_inside_me) cout << status << " " ;
        cout << endl;
    }
 
 
 
    // Am I inside any range !?
    {
        sort(ranges.begin() , ranges.end() , [&](array<int , 3> &r1 , array<int , 3> &r2){
            return r1[0] == r2[0] ? r1[1] > r2[1] : r1[0] < r2[0];
        });
 
        int rightmost_end = 0;
        vector<int> Am_I_inside_anyone(n , 0);
 
        for(auto [start , end , index] : ranges){
            if(end <= rightmost_end) Am_I_inside_anyone[index] = 1;
            rightmost_end = max(rightmost_end , end);
        }
 
        for(int status : Am_I_inside_anyone) cout << status << " " ;
    }

    
    return 0;
}