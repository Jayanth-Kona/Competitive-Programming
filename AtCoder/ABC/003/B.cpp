#include<bits/stdc++.h>
using namespace std;

int main(){
    string a , b ; cin >> a >> b;

    int good = 1;
    for(int i = 0 ; i < (int)a.size() ; i++){
        if(a[i] != b[i]){
            if(a[i] == '@'){
                if(!(b[i] == 'a' || b[i] == 't' || b[i] == 'c' || b[i] == 'o' || b[i] == 'd' || b[i] == 'e' || b[i] == 'r')){
                    good = 0;
                    break;
                }
            }
            else if(b[i] == '@'){
                if(!(a[i] == 'a' || a[i] == 't' || a[i] == 'c' || a[i] == 'o' || a[i] == 'd' || a[i] == 'e' || a[i] == 'r')){
                    good = 0;
                    break;
                }
            }
            else{
                good = 0;
                break;
            }
        }
    }

    if(good) cout << "You can win\n";
    else cout << "You will lose\n";

    return 0;
}