#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int main(){
    int n ; cin >> n;

    vector<int> currRow(n + 1 , 0) , prevRow(n + 1 , 0);
    prevRow[1] = 1; // (or) CurrRow[0] = 1

    for(int r = 1 ; r <= n ; r++){
        string row ; cin >> row;
        for(int col = 1 ; col <= n ; col++){
            if(row[col - 1] == '.'){
                currRow[col] = (currRow[col - 1] + prevRow[col]) % mod;
            }
            else{
                currRow[col] = 0;
            }
        }
        prevRow = currRow;
    }

    cout << currRow[n];

    return 0;
}