#include<bits/stdc++.h>
using namespace std;

/*

Thinking:
    - Given that we can slide from L to R, if height[L] > height[L+1...R]
    - Meaning, for a given Building : DP[big] = 1 + max(DP[small])
    - small : list of indices, whose height is smaller than current mountain height

More 
    - DP[big] = 1 + max(DP[small])
    - Small mountains contribute to the bigger mountains
    - So propagate DP from small mountains to bigger mountains

*/

class SegmentTree{
private:
      vector<int> Tree;

public:
    SegmentTree(int n){
        Tree.resize(n << 2 | 2 , 0);
    }

    int Query(int node , int low , int high , int qL , int qR){
        if(low >  qR || high <  qL) return 0;
        if(low >= qL && high <= qR) return Tree[node];
        int mid = (low + high) >> 1;
        return max(Query(node << 1 , low , mid , qL , qR) , Query(node << 1 | 1 , mid + 1 , high , qL , qR));
    }

    int Update(int node , int low , int high , int index , int val){
        if(low == high) return Tree[node] = val;
        int mid = (low + high) >> 1;
        if(index <= mid) Update(node << 1 , low , mid , index , val);
        else Update(node << 1 | 1 , mid + 1 , high , index , val);
        return Tree[node] = max(Tree[node << 1] , Tree[node << 1 | 1]);
    }
};

vector<int> nge_left(vector<int> &heights){
    int n = heights.size();
    vector<int> nge(n) , stack;
    for(int i = 0 ; i < n ; i++){
        while(stack.empty() == false && heights[stack.back()] < heights[i]){
            stack.pop_back();
        }
        nge[i] = stack.empty() ? -1 : stack.back();
        stack.push_back(i);
    }
    return nge;
}

vector<int> nge_right(vector<int> &heights){
    int n = heights.size();
    vector<int> nge(n) , stack;
    for(int i = n - 1 ; i >= 0 ; i--){
        while(stack.empty() == false && heights[stack.back()] < heights[i]){
            stack.pop_back();
        }
        nge[i] = stack.empty() ? n : stack.back();
        stack.push_back(i);
    }
    return nge;
}

int main(){
    int n ; cin >> n;

    vector<int> heights(n);
    for(int &height : heights) cin >> height;

    vector<int> propagationOrder(n);
    iota(propagationOrder.begin() , propagationOrder.end() , 0);
    sort(propagationOrder.begin() , propagationOrder.end() , [&](int i , int j){
        return heights[i] < heights[j];
    });

    vector<int> left = nge_left(heights);
    vector<int> right = nge_right(heights);
    
    int maxSlides = 0;

    SegmentTree ST(n);
    vector<int> slidesFrom(n);

    for(int index : propagationOrder){
        int left_bound = left[index] + 1;
        int right_bound = right[index] - 1;

        int currSlides = 1 + ST.Query(1 , 0 , n - 1 , left_bound , right_bound);
        ST.Update(1 , 0 , n - 1 , index , slidesFrom[index] = currSlides);

        maxSlides = max(maxSlides , currSlides);
    }

    cout << maxSlides;

    return 0;
}