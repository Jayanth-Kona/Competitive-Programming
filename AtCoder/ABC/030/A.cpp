#include<bits/stdc++.h>
using namespace std;

int main(){
    int a , b , c , d;
    cin >> a >> b >> c >> d;

    if(b * c == a * d) cout << "DRAW\n";
    else if(b * c > a * d) cout << "TAKAHASHI\n";
    else cout << "AOKI\n";

    return 0;
}