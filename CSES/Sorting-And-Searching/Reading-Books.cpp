#include<bits/stdc++.h>
using namespace std;

int main(){
    int totalBooks ; cin >> totalBooks;

    vector<int> times(totalBooks);
    for(int &time : times) cin >> time;

    long long maxi = *max_element(times.begin() , times.end());
    long long sum  = accumulate(times.begin() , times.end() , 0LL);

    if(sum - maxi >= maxi){
        cout << sum;
    }
    else{
        cout << (maxi + maxi);
    }

    return 0;
}