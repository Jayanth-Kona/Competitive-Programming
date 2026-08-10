#include<bits/stdc++.h>
using namespace std;

int main(){
    int n ; cin >> n;

    vector<int> a(n);
    for(int &num : a) cin >> num;

    int removed = 0 , suffixmax = a[n - 1];
    
    for(int i = n - 2 ; i >= 0 ; i--){
        removed += suffixmax > a[i];
        suffixmax = max(suffixmax , a[i]);
    }

    cout << n - removed;

    return 0;
}