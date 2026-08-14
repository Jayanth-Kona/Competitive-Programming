#include<bits/stdc++.h>
using namespace std;

/*

Source: Submissions Page + DeepSeek
Reason: Question was in chinese (Translator was not clear) + Problem is doable

*/

int main(){
    int n ; cin >> n;

    vector<int> a(n);
    for(int &num : a) cin >> num;

    int best_taka = -1e9;
    
    for(int i = 0 ; i < n ; i++){
        int best_aoki = -1e9;
        int curr_taka = 0;

        for(int j = 0 ; j < n ; j++){
            if(i != j){
                int aoki = 0 , taka = 0;

                for(int k = min(i , j) ; k <= max(i , j) ; k++){
                    if((k - min(i , j)) % 2 == 0) taka += a[k];
                    else aoki += a[k];
                }

                if(aoki > best_aoki){
                    best_aoki = aoki;
                    curr_taka = taka;
                }
            }
        }

        best_taka = max(best_taka , curr_taka);
    }

    cout << best_taka << "\n";

    return 0;
}