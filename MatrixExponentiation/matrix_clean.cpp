#include<bits/stdc++.h>
using namespace std;

#define ll long long

template<typename T>
class matrix{
public:

    int n , m;
    int mod = 1e9 + 7;

    vector<vector<T>> mat;

    matrix(vector<vector<T>> &A){
        n = A.size() , m = A[0].size();
        mat = A;
    }

    matrix(int N = 2 , int M = 2 , int isIdentity = 0){
        n = N;
        m = M;
        mat = vector<vector<T>>(n , vector<T>(m , 0));
        if(isIdentity){
            for(int i = 0 ; i < n ; i++) mat[i][i] = 1;
        }
    }

    matrix operator +(const matrix &B){
        matrix &A = *this , result(n , m);
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                result.mat[i][j] = (A.mat[i][j] % mod + B.mat[i][j] % mod + mod) % mod;
            }
        }
        return result;
    }

    matrix operator -(const matrix &B){
        matrix &A = *this , result(n , m);
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                result.mat[i][j] = (A.mat[i][j] % mod - B.mat[i][j] % mod + mod) % mod;
            }
        }
        return result;
    }

    matrix operator *(const matrix &B){
        matrix &A = *this , result(A.n , B.m);
        for(int i = 0 ; i < A.n ; i++){
            for(int j = 0 ; j < B.m ; j++){
                for(int k = 0 ; k < B.m ; k++)
                result.mat[i][j] = (result.mat[i][j] + (A.mat[i][k] % mod) * (B.mat[k][j] % mod) % mod + mod) % mod;

            }
        }
        return result;
    }

    matrix operator ^(ll power){
        matrix A = *this , result(A.n , A.m , 1);
        while(power){
            if(power & 1) result = result * A;
            A = A * A;
            power >>= 1;
        }
        return result;
    }

    friend ostream& operator <<(ostream &os , const matrix &A){
        for(int i = 0 ; i < A.n ; i++){ 
            for(int j = 0 ; j < A.m ; j++){
                os << A.mat[i][j] << " ";
            }
            os << endl;
        }
        return os;
    }

};

int main(){


    vector<vector<ll>> mat = {
        {1  , 2 , 4},
        {8  , 0 , 1},
        {2  , 8 , 0}
    };

    matrix<ll> A(mat);

    cout << (A ^ 97);

    return 0;
}