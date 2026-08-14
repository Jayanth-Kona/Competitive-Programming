#include<bits/stdc++.h>
using namespace std;

int main(){
    int n ; cin >> n;

    int total = 0;
    vector<pair<string , int>> humans(n);

    for(auto &[name , count] : humans){
        cin >> name >> count;
        total += count;
    }

    for(auto &[name , count] : humans){
        if(2 * count > total){
            cout << name << "\n";
            return 0;
        }
    }

    cout << "atcoder\n";

    return 0;
}