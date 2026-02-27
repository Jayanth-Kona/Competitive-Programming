#include<bits/stdc++.h>
using namespace std;

int main(){
    int n , m , c ; cin >> n >> m >> c;

    vector<int> a(n) , b(m);
    for(int &num : a) cin >> num ; sort(a.begin() , a.end());
    for(int &num : b) cin >> num ; sort(b.begin() , b.end());

    int k = 0;
    
    for(int chef : a) if(k < m && chef >= b[k]) k++;

    cout << k * 1LL * c;

    return 0;
}