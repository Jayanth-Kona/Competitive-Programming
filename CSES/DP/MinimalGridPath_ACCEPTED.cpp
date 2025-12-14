#include<bits/stdc++.h>
using namespace std;

int main(){
    int n ; cin >> n;

    vector<string> grid(n);
    for(string &row : grid) cin >> row;

    string minimalString;
    char previous_level_min = grid[0][0];

    vector<vector<int>> valid(n , vector<int>(n , 0));

    for(int startRow = 0 ; startRow < n ; startRow++){

        char curr_level_min = 'Z';

        int row = startRow;
        int col = 0;

        // find minimum in current level : if parent is minimum and valid
        while(row >= 0 && col < n){
            if((row == 0 && col == 0) || (row - 1 >= 0 && grid[row - 1][col] == previous_level_min && valid[row - 1][col]) || (col - 1 >= 0 && grid[row][col - 1] == previous_level_min && valid[row][col - 1])){
                curr_level_min = min(curr_level_min , grid[row][col]);
            }
            row--;
            col++;
        }

        row = startRow;
        col = 0;

        // is current cell : minimal and valid ??
        while(row >= 0 && col < n){
            if((row == 0 && col == 0) || (row - 1 >= 0 && grid[row - 1][col] == previous_level_min && valid[row - 1][col]) || (col - 1 >= 0 && grid[row][col - 1] == previous_level_min && valid[row][col - 1])){
                if(grid[row][col] == curr_level_min){
                    valid[row][col]  = 1;
                }
            }
            row--;
            col++;
        }

        minimalString.push_back(curr_level_min);
        previous_level_min = curr_level_min;
    }

    for(int startCol = 1 ; startCol < n ; startCol++){

        char curr_level_min = 'Z';

        int row = n - 1;
        int col = startCol;

        // find minimum in current level : if parent is minimum and valid
        while(row >= 0 && col < n){
            if((row - 1 >= 0 && grid[row - 1][col] == previous_level_min && valid[row - 1][col]) || (col - 1 >= 0 && grid[row][col - 1] == previous_level_min && valid[row][col - 1])){
                curr_level_min = min(curr_level_min , grid[row][col]);
            }
            row--;
            col++;
        }

        row = n - 1;
        col = startCol;
        
        // is current cell : minimal and valid ??
        while(row >= 0 && col < n){
            if((row - 1 >= 0 && grid[row - 1][col] == previous_level_min && valid[row - 1][col]) || (col - 1 >= 0 && grid[row][col - 1] == previous_level_min && valid[row][col - 1])){
                if(grid[row][col] == curr_level_min) valid[row][col] = 1;
            }
            row--;
            col++;
        }

        minimalString.push_back(curr_level_min);
        previous_level_min = curr_level_min;
    }

    // can trace path
    // for(int i = 0 ; i < n ; i++){
    //     for(int j = 0 ; j < n ; j++)  cout << valid[i][j] << " ";
    //     cout << endl;
    // }

    cout << minimalString;

    return 0;
}