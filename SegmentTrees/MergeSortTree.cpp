#include<bits/stdc++.h>
using namespace std;

class mergeSortTree{
private:
    int N;
    vector<vector<int>> tree;

public:
    mergeSortTree(vector<int> &nums){
        this->N = nums.size();
        tree.resize(N << 2 | 1);
        build(1 , 0 , N - 1 , nums);
    }

    vector<int> merge(vector<int> &node1 , vector<int> &node2){
        vector<int> parentNode;
        int i = 0 , j = 0;
        while(i < node1.size() && j < node2.size()){
            if(node1[i] <= node2[j]) parentNode.push_back(node1[i++]);
            else parentNode.push_back(node2[j++]);
        }
        while(i < node1.size()) parentNode.push_back(node1[i++]);
        while(j < node2.size()) parentNode.push_back(node2[j++]);
        return parentNode;
    }

    void build(int node , int low , int high , vector<int> &nums){
        if(low == high){
            tree[node] = vector<int>{nums[low]};
            return;
        }
        int mid = (low + high) >> 1;
        build(node << 1 , low , mid , nums);
        build(node << 1 | 1 , mid + 1 , high , nums);
        tree[node] = merge(tree[node << 1] , tree[node << 1 | 1]);
    }

    void update(int node , int low , int high , int index , int val){
        if(low == high){
            tree[node] = vector<int>{val};
            return;
        }
        int mid = (low + high) >> 1;
        if(index <= mid) update(node << 1 , low , mid , index , val);
        else update(node << 1 | 1 , mid + 1 , high , index , val);
        tree[node] = merge(tree[node << 1] , tree[node << 1 | 1]);
    }
    
    int lessThanX(int ql , int qr , int x , int node = 1 , int low = 0 , int high = - 1){
        if(high == -1) high = N - 1;
        if(high < ql || low > qr) return 0;
        if(low >= ql && high <= qr) return lower_bound(tree[node].begin() , tree[node].end() , x) - tree[node].begin();
        int mid = (low + high) >> 1;
        return lessThanX(ql , qr , x , node << 1 , low , mid) + lessThanX(ql , qr , x , node << 1 | 1 , mid + 1 , high);
    }

    int greaterThanX(int ql , int qr , int x , int node = 1 , int low = 0 , int high = - 1){
        if(high == -1) high = N - 1;
        if(high < ql || low > qr) return 0;
        if(low >= ql && high <= qr) return tree[node].size() - (upper_bound(tree[node].begin() , tree[node].end() , x) - tree[node].begin());
        int mid = (low + high) >> 1;
        return greaterThanX(ql , qr , x , node << 1 , low , mid) + greaterThanX(ql , qr , x , node << 1 | 1 , mid + 1 , high);
    }
    
    int betweenXY_Inclusive(int ql , int qr , int x , int y , int node = 1 , int low = 0 , int high = - 1){
        if(high == -1) high = N - 1;
        if(high < ql || low > qr) return 0;
        if(low >= ql && high <= qr){
        
        }
        int mid = (low + high) >> 1;
        return betweenXY_Inclusive(ql , qr , x , node << 1 , low , mid) + betweenXY_Inclusive(ql , qr , x , node << 1 | 1 , mid + 1 , high);
    }

    int betweenXY_Exclusive(int ql , int qr , int x , int y , int node = 1 , int low = 0 , int high = - 1){
        if(high == -1) high = N - 1;
        if(high < ql || low > qr) return 0;
        if(low >= ql && high <= qr){
            
        }
        int mid = (low + high) >> 1;
        return betweenXY_Exclusive(ql , qr , x , node << 1 , low , mid) + betweenXY_Exclusive(ql , qr , x , node << 1 | 1 , mid + 1 , high);
    }

    int lessThanOrEqualsX(int ql , int qr , int x){
        return (qr - ql + 1) - greaterThanX(ql , qr , x);
    }

    int greaterThanOrEqualsX(int ql , int qr , int x){
        return (qr - ql + 1) - lessThanX(ql , qr , x);
    }

};

int main(){
    vector<int> nums = {6 , 1 , 2 , 0 , 100 , 200 , 0 , 0 , 0};
    mergeSortTree mst(nums);
    cout << mst.lessThanX(2 , 2 , 2) << endl;
    cout << mst.lessThanOrEqualsX(2 , 2 , 2) << endl;
    cout << mst.greaterThanX(2 , 2 , 2) << endl;
    cout << mst.greaterThanOrEqualsX(2 , 2 , 2) << endl;
    return 0;
}