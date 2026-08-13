#include<bits/stdc++.h>
using namespace std;

int main(){
    int a , b ; cin >> a >> b;
    int c , d ; cin >> c >> d;

    if(a == c || a == d || b == c || b == d) cout << "YES";
    else cout << "NO";

    return 0;
}