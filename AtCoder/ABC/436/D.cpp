#include<bits/stdc++.h>
using namespace std;


int main(){
    int n , m ; cin >> n >> m;

    vector<string> grid(n);
    for(string &row : grid) cin >> row;

    vector<vector<array<int , 2>>> wrap(26);
    for(int row = 0 ; row < n ; row++){
        for(int col = 0 ; col < m ; col++){
            if(isalpha(grid[row][col])){
                wrap[grid[row][col] - 'a'].push_back({row , col});
            }
        }
    }

    int delta[5] = {-1 , 0 , +1 , 0 , -1};

    vector<vector<int>> minDist(n , vector<int>(m , 1e9));

    queue<array<int , 3>> Queue;
    Queue.push({minDist[0][0] = 0 , 0 , 0});


    while(Queue.empty() == false){
        auto [dist , row , col] = Queue.front();
        Queue.pop();

        if(row == n - 1 && col == m - 1){
            cout << dist;
            return 0;
        }

        if(isalpha(grid[row][col])){
            int cell = grid[row][col] - 'a';
            while(wrap[cell].empty() == false){
                int newRow = wrap[cell].back()[0];
                int newCol = wrap[cell].back()[1];
                if(1 + dist < minDist[newRow][newCol]){
                    Queue.push({minDist[newRow][newCol] = 1 + dist , newRow , newCol});
                }
                wrap[cell].pop_back();
            }
        }

        for(int k = 0 ; k < 4 ; k++){
            int newRow = row + delta[k];
            int newCol = col + delta[k + 1];
            if(min(newRow , newCol) >= 0 && newRow < n && newCol < m && grid[newRow][newCol] != '#' && 1 + dist < minDist[newRow][newCol]){
                Queue.push({minDist[newRow][newCol] = 1 + dist , newRow , newCol});
            }
        }

    }

    cout << "-1";


    return 0;
}