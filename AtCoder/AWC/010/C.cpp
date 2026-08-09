#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int n , k , q ; cin >> n >> k >> q;

    vector<int> a(n) , b(n);
    for(int &num : a) cin >> num;

    for(int i = 0 , j = 0 ; i < n ; i = j){
        b[j++] = i;
        while(j < n && abs(a[j] - a[j - 1]) <= k) b[j++] = i;
    }

    for(int i = 1 ; i <= q ; i++){
        int l , r ; cin >> l >> r;
        cout << (b[l - 1] == b[r - 1] ? "Yes" : "No") << "\n "[i == q];
    }


    return 0;
}