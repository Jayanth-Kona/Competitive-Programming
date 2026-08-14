#include<bits/stdc++.h>
using namespace std;

int main(){
    int k , n ; cin >> k >> n;

    vector<string> num(n) , word(n);
    for(int i = 0 ; i < n ; i++) cin >> num[i] >> word[i];

    vector<string> digit_mapping(k);

    int total = 1;
    for(int i = 1 ; i <= k ; i++) total *= 3;

    for(int mask = 0 ; mask < total ; mask++){
        vector<int> len(k);
        for(int i = 0 , j = mask ; i < k ; i++){
            len[i] = 1 + (j % 3);
            j /= 3;
        }

        int good = 1;

        for(int i = 0 ; i < n && good ; i++){
            int k = 0;
            
            for(int j = 0 ; j < (int)num[i].size() && good ; j++){
                int digit = num[i][j] - '1';
                if(k + len[digit] - 1 < (int)word[i].size()){
                    if(digit_mapping[digit].empty() == true){
                        digit_mapping[digit] = word[i].substr(k , len[digit]);
                        k += len[digit];
                    }
                    else if(digit_mapping[digit] == word[i].substr(k , len[digit])){
                        k += len[digit];
                    }
                    else{
                        good = 0;
                    }
                }
                else{
                    good = 0;
                }
            }

            if(k != (int)word[i].size()) good = 0;
        }

        if(good){
            break;
        }
        else{
            for(int digit = 0 ; digit < k ; digit++) digit_mapping[digit] = "";
        }
    }

    for(int digit = 0 ; digit < k ; digit++){
        cout << digit_mapping[digit] << "\n";
    }

    return 0;
}