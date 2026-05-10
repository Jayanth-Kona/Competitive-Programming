#include<bits/stdc++.h>
using namespace std;
 
int main(){
    int n , m ; cin >> n >> m;
 
    vector<string> grid(n);
    for(string &row : grid) cin >> row;
 
    queue<array<int , 2>> queue;
    vector<vector<int>> byMachine(n , vector<int>(m , 1e9));
 
    int Ax , Ay;
 
    for(int row = 0 ; row < n ; row++){
        for(int col = 0 ; col < m ; col++){
            if(grid[row][col] == 'M'){
                queue.push({row , col});
                byMachine[row][col] = 0;
            }
            if(grid[row][col] == 'A'){
                Ax = row;
                Ay = col;
            }
        }
    }
 
    int delta[5] = {-1 , 0 , +1 , 0 , -1};
    char dir[4] = {'U' , 'R' , 'D' , 'L'};
 
    for(int T = 1 ; queue.empty() == false ; T++){
        int k = queue.size();
 
        while(k--){
            array<int , 2> u = queue.front();
            queue.pop();
 
            for(int d = 0 ; d < 4 ; d++){
                int row = u[0] + delta[d];
                int col = u[1] + delta[d + 1];
                if(min(row , col) >= 0 && row < n && col < m && grid[row][col] == '.' && byMachine[row][col] == 1e9){
                    queue.push({row , col});
                    byMachine[row][col] = T;
                }
            }
        }
 
    }
 
    queue.push({Ax , Ay});
    vector<vector<int>> parent(n , vector<int>(m , -1));
 
    for(int T = 1 ; queue.empty() == false ; T++){
        int k = queue.size();
 
        while(k--){
            array<int , 2> u = queue.front();
            queue.pop();
 
            if(u[0] == 0 || u[0] == n - 1 || u[1] == 0 || u[1] == m - 1){
                string path;
 
                while(!(u[0] == Ax && u[1] == Ay)){
                    int d = parent[u[0]][u[1]];
                    path.push_back(d);
                    u[0] -= delta[d];
                    u[1] -= delta[d + 1];
                }
 
                reverse(path.begin() , path.end());
                cout << "YES\n" << path.size() << "\n";
                for(int d : path) cout << dir[d];
 
                return 0;
            }
 
            for(int d = 0 ; d < 4 ; d++){
                int row = u[0] + delta[d];
                int col = u[1] + delta[d + 1];
                if(min(row , col) >= 0 && row < n && col < m && grid[row][col] == '.' && T < byMachine[row][col] && parent[row][col] == -1){
                    parent[row][col] = d;
                    queue.push({row , col});
                }
            }
        }
 
    }
 
    cout << "NO";
 
    return 0;
}