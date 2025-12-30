#include<bits/stdc++.h>
using namespace std;
 
class FenwickTree{
private:
    vector<int> BIT;
 
public:
    FenwickTree(int n){
        BIT.resize(n + 2, 0);
    }
 
    int Query(int index){
        int sum = 0;
        for( ; index > 0 ; index -= index & -index) sum += BIT[index];
        return sum;
    }
 
    int Query(int l , int r){
        return Query(r) - Query(l - 1);
    }
 
    void Update(int index , int val){
        for( ; index < (int)BIT.size() ; index += index & -index) BIT[index] += val;
    }
};   
 
 
void compress(vector<array<int , 3>> &nums){
    map<int , int> map;
    for(auto &[start , end , index] : nums) map[start] = map[end] = 1;
 
    int newID = 1;
    for(auto &[num , ID] : map) ID = newID++;
 
    for(auto &[start , end , index] : nums) start = map[start] , end = map[end];
}
 
 
int main(){
    int n ; cin >> n;
 
    vector<array<int , 3>> ranges(n);
    for(int i = 0 ; i < n ; i++){
        cin >> ranges[i][0] >> ranges[i][1];
        ranges[i][2] = i;
    }
 
    compress(ranges);
 
    int maxN = 2 * n + 1;
 
    // Is any range inside me !?
    {
        sort(ranges.begin() , ranges.end() , [&](array<int , 3> &r1 , array<int , 3> &r2){
            return r1[1] == r2[1] ? r1[0] > r2[0] : r1[1] < r2[1];
        });
 
        FenwickTree FT(maxN);
        vector<int> count_inside_me(n , 0);
 
        for(auto [start , end , index] : ranges){
            int count = FT.Query(start , maxN - 1);
            count_inside_me[index] = count;
            FT.Update(start , 1);
        }
 
        for(int count : count_inside_me) cout << count << " " ;
        cout << endl;
    }
 
 
 
    // Am I inside any range !?
    {
        sort(ranges.begin() , ranges.end() , [&](array<int , 3> &r1 , array<int , 3> &r2){
            return r1[0] == r2[0] ? r1[1] > r2[1] : r1[0] < r2[0];
        });
        
        FenwickTree FT(maxN);
        vector<int> count_I_am_inside(n , 0);
 
        for(auto [start , end , index] : ranges){
            int count = FT.Query(end , maxN - 1);
            count_I_am_inside[index] = count;
            FT.Update(end , 1);
        }
 
        for(int count : count_I_am_inside) cout << count << " " ;
    }
 
    return 0;
}