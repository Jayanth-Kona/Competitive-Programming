#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll h , w , n;
    cin >> h >> w >> n;

    ll freq[10]{};
    freq[0] = (h - 2) * (w - 2);

    map<array<int , 2> , int> blackCellsCount;

    for(int i = 1 ; i <= n ; i++){
        int x , y ; cin >> x >> y;

        for(int dx = -2 ; dx <= 0 ; dx++){
            for(int dy = -2 ; dy <= 0 ; dy++){
                int nx = x + dx;
                int ny = y + dy;
                if(min(nx , ny) >= 1 && nx + 2 <= h && ny + 2 <= w){
                    freq[blackCellsCount[{nx , ny}]] -= 1;
                    blackCellsCount[{nx , ny}] += 1;
                    freq[blackCellsCount[{nx , ny}]] += 1;
                }
            }
        }
    }
    
    for(int count = 0 ; count <= 9 ; count++){
        cout << freq[count] << "\n";
    }

    return 0;
}