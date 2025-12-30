#include<bits/stdc++.h>
using namespace std;
 
int main(){
    int N , M ; cin >> N >> M;

    multiset<int> ms;
    for(int T = 1 ; T <= N ; T++){
        int num ; cin >> num;
        ms.insert(num);
    }

    for(int T = 1 ; T <= M ; T++){
        int num ; cin >> num;

        if(ms.empty() == false && *ms.begin() <= num){
            int allocate = *prev(ms.upper_bound(num));
            ms.extract(allocate);
            cout << allocate << endl;
        }
        else{
            cout << "-1" << endl;
        }
    }

    return 0;
}
