#include<bits/stdc++.h>
using namespace std;

/*

Counts distinct element in nums([L...R])
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
    int N;    
    vector<Node*> version;

public:
    PersistentSegmentTree(vector<int> &nums){
        N = nums.size();
        compress(nums);

        version.resize(N + 1);
        version[0] = build(0 , N - 1);

        vector<int> lastpos(N + 1 , -1);

        for(int i = 0 ; i < N ; i++){
            Node *root = version[i];
            if(lastpos[nums[i]] != -1) root = update(root , 0 , N - 1 , lastpos[nums[i]] , -1);
            version[i + 1] = update(root , 0 , N - 1 , i , +1);;
            lastpos[nums[i]] = i;
        }
    }

    void compress(vector<int> &nums){
        map<int , vector<int>> map;
        for(int i = 0 ; i < N ; i++) map[nums[i]].push_back(i);
        int id = 0;
        for(auto &it : map){
            for(int i : it.second) nums[i] = id;
            id++;
        }
    }

    Node* merge(Node *u , Node *v){
        Node *uv = new Node();
        uv->left = u;
        uv->right = v;
        if(u) uv->count += u->count;
        if(v) uv->count += v->count;
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

    int query(Node *node , int low , int high , int qL , int qR){
        if(node == NULL || low > qR || high < qL) return 0;
        if(qL <= low && high <= qR) return node->count;
        int mid = (low + high) >> 1;
        return query(node->left , low , mid , qL , qR) + query(node->right , mid + 1 , high , qL , qR);
    }

    int countDistinct(int qL , int qR){
        return query(version[qR + 1] , 0 , N - 1 , qL , qR);
    }
};

int main(){
    int n , q ; cin >> n >> q;

    vector<int> nums(n);
    for(int &num : nums) cin >> num;

    PersistentSegmentTree PST(nums);

    for(int i = 1 ; i <= q ; i++){
        int L , R ; cin >> L >> R;
        cout << PST.countDistinct(L - 1 , R - 1) << "\n "[i == q];
    }

    return 0;
}