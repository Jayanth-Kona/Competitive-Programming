#include<bits/stdc++.h>
using namespace std;

int main(){
    int n , m ; cin >> n >> m;

    vector<vector<int>> cuts(n + 1 , vector<int>(m + 1));

    for(int length = 1 ; length <= n ; length++){
        for(int width = 1 ; width <= m ; width++){
            if(length == width){
                cuts[length][width] = 0;
                continue;
            }
            else{
                cuts[length][width] = 1e9;

                for(int hCut = 1 ; hCut < length ; hCut++){
                    int cutsReqd = 1 + cuts[hCut][width] + cuts[length - hCut][width];
                    cuts[length][width] = min(cuts[length][width] , cutsReqd);
                }

                for(int vCut = 1 ; vCut < width ; vCut++){
                    int cutsReqd = 1 + cuts[length][vCut] + cuts[length][width - vCut];
                    cuts[length][width] = min(cuts[length][width] , cutsReqd);
                }
            }
        }
    }

    cout << cuts[n][m];

    return 0;
}
