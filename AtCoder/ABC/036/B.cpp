#include<bits/stdc++.h>
using namespace std;

int main(){
    int n ; cin >> n;

    vector<string> grid(n);
    for(string &row : grid) cin >> row;

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < i ; j++){
            swap(grid[i][j] , grid[j][i]);
        }
    }

    for(string &row : grid){
        reverse(row.begin() , row.end());
        cout << row << "\n";
    }

    return 0;
}