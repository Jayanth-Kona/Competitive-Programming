#include<bits/stdc++.h>
using namespace std;
 
int main(){
    int totalSongs ; cin >> totalSongs;

    vector<int> songs(totalSongs);
    for(int &song : songs) cin >> song;

    int maxUniqueSongs = 0;
    map<int , int> seenAt;

    for(int L = 0 , R = 0 ; R < totalSongs ; R++){
        if(seenAt.count(songs[R])) L = max(L , 1 + seenAt[songs[R]]);
        maxUniqueSongs = max(maxUniqueSongs , R - L + 1);
        seenAt[songs[R]] = R;
    }

    cout << maxUniqueSongs;

    return 0;
}
