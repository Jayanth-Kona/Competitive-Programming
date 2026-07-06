#include<bits/stdc++.h>
using namespace std;

class BitManipulation{
public:
    BitManipulation(){

    }

    void printMask(int mask){
        cout << mask << " -> " << bitset<10>(mask) << "\n";
    }

    // Print all subsets of mask (descending order)
    void subsets(int mask){
        cout << "printing subsets of "; printMask(mask);
        for(int sub = mask ; ; sub = (sub - 1) & mask){
            printMask(sub);
            if(sub == 0) break;
        }
        cout << "\n";
    }

    // Print all supersets of mask (descending order)
    // NOTE: total mask should be of form : (1 << n) - 1
    void supersets(int mask , int totalMask){
        cout << "printing supersets of "; printMask(mask);
        int rem = totalMask ^ mask;
        for(int sub = rem ;  ; sub = (sub - 1) & rem){
            printMask(sub | mask);
            if(sub == 0) break;
        }
        cout << "\n";
    }

    // SOS DP: sum over all subsets -> TC: O(n * 2^n)
    // After this: dp[mask] = sum of count[subset] for all sub ⊆ mask
    void sum_of_subsets(int n , vector<long long> &sum){
        for(int i = 0 ; i < n ; i++){
            for(int mask = 0 ; mask < (1 << n) ; mask++){
                if((mask >> i & 1) == 1){
                    sum[mask] += sum[mask ^ (1 << i)];
                }
            }
        }
    }

    // SOS DP: sum over all supersets -> TC: O(n * 2^n)
    // After this: dp[mask] = sum of count[superset] for all super ⊇ mask
    void sum_of_supersets(int n , vector<long long> &sum){
        for(int i = 0 ; i < n ; i++){
            for(int mask = 0 ; mask < (1 << n) ; mask++){
                if((mask >> i & 1) == 0){
                    sum[mask] += sum[mask | (1 << i)];
                }
            }
        }
    }

};


int main(){
    BitManipulation bm;
    bm.supersets(1 , 15);

    return 0;
}