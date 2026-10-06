#include<bits/stdc++.h>
using namespace std;

int main(){
    int n , q ; cin >> n >> q;

    char lastColor = 'a';
    int lastTime = -1;
    vector<int> isTilePlaced(n , 0) ,  tileRemovedAt(n , 0);

    string ans(n , 'a');

    for(int i = 1 ; i <= q ; i++){
        int t ; cin >> t;

        if(t == 1){
            int x ; cin >> x;
            if(isTilePlaced[x - 1] == 0){
                if(tileRemovedAt[x - 1] <= lastTime) ans[x - 1] = lastColor;
                isTilePlaced[x - 1] = 1;
            }
            else{
                tileRemovedAt[x - 1] = i;
                isTilePlaced[x - 1]  = 0;
            }
        }
        else{
            char color ; cin >> color;
            lastColor = color;
            lastTime = i;
        }
    }

    for(int i = 0 ; i < n ; i++){
        if(isTilePlaced[i] == 0 && tileRemovedAt[i] < lastTime){
            ans[i] = lastColor;
        }
    }

    cout << ans;

    return 0;
}