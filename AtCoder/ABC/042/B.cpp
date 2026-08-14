#include<bits/stdc++.h>
using namespace std;

int main(){
    int n , l ; cin >> n >> l;

    vector<string> s(n);
    for(string &si : s) cin >> si;

    sort(s.begin() , s.end() , [&](string &si , string &sj){
        return si + sj < sj + si;
    });

    string mini;
    for(string &si : s) mini += si;

    cout << mini;

    return 0;
}