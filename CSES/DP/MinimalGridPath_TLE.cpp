#include<bits/stdc++.h>
using namespace std;

int main(){
    int n ; cin >> n;

    vector<string> grid(n);
    for(string &row : grid) cin >> row;

    string minimalString;
    char previous_level_min = grid[0][0];

    queue<array<int , 2>> queue;
    queue.push({0 , 0});

    for(int level = 1 ; level <= n + n - 1 ; level++){
        minimalString.push_back(previous_level_min);

        int levelsize = queue.size();
        char next_level_min = 'Z';

        for(int size = 1 ; size <= levelsize ; size++){
            auto [row , col] = queue.front();
            queue.pop();

            if(grid[row][col] == previous_level_min){
                if(row + 1 < n){
                    queue.push({row + 1 , col});
                    next_level_min = min(next_level_min , grid[row + 1][col]);
                }
                if(col + 1 < n){
                    queue.push({row , col + 1});
                    next_level_min = min(next_level_min , grid[row][col + 1]);
                }
            }
        }
        
        previous_level_min = next_level_min;
    }

    cout << minimalString;

    return 0;
}