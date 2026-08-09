#include<bits/stdc++.h>
using namespace std;


int main(){
    int n ; cin >> n;

    vector<vector<int>> a(n , vector<int>(n , -1));
    a[0][(n - 1) / 2] = 1;

    int r = 0 , c = (n - 1) / 2;
    for(int t = 1 ; t <= n * n - 1 ; t++){
        int nr = (r + n - 1) % n;
        int nc = (c + 1) % n;
        if(a[nr][nc] != -1){
            nr = (r + 1) % n;
            nc = c;
        }
        a[nr][nc] = t + 1;
        r = nr;
        c = nc;
    }

    for(vector<int> &row : a){
        for(int col : row) cout << col << " ";
        cout << endl;
    }

    return 0;
}