#include<bits/stdc++.h>
using namespace std;
 
int main(){
    int N ; cin >> N;

    vector<array<int , 2>> movies(N);
    for(auto &[startTime , endTime] : movies) cin >> startTime >> endTime;

    sort(movies.begin() , movies.end() , [&](array<int , 2> &m1 , array<int , 2> &m2){
        return m1[1] < m2[1];
    });

    int moviesWatched = 1 , lastMovie = 0;

    for(int currentMovie = 1 ; currentMovie < N ; currentMovie++){
        if(movies[lastMovie][1] <= movies[currentMovie][0]){
            lastMovie = currentMovie;
            moviesWatched++;  
        } 
    }

    cout << moviesWatched;

    return 0;
}
