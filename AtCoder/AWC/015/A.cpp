#include<bits/stdc++.h>
using namespace std;

int main(){
    valarray<int> a(7) , b(7);

    for(int &num : a) cin >> num;
    for(int &num : b) cin >> num;

    cout << (a * b).sum();

    return 0;
}