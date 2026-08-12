#include<bits/stdc++.h>
using namespace std;

int main(){
    int N ; cin >> N;

    vector<array<int , 2>> intervals;

    for(int i = 0 ; i < N ; i++){
        string s ; cin >> s;

        int start = stoi(s.substr(0 , 4));
        int end = stoi(s.substr(5 , 4));

        int start_minutes = start % 100;
        int start_hour = start / 100;
        int rounded_start = (start_hour * 60 + start_minutes) / 5 * 5;

        int end_minutes = end % 100;
        int end_hour = end / 100;
        int rounded_end = (end_hour * 60 + end_minutes + 4) / 5 * 5;

        intervals.push_back({rounded_start , rounded_end});
    }

    sort(intervals.begin() , intervals.end());

    vector<array<int , 2>> merged;
    for(auto [start , end] : intervals){
        if(merged.empty()){
            merged.push_back({start , end});
        }
        else{
            auto &last = merged.back();
            if(start <= last[1]){
                last[1] = max(last[1] , end);
            }
            else{
                merged.push_back({start , end});
            }
        }
    }

    for(auto [start , end] : merged){
        int start_hour = start / 60;
        int start_min = start % 60;
        int end_hour = end / 60;
        int end_min = end % 60;

        printf("%02d%02d-%02d%02d\n" , start_hour , start_min , end_hour , end_min);
    }

    return 0;
}