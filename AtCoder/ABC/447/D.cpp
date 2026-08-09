#include<bits/stdc++.h>
using namespace std;

int main(){
    string S ; cin >> S;

    vector<int> A , B , C;

    for(int i = 0 ; i < (int)S.size() ; i++){
        if(S[i] == 'A') A.push_back(i);
        else if(S[i] == 'B') B.push_back(i);
        else if(S[i] == 'C') C.push_back(i);
    }

    int ans = 0;

    while(A.empty() == false && B.empty() == false && C.empty() == false){
        
        while(B.empty() == false && B.back() > C.back()) B.pop_back();
        if(B.empty()) break;

        while(A.empty() == false && A.back() > B.back()) A.pop_back();
        if(A.empty()) break;

        ans++;
        
        A.pop_back();
        B.pop_back();
        C.pop_back();
    }

    cout << ans;

    return 0;
}