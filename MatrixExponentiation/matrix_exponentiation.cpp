#include<bits/stdc++.h>
using namespace std;


class matrix{
public:
    #define REP(i , n) for(int i = 0 ; i < n ; i++)

    int mat[2][2] = {{0 , 0} , {0 , 0}};

    matrix operator *(const matrix &B){
        matrix res;
        REP(i , 2) res.mat[i][i] = 1;
        REP(i , 2) REP(j , 2) REP(k , 2) res.mat[i][j] += mat[i][k] * B.mat[k][j];
        return res;
    }

    matrix operator ^(int B){
        matrix A = *this , res;
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

    return 0;
}