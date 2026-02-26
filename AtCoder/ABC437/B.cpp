#include<bits/stdc++.h>
using namespace std;

int main(){
    int rows , cols , nvals;
    cin >> rows >> cols >> nvals;

    vector<int> rowNumber(100,  -1);
    for(int row = 0 ; row < rows ; row++){
        for(int col = 0 ; col < cols ; col++){
            int val ; cin >> val;
            rowNumber[val] = row;
        }
    }

    int maxRows = 0;
    vector<int> rowCount(rows , 0);

    while(nvals--){
        int val ; cin >> val;
        if(rowNumber[val] != -1){
            maxRows = max(maxRows , ++rowCount[rowNumber[val]]);
        }
    }

    cout << maxRows;

    return 0;
}