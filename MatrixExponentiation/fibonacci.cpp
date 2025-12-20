#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 1e9 + 7;

class matrix{
public:
    #define REP(i , n) for(int i = 0 ; i < n ; i++)

    ll mat[2][2] = {{0 , 0} , {0 , 0}};

    matrix operator *(const matrix &B){
        matrix res;
        REP(i , 2) REP(j , 2) REP(k , 2) res.mat[i][j] = (res.mat[i][j] + mat[i][k] * B.mat[k][j]) % mod;
        return res;
    }

    matrix operator ^(ll power){
        matrix A = *this , res;
        REP(i , 2) res.mat[i][i] = 1;
        while(power){
            if(power & 1) res = res * A;
            A = A * A;
            power >>= 1;
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



/*

    ################################################################################################
    ################################################################################################
    ################                                                               #################
    ################ DONT REMOVE THIS (IT TOOK EFFORT TO WRITE THIS AND UNDERSTAND)#################
    ################                                                               #################
    ################################################################################################
    ################################################################################################



    IDEA : 

    a = 0 , b = 1; // fibonacci sequence
    
    for(int i = 2 ; i <= N ; i++){
        int new_a = b;
        int new_b = a + b;
    }



    try transform into equations and get matrix generated
    


    correct:
        a  b
    a
    a

    new_a = 0 * a + 1 * b
    new_b = 1 * a + 1 * b;
    FIBONACCI.mat[0][0] = 0 , FIBONACCI.mat[0][1] = 1;
    FIBONACCI.mat[1][0] = 1 , FIBONACCI.mat[1][1] = 1;



    wrong:
        a  b
    b
    a

    new_b = 1 * a + 1 * b;
    new_a = 0 * a + 1 * b
    FIBONACCI.mat[0][0] = 1 , FIBONACCI.mat[0][1] = 1;
    FIBONACCI.mat[1][0] = 0 , FIBONACCI.mat[1][1] = 1;

    correct:
        b  a
    b
    a
    
    new_b = 1 * b + 1 * a;
    new_a = 1 * b + 0 * a
    FIBONACCI.mat[0][0] = 1 , FIBONACCI.mat[0][1] = 1;
    FIBONACCI.mat[1][0] = 1 , FIBONACCI.mat[1][1] = 0;



#####################################################################################################



Formal proof:


 A0     F   ->      F0 = 0
[1 0]  [F0]      [F0 : 0]
[0 1]  [F1]      [F1 : 1]

 A1      F  ->       F1 = 1
[0 1]  [F0]     [F1      : 1] 
[1 1]  [F1]     [F0 + F1 : 1]


 A2      F  ->       F2 = 1
[1 1]  [F0]     [F0 + F1  : 1]
[1 2]  [F1]     [F0 + 2F1 : 2]


 A3      F  ->       F3 = 2
[1 2]  [F0]     [F0 + 2F1   : 2]
[2 3]  [F1]     [2F0 + 3F1  : 3]


 A8     F    ->     F8 = 21
[13 21] [F0]   [13F0 + 21F1 : 21]
[21 34] [F1]   [21F0 + 34F1 : 34]


#####################################################################################################
 

int new_a = 0 * a + 1 * b;
int new_b = 1 * a + 1 * b

  A1    A1  ->   A2
[0 1] [0 1]    [1 1]
[1 1] [1 1]    [1 2]

  A2    A1  ->   A3
[1 1] [0 1]    [1 2]
[1 2] [1 1]    [2 3]

  A3    A1  ->   A4
[1 2] [0 1]    [2 3]
[2 3] [1 1]    [3 5]

  A2    A2  ->   A4 
[1 1] [1 1]    [2 3]
[1 2] [1 2]    [3 5]

  A4    A1  ->   A5
[2 3] [0 1]    [3 5]
[3 5] [1 1]    [5 8]

  A2    A3  ->   A5
[1 1] [1 2]    [3 5]
[1 2] [2 3]    [3 5]

  A4    A4  ->   A8
[2 3] [2 3]    [13 21]
[3 5] [3 5]    [21 34]



*/