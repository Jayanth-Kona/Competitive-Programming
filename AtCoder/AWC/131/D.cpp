#include<bits/stdc++.h>
using namespace std;

int main(){
    int n , q , m;
    cin >> n >> q >> m;

    vector<int> a(n + 1);
    for(int i = 1 ; i <= n ; i++) cin >> a[i];


    vector<int> p(n + 2 , 1) , s(n + 2 , 1);
    for(int i = 1 , j = n ; i <= n ; i++ , j--){
        p[i] = p[i - 1] * 1LL * a[i] % m;
        s[j] = s[j + 1] * 1LL * a[j] % m;
    }

    for(int i = 1 ; i <= q ; i++){
        int x , v ; cin >> x >> v;
        cout << (p[x - 1] * 1LL * s[x + 1] % m * 1LL * v % m) << "\n";
    }

    return 0;
}