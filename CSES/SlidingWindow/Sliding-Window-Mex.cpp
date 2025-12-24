#include<bits/stdc++.h>
using namespace std;

int main(){
    int n , k ; cin >> n >> k;

    vector<int> x(n);
    for(int &xi : x) cin >> xi;

    set<int> missing;
    for(int num = 0 ; num <= n + 1 ; num++) missing.insert(num);

    map<int , int> Freq;

    for(int i = 0 ; i < n ; i++){
        if(Freq[x[i]]++ == 0 && 0 <= x[i] && x[i] <= n) missing.erase(x[i]);
        
        if(i >= k - 1){
            cout << *missing.begin() << " ";
            
            if(--Freq[x[i - k + 1]] == 0 && 0 <= x[i - k + 1] && x[i - k + 1] <= n){
                missing.insert(x[i - k + 1]);
            }
        }
    }

    return 0;
}