#include<bits/stdc++.h>
using namespace std;

int main(){
    string deck[3];
    cin >> deck[0] >> deck[1] >> deck[2];

    for(int d : {0 , 1 , 3}) reverse(deck[d].begin() , deck[d].end());

    int turn = 0;
    while(deck[turn].empty() == false){
        int next_turn = deck[turn].back() - 'a';
        deck[turn].pop_back();
        turn = next_turn;
    }

    cout << char('A' + turn);

    return 0;
}