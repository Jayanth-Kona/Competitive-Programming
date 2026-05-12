#include <bits/stdc++.h>
using namespace std;
using ll = long long;

class Node{
public:
    ll sum;
    ll ways;
    bool done;
    
public:
    Node(ll s = 0 , ll w = 0 , bool d = false){
        sum = s;
        ways = w;
        done = d;
    }
};

class solution{
private:
    Node DP[20][2];
    
    Node DFS(string &num , int pos = 0 , int t = 1){
        if(pos == num.size()) return Node(0 , 1);
        
        Node &parent = DP[pos][t];
        if(parent.done) return parent;
        
        int limit = t ? num[pos] - '0' : 9;
        for(int d = 0 ; d <= limit ; d++){
            Node child = DFS(num , pos + 1 , t & (d == limit));
            parent.ways += child.ways;
            parent.sum += child.sum + d * child.ways;
        }
        
        parent.done = true;
        return parent;
    }
    
    ll SUM(ll N){
        string num = to_string(N);
        for(int pos = 0 ; pos < 20 ; pos++){
            DP[pos][0] = Node();
            DP[pos][1] = Node();
        }
        return DFS(num).sum;
    }
    
public:
    ll calculateDigitSum(ll L , ll R){
        return SUM(R) - SUM(L - 1);
    }
};


int main(){
    ll L , R ; cin >> L >> R;

    solution obj;
    cout << obj.calculateDigitSum(L , R);

    return 0;
}