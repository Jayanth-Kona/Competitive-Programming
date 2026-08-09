#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int n , k , m ; cin >> n >> k >> m;

    vector<int> exp , beg;
    for(int i = 1 ; i <= n ; i++){
        int h , p ; cin >> h >> p;
        if(h == 1) exp.push_back(p);
        else beg.push_back(p);
    }

    if(exp.size() >= m && beg.size() >= k - m){
        sort(exp.rbegin() , exp.rend());
        sort(beg.rbegin() , beg.rend());
        ll tot = 0;
        tot += accumulate(exp.begin() , exp.begin() + m , 0LL);
        tot += accumulate(beg.begin() , beg.begin() + k - m , 0LL);
        cout << tot;
    }
    else{
        cout << "-1";
    }

    return 0;
}