#include<bits/stdc++.h>
using namespace std;
 
int main(){
    int x , n ; cin >> x >> n;
 
    vector<int> positions(n);
    for(int &pos : positions) cin >> pos;
 
    set<array<int , 2>> dark; // {pos , len} -> [pos + len - 1 , pos]
    dark.insert({0 , 0});
    dark.insert({x , x});
 
    multiset<int> lengths;
    lengths.insert(0);
    lengths.insert(x);
 
    for(int pos : positions){
        auto R = dark.lower_bound({pos , -1});
        auto L = prev(R);
 
        auto [x1 , len1] = *L;
        auto [x2 , len2] = *R;
 
        dark.erase(R);
        lengths.extract(len2);
 
        dark.insert({pos , pos - x1});
        lengths.insert(pos - x1);
 
        dark.insert({x2 , x2 - pos});
        lengths.insert(x2 - pos);
 
        cout << *lengths.rbegin() << " ";
    }
 
    return 0;
}
