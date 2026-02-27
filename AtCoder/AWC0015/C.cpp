#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int n ; cin >> n;

    map<int , int> p;
    map<array<int , 2> , int> pq;

    ll pairs = 0;

    for(int i = 1 ; i <= n ; i++){
        int pi , qi ; cin >> pi >> qi;

        ll total = p[pi]++;
        ll exclude = pq[{pi , qi}]++;

        pairs += (total - exclude);
    }

    cout << pairs;

    return 0;
}


/*


Another approach:

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int n ; cin >> n;

    vector<array<int , 2>> pq(n);
    for(auto &[p , q] : pq) cin >> p >> q;

    sort(pq.begin() , pq.end());

    ll pairs = 0;
    
    for(int i = 0 , j = 0 ; i < n ; i = j){
        int sport = pq[i][0] , diffTeam = 0;

        while(j < n && sport == pq[j][0]){

            int team = pq[j][1] , currTeam = 0;
            while(j < n && sport == pq[j][0] && team == pq[j][1]){
                j++;
                currTeam++;
            }

            pairs += diffTeam * 1LL * currTeam;
            diffTeam += currTeam;
        }
    }

    cout << pairs;

    return 0;
}

*/