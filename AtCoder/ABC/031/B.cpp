#include<bits/stdc++.h>
using namespace std;

int main(){
    int a , b ; cin >> a >> b;

    int q ; cin >> q;

    for(int i = 1 ; i <= q ; i++){
        int num ; cin >> num;        
        if(num < a) cout << a - num << "\n";
        else if(num > b) cout << "-1\n";
        else cout << "0\n";
    }

    return 0;
}