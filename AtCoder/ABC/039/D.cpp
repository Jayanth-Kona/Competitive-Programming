#include<bits/stdc++.h>
using namespace std;

int main(){
    int n , m ; cin >> n >> m;

    vector<string> image(n);
    for(string &row : image) cin >> row;

    vector<string> original(n , string(m , '#'));
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            if(image[i][j] == '.'){
                for(int di = -1 ; di <= +1 ; di++){
                    for(int dj = -1 ; dj <= +1 ; dj++){
                        int ni = i + di;
                        int nj = j + dj;
                        if(min(ni , nj) >= 0 && ni < n && nj < m){
                            original[ni][nj] = '.';
                        }
                    }
                }
            }
        }
    }

    vector<string> changedTo(n , string(m , '.'));
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            bool hasBlack = false;
            for(int di = -1 ; di <= +1 ; di++){
                for(int dj = -1 ; dj <= +1 ; dj++){
                    int ni = i + di;
                    int nj = j + dj;
                    if(min(ni , nj) >= 0 && ni < n && nj < m && original[ni][nj] == '#'){
                        hasBlack = true;
                    }
                }
            }
            if(hasBlack) changedTo[i][j] = '#';
        }
    }

    if(image == changedTo){
        cout << "possible\n";
        for(string &row : original) cout << row << "\n";
    }
    else{
        cout << "impossible\n";
    }
    
    return 0;
}