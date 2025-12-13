#include<bits/stdc++.h>
using namespace std;


int main(){
    int n , m ; cin >> n >> m;

    int blocks = 0;
    set<array<int , 2>> covered;

    while(m--){
        int x , y ; cin >> x >> y;

        if(x == n || y == n) continue;

        int isPlaced = 1;
        for(int dx : {0 , +1}){
            for(int dy : {0 , +1}){
                if(covered.count({x + dx , y + dy})){
                    isPlaced = 0;
                    break;
                }
            }
        }

        if(isPlaced){
            blocks += 1;
            for(int dx : {0 , +1}){
                for(int dy : {0 , +1}){
                    covered.insert({x + dx , y + dy});
                }
            }
        }
    }

    cout << blocks;

    return 0;
}