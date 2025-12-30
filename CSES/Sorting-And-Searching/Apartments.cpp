#include<bits/stdc++.h>
using namespace std;
 
int main(){
    int n , m , k;
    cin >> n >> m >> k;

    vector<int> a(n) , b(m);
    for(int &num : a) cin >> num;
    for(int &num : b) cin >> num;

    sort(a.begin() , a.end());
    sort(b.begin() , b.end());

    int aID = 0 , bID = 0 , fulfilled = 0;

    while(aID < n && bID < m){
        if(a[aID] + k < b[bID]) aID++; // smallest building is larger than applicant's desire
        else if(a[aID] - k > b[bID]) bID++; // requires a larger building to match applicant desire
        else aID++ , bID++ , fulfilled++;
    }

    cout << fulfilled;

    return 0;
}
