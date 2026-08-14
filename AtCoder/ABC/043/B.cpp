#include<bits/stdc++.h>
using namespace std;

int main(){
    string s ; cin >> s;

    string output;
    for(char ch : s){
        if(ch == '0' || ch == '1') output.push_back(ch);
        else if(output.empty() == false) output.pop_back();
    }

    cout << output;

    return 0;
}