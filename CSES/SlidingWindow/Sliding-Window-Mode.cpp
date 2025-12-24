#include<bits/stdc++.h>
using namespace std;
 
int main(){
    int n , k ; cin >> n >> k;
 
    vector<int> x(n);
    for(int &xi : x) cin >> xi;
 
    map<int , int> Freq;
    set<array<int , 2>> mostFrequent;
 
    for(int i = 0 ; i < n ; i++){
        if(Freq[x[i]] > 0) mostFrequent.erase({-Freq[x[i]] , x[i]});
        Freq[x[i]]++;
        mostFrequent.insert({-Freq[x[i]] , x[i]});
        
        if(i >= k - 1){
            cout << (*mostFrequent.begin())[1] << " ";
            mostFrequent.erase({-Freq[x[i - k + 1]] , x[i - k + 1]});
            Freq[x[i - k + 1]]--;
            if(Freq[x[i - k + 1]] > 0) mostFrequent.insert({-Freq[x[i - k + 1]] , x[i - k + 1]});
            else Freq.erase(x[i - k + 1]);
        }
    }
 
    return 0;
}