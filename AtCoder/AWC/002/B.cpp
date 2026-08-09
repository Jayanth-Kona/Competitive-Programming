#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int n , m , k ; cin >> n >> m >> k;

    vector<int> sweetness(n);
    for(int &num : sweetness) cin >> num;

    ll shipped = 0 , totalSweetness = 0;

    for(int i = 1 ; i <= m ; i++){
        int index ; cin >> index;
        if(sweetness[index - 1] < k){
            shipped += 1;
            totalSweetness += sweetness[index - 1];
        }
    }

    cout << shipped << " " << totalSweetness;

    return 0;
}