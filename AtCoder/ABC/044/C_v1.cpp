#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll DP[50][50 * 50 + 1][51];

ll DFS(int i , int sum , int cnt , int reqd , vector<int> &x){
    if(i < 0) return cnt > 0 && sum == reqd * cnt;
    
    if(DP[i][sum][cnt] != -1) return DP[i][sum][cnt];
    
    return DP[i][sum][cnt] = DFS(i - 1 , sum + x[i] , cnt + 1 , reqd , x) + DFS(i - 1 , sum , cnt , reqd , x);
};

int main(){
    int n , a ; cin >> n >> a;

    vector<int> x(n);
    for(int &num : x) cin >> num;

    memset(DP , -1 , sizeof DP);
    cout << DFS(n - 1 , 0 , 0 , a , x);
    
    return 0;
}