#include<bits/stdc++.h>
using namespace std;

int main(){
    int n , k ; cin >> n >> k;

    vector<int> a(n);
    for(int &num : a) cin >> num;

    int ans = -2e9;
    deque<int> mini , maxi;

    for(int i = 0 ; i < n ; i++){
        while(mini.empty() == false && a[i] <= a[mini.back()]) mini.pop_back();
        while(maxi.empty() == false && a[i] >= a[maxi.back()]) maxi.pop_back();

        mini.push_back(i);
        maxi.push_back(i);

        if(i >= k - 1){
            ans = max(ans , a[maxi.front()] - a[mini.front()]);
            if(mini.empty() == false && mini.front() == i - k + 1) mini.pop_front();
            if(maxi.empty() == false && maxi.front() == i - k + 1) maxi.pop_front();
        }
    }

    cout << ans;

    return 0;
}