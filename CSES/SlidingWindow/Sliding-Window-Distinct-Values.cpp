#include<bits/stdc++.h>
using namespace std;

int main(){
    int n , k ; cin >> n >> k;

    vector<int> x(n);
    for(int &xi : x) cin >> xi;

    map<int , int> Freq;

    for(int i = 0 ; i < n ; i++){
        Freq[x[i]]++;
        if(i >= k - 1){
            cout << Freq.size() << " ";
            if(--Freq[x[i - k + 1]] == 0) Freq.erase(x[i - k + 1]);
        }
    }

    return 0;
}