#include<bits/stdc++.h>
using namespace std;
using ll = long long;

bool DFS(int i , vector<ll> &weights , vector<ll> &trucks){
    if(i < 0) return true;
    for(int j = 0 ; j < (int)trucks.size() ; j++){
        if(trucks[j] >= weights[i]){
            trucks[j] -= weights[i];
            if(DFS(i - 1 , weights , trucks)){
                trucks[j] += weights[i];
                return true;
            }
            trucks[j] += weights[i];
        }
    }
    return false;
}

int main(){
    int n , m ; cin >> n >> m;

    vector<ll> weights(n) , trucks(m);

    for(ll &weight : weights) cin >> weight;
    for(ll &capacity : trucks) cin >> capacity;

    sort(trucks.rbegin() , trucks.rend());
    sort(weights.begin() , weights.end());

    if(weights.back() <= trucks[0] && accumulate(weights.begin() , weights.end() , 0LL) <= accumulate(trucks.begin() , trucks.end() , 0LL) && DFS(n - 1 , weights , trucks)) cout << "Yes";
    else cout << "No";

    return 0;
}