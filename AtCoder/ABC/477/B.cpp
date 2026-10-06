#include<bits/stdc++.h>
using namespace std;

int main(){
    int n , d ; cin >> n >> d;

    vector<array<int , 2>> A(n);
    for(int i = 0 ; i < n ; i++){
        cin >> A[i][0];
        A[i][1] = i + 1;
    }

    sort(A.begin() , A.end());

    vector<int> ans;

    for(int i = 0 ; i < n ; i++){
        int d1 = i - 1 >= 0 ? A[i][0] - A[i - 1][0] : 1e9;
        int d2 = i + 1 <  n ? A[i + 1][0] - A[i][0] : 1e9;

        if(min(d1 , d2) >= d){
            ans.push_back(A[i][1]);
        }
    }

    sort(ans.begin() , ans.end());

    cout << ans.size() << '\n';
    for(int id : ans) cout << id << " ";

    return 0;
}