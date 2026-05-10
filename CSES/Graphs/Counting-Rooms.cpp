#include<bits/stdc++.h>
using namespace std;
 
int main(){
    int n , m ; cin >> n >> m;
 
    vector<string> grid(n);
    for(string &row : grid) cin >> row;
 
    int delta[5] = {-1 , 0 , +1 , 0 , -1};
 
    auto DFS = [&](auto &&self, int row , int col) -> void{
        grid[row][col] = '#';
        for(int d = 0 ; d < 4 ; d++){
            int newRow = row + delta[d];
            int newCol = col + delta[d + 1];
            if(min(newRow , newCol) >= 0 && newRow < n && newCol < m && grid[newRow][newCol] == '.'){
                self(self , newRow , newCol);
            }
        }
    };
 
    int rooms = 0;
 
    for(int row = 0 ; row < n ; row++){
        for(int col = 0 ; col < m ; col++){
            if(grid[row][col] == '.'){
                rooms++;
                DFS(DFS , row , col);
            }
        }
    }
 
    cout << rooms;
 
    return 0;
}