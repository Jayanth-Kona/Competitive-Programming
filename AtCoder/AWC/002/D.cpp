#include<bits/stdc++.h>
using namespace std;

int main(){
    int n , m ; cin >> n >> m;

    vector<int> a(n) , b(m);
    for(int &num : a) cin >> num ; sort(a.begin() , a.end());
    for(int &num : b) cin >> num ; sort(b.begin() , b.end());

    int lock = 0;
    
    for(int key : b) if(lock < n && a[lock] <= key) lock++;

    cout << lock;

    return 0;
}