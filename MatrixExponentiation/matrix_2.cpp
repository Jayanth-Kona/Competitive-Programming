#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 1e9 + 7;

class matrix{
public:
    #define REP(i , n) for(int i = 0 ; i < n ; i++)

    ll R , C;
    vector<vector<ll>> mat;

    matrix(int N = 2 , int M = 2 , int V = 0){
        R = N , C = M;
        mat = vector<vector<ll>> (N , vector<ll>(M , 0));
        if(R == C && V != 0) REP(i , R) mat[i][i] = V;
    }

    matrix operator +(const matrix &B){
        matrix &A = *this , res(R , C);
        REP(i , R) REP(j , C) res.mat[i][j] = (A.mat[i][j] + B.mat[i][j]) % mod;
        return res;
    }

    matrix operator -(const matrix &B){
        matrix &A = *this , res(R , C);
        REP(i , R) REP(j , C) res.mat[i][j] = ((A.mat[i][j] - B.mat[i][j]) % mod + mod) % mod;
        return res;
    }

    matrix operator *(const matrix &B){
        // for N x M matrix : A.C == B.R
        matrix &A = *this , res(A.R , B.C); // A.R * B.C
        REP(i , A.R) REP(j , B.C) REP(k , A.C) res.mat[i][j] = (res.mat[i][j] + A.mat[i][k] * B.mat[k][j]) % mod;
        return res;
    }

    matrix operator ^(ll B){
        matrix A = *this , res(R , C , 1);
        while(B){
            if(B & 1) res = res * A;
            A = A * A;
            B >>= 1;
        }
        return res;
    }

    friend ostream& operator<<(ostream &os , const matrix &A){
        REP(i , A.R){ 
            REP(j , A.C){
                os << A.mat[i][j] << " ";
            }
            os << endl;
        }
        return os;
    }

};

int main(){
    ll n ; cin >> n;

    matrix FIBONACCI;
    
    FIBONACCI.mat[0][0] = 0 , FIBONACCI.mat[0][1] = 1;
    FIBONACCI.mat[1][0] = 1 , FIBONACCI.mat[1][1] = 1;

    cout << (FIBONACCI ^ n).mat[0][1];

    return 0;
}