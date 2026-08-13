#include<bits/stdc++.h>
using namespace std;

int main(){
    string s ; cin >> s;
    int T ; cin >> T;

    int adjust = 0;
    int dx = 0 ,  dy = 0;

    for(char dir : s){
        if(dir == 'L') dx -= 1;
        else if(dir == 'R') dx += 1;
        else if(dir == 'U') dy += 1;
        else if(dir == 'D') dy -= 1;
        else adjust += 1;
    }

    int dxy = abs(dx) + abs(dy);

    if(T == 1){
        cout << dxy + adjust;
    }
    else{
        if(adjust <= dxy) cout << dxy - adjust;
        else cout << (adjust - dxy) % 2;
    }
    
    cout << "\n";

    return 0;
}