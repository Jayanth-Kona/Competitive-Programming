#include<bits/stdc++.h>
using namespace std;

int main(){
    int totalBooks , maxPrice;
    cin >> totalBooks >> maxPrice;

    vector<int> prices(totalBooks) , pages(totalBooks);

    for(int &price : prices) cin >> price;
    for(int &page : pages) cin >> page;

    vector<int> maxPages(maxPrice + 1 , 0);

    for(int book = 0 ; book < totalBooks ; book++){
        for(int price = maxPrice ; price >= prices[book] ; price--){
            maxPages[price] = max(maxPages[price] , pages[book] + maxPages[price - prices[book]]);
        }
    }

    cout << maxPages[maxPrice];

    return 0;
}