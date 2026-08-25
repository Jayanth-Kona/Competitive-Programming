#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int n , m , k , q;
    cin >> n >> m >> k >> q;

    map<int , vector<int>> stores;

    for(int i = 1 ; i <= n ; i++){
        int price , store;
        cin >> price >> store;
        stores[store].push_back(price);
    }

    priority_queue<array<ll , 2>> maxHeap;

    for(int i = 1 ; i <= q ; i++){
        int store ; cin >> store;
        if(stores.count(store)){
            sort(stores[store].begin() , stores[store].end());
            maxHeap.push({stores[store].back() , store});
        }
    }

    ll ans = 0;

    for(int items = 1 ; items <= k && maxHeap.empty() == false ; items++){
        auto [price , store] = maxHeap.top();
        maxHeap.pop();

        ans += price;
        stores[store].pop_back();

        if(stores[store].empty() == false){
            maxHeap.push({stores[store].back() , store});
        }
        else{
            stores.erase(store);
        }
    }

    cout << ans;

    return 0;
}