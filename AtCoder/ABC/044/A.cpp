#include<bits/stdc++.h>
using namespace std;

int main(){
    int n , k , x , y;
    cin >> n >> k >> x >> y;

    int firstK = min(n , k);
    int remaining = max(0 , n - firstK);

    cout << firstK * x + remaining * y;
    
    return 0;
}