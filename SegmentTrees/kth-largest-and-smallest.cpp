#include<bits/stdc++.h>
using namespace std;

/*

Finds k-th smallest/largest element in nums[L...R]
works for static inputs

*/

struct Node{
    int count;
    Node *left , *right;

    Node(int num = 0){
        count = num;
        left = NULL;
        right = NULL;
    }
};

class PersistentSegmentTree{
private:
    int N , unique;
    vector<Node*> version;
    vector<int> indexToValue;

public:
    PersistentSegmentTree(vector<int> &nums){
        N = nums.size();
        compress(nums);

        unique = indexToValue.size();

        version.resize(N + 1);
        version[0] = build(0 , unique - 1);
        
        for(int i = 0 ; i < N ; i++){
            Node *root = version[i];
            version[i + 1] = update(root , 0 , unique - 1 , nums[i] , 1);
        }
    }

    void compress(vector<int> &nums){
        map<int , vector<int>> map;
        for(int i = 0 ; i < N ; i++) map[nums[i]].push_back(i);
        
        int id = 0;
        indexToValue.resize(map.size());
        
        for(auto &[num , indices] : map){
            indexToValue[id] = num;
            for(int i : indices) nums[i] = id;
            id++;
        }
    }

    Node* merge(Node *u , Node *v){
        Node *uv = new Node((u ? u->count : 0) + (v ? v->count : 0));
        uv->left = u;
        uv->right = v;
        return uv;
    }

    Node* build(int low , int high){
        if(low == high) return new Node(0);
        int mid = (low + high) >> 1;
        return merge(build(low , mid) , build(mid + 1 , high));
    }

    Node* update(Node *node , int low , int high , int idx , int val){
        if(low == high) return new Node(node->count + val);
        int mid = (low + high) >> 1;
        if(idx <= mid) return merge(update(node->left , low , mid , idx , val) , node->right);
        else return merge(node->left , update(node->right , mid + 1 , high , idx , val));
    }

    int kthQuery(Node *leftNode , Node *rightNode , int low , int high , int k){
        if(low == high) return low;
        
        int mid = (low + high) >> 1;
        int leftCount = (rightNode->left ? rightNode->left->count : 0) - (leftNode->left ? leftNode->left->count : 0);

        if(k <= leftCount) return kthQuery(leftNode->left , rightNode->left , low , mid , k);
        return kthQuery(leftNode->right , rightNode->right , mid + 1 , high , k - leftCount);
    }

    int kthSmallest(int L , int R , int k){
        int idx = kthQuery(version[L] , version[R + 1] , 0 , unique - 1 , k);
        return indexToValue[idx];
    }
    
    int kthLargest(int L , int R , int k){
        int total = version[R + 1]->count - version[L]->count;
        int idx = kthQuery(version[L] , version[R + 1] , 0 , unique - 1 , total - k + 1);
        return indexToValue[idx];
    }
};

int main(){
    int n , q ; cin >> n >> q;

    vector<int> nums(n);
    for(int &num : nums) cin >> num;

    PersistentSegmentTree PST(nums);

    for(int i = 1 ; i <= q ; i++){
        int L , R , K ; cin >> L >> R >> K;
        cout << PST.kthSmallest(L - 1 , R  - 1 , K) << "\n "[i == q];
    }

    return 0;
}