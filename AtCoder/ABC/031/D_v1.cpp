#include<bits/stdc++.h>
using namespace std;

int main(){
    int k , n ; cin >> k >> n;

    vector<string> num(n) , word(n);
    for(int i = 0 ; i < n ; i++) cin >> num[i] >> word[i];

    vector<string> digit_mapping(k + 1);

    function<bool(int , int , int)> DFS = [&](int i , int j , int id){
        if(id == n) return true;

        if(i == (int)num[id].size() || j == (int)word[id].size()) return i == (int)num[id].size() && j == (int)word[id].size() && DFS(0 , 0 , id + 1);

        int digit = num[id][i] - '0';

        if(digit_mapping[digit].empty() == false){
            int len = digit_mapping[digit].size();
            string &mapped_word = digit_mapping[digit];
            if(word[id].substr(j , len) == mapped_word) return DFS(i + 1 , j + len , id);
        }
        else{
            for(int len = 1 ; len <= 3 && j + len - 1 < (int)word[id].size() ; len++){
                digit_mapping[digit] = word[id].substr(j , len);
                if(DFS(i + 1 , j + len , id)) return true;
                digit_mapping[digit] = "";
            }
        }

        return false;
    };

    DFS(0 , 0 , 0);

    for(int digit = 1 ; digit <= k ; digit++){
        cout << digit_mapping[digit] << "\n";
    }

    return 0;
}