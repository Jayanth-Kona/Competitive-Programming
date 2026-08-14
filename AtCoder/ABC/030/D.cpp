#include<bits/stdc++.h>
using namespace std;

bool isEnough(int initial_dist , string &k){
    string d = to_string(initial_dist);
    return d.size() == k.size() ? d >= k : d.size() > k.size();
}

int modulo(string &k , int mod){
    int rem = 0;
    for(char ch : k) rem = (rem * 10LL + (ch - '0')) % mod;
    return rem;
}

int main(){
    int n , a ; cin >> n >> a;

    string k ; cin >> k;

    vector<int> b(n + 1);
    for(int i = 1 ; i <= n ; i++) cin >> b[i];

    int cycle_start = 0;
    vector<int> path , vis(n + 1 , 0);

    for(int word = a ; !vis[word] ; word = b[word]){
        vis[word] = 1;
        path.push_back(word);
        cycle_start = b[word];
    }

    int path_length = path.size() , cycle_start_index = 0;;
    for(int i = 0 ; i < path_length ; i++){
        if(path[i] == cycle_start){
            cycle_start_index = i;
        }
    }

    int initial_dist = cycle_start_index;
    int cycle_length = path_length - initial_dist;

    if(isEnough(initial_dist , k)){
        cout << path[stoi(k)] << "\n";
    }
    else{
        int mod_k = modulo(k , cycle_length);
        int rem = ((mod_k - initial_dist) % cycle_length + cycle_length) % cycle_length;
        cout << path[cycle_start_index + rem] << "\n";
    }

    return 0;
}