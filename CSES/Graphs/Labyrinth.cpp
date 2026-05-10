#include<bits/stdc++.h>
using namespace std;
 
int main(){
    int n , m ; cin >> n >> m;
 
    vector<string> grid(n);
    for(string &row : grid) cin >> row;
 
    
    vector<vector<int>> parent(n , vector<int>(m , 4));
 
    queue<array<int , 2>> queue;
    for(int row = 0 ; row < n ; row++){
        for(int col = 0 ; col < m ; col++){
            if(grid[row][col] == 'A'){
                queue.push({row , col});
                row = n;
                col = m;
            }
        }
    }
 
    int delta[5] = {-1 , 0 , +1 , 0 , -1};
    char dir[4] = {'U' , 'R' , 'D' , 'L'};
 
    for(int level = 0 ; queue.empty() == false ; level++){
        int k = queue.size();
 
        while(k--){
            array<int , 2> u = queue.front();
            queue.pop();
 
            if(grid[u[0]][u[1]] == 'B'){
                cout << "YES\n" << level << "\n";
                vector<int> path;
                while(grid[u[0]][u[1]] != 'A'){
                    int index = parent[u[0]][u[1]];
                    path.push_back(index);
                    u[0] -= delta[index];
                    u[1] -= delta[index + 1];
                }
                reverse(path.begin() , path.end());
                for(int index : path) cout << dir[index];
                return 0;
            }
 
            for(int index = 0 ; index < 4 ; index++){
                int row = u[0] + delta[index];
                int col = u[1] + delta[index + 1];
                if(min(row , col) >= 0 && row < n && col < m && grid[row][col] != '#' && parent[row][col] == 4){
                    parent[row][col] = index;
                    queue.push({row , col});
                }
            }
        }
 
    }
 
    cout << "NO";
 
    return 0;
}