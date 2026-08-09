#include<bits/stdc++.h>
using namespace std;

int main(){
    int n , m , k;
    cin >> n >> m >> k;

    char c1 , c2 ; cin >> c1 >> c2;

    vector<string> design(n);
    for(string &row : design) cin >> row;

    for(int i = 0 ; i < n * k ; i++){
        for(int j = 0 ; j < m * k ; j++){
            cout << (design[i / k][j / k] == '#' ? c1 : c2);
        }
        cout << "\n";
    }

    return 0;
}