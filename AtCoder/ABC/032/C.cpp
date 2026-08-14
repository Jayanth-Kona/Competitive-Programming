#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int n , k ; cin >> n >> k;

    vector<int> a(n);
    for(int &num : a) cin >> num;

    int z = count(a.begin() , a.end() , 0);

    if(k == 0 || z > 0){
        if(z > 0) cout << n << "\n";
        else cout << "0\n";
    }
    else{
        int ans = 0;
        ll prod = 1;

        for(int i = 0 , j = 0 ; j < n ; j++){
            prod *= a[j];
            while(prod > k) prod /= a[i++];
            ans = max(ans , j - i + 1);
        }

        cout << ans << "\n";
    }

    return 0;
}