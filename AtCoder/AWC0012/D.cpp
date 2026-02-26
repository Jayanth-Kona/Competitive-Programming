#include<bits/stdc++.h>
using namespace std;

int main(){
    int n , m ; cin >> n >> m;

    vector<string> grid(n);
    for(string &row : grid) cin >> row;

    int dir[5] = {-1 , 0 , +1 , 0 , -1};

    vector<vector<int>> cost(n , vector<int>(m , 1e9));

    using node = array<int , 3>;
    priority_queue<node , vector<node> , greater<node>> minHeap;
    minHeap.push({cost[0][0] = 0 , 0 , 0});

    while(minHeap.empty() == false){
        auto [destroyed , row , col] = minHeap.top();
        minHeap.pop();

        if(row == n - 1 && col == m - 1){
            cout << destroyed;
            return 0;
        }

        for(int d = 0 ; d < 4 ; d++){
            int nrow = row + dir[d + 0];
            int ncol = col + dir[d + 1];
            if(0 <= min(nrow , ncol) && nrow < n && ncol < m){
                int ndestroyed = destroyed + (grid[nrow][ncol] == '#');
                if(ndestroyed < cost[nrow][ncol]) minHeap.push({cost[nrow][ncol] = ndestroyed , nrow , ncol});
            }
        }
    }

    return 0;
}