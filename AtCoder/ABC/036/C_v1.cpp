#include<bits/stdc++.h>
using namespace std;

int main(){
    int n ; cin >> n;

    vector<int> a(n);
    for(int &num : a) cin >> num;

    int id = 0;
    map<int , int> map;
    for(int num : set<int>(a.begin() , a.end())) map[num] = id++;

    for(int num : a) cout << map[num] << "\n";

    return 0;
}