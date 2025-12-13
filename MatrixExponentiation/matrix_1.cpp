#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 1e9 + 7;

class matrix{
public:
    #define REP(i , n) for(int i = 0 ; i < n ; i++)

    ll mat[2][2] = {{0 , 0} , {0 , 0}};

    matrix operator +(const matrix &B){
        matrix res;
        REP(i , 2) REP(j , 2) res.mat[i][j] = mat[i][j] + B.mat[i][j];
        return res;
    }

    matrix operator -(const matrix &B){
        matrix res;
        REP(i , 2) REP(j , 2) res.mat[i][j] = mat[i][j] - B.mat[i][j];
        return res;
    }

    matrix operator *(const matrix &B){
        matrix res;
        REP(i , 2) REP(j , 2) REP(k , 2) res.mat[i][j] = (res.mat[i][j] + mat[i][k] * B.mat[k][j]) % mod;
        return res;
    }

    matrix operator ^(ll B){
        matrix A = *this , res;
        REP(i , 2) res.mat[i][i] = 1;
        while(B){
            if(B & 1) res = res * A;
            A = A * A;
            B >>= 1;
        }
        return res;
    }

    friend ostream& operator<<(ostream &os , const matrix &A){
        REP(i , 2){ 
            REP(j , 2){
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