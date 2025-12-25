#include <bits/stdc++.h>
using namespace std;
using ll = long long;

class Line{
private:
    ll m , c;

public:
    Line(ll slope = 0, ll intercept = 0){
        m = slope;
        c = intercept;
    }

    ll eval(ll x){
        return m * x + c;
    }
};

class Node{
public:
    Line line;
    Node *left , *right;
    
public:
    Node(Line newLine = Line()){
        left = NULL;
        right = NULL;
        line = newLine;
    }
};

class LiChaoTree{
private:
    Node* root;
    ll xmin , xmax;

public:
    LiChaoTree(ll L , ll R){
        xmin = L;
        xmax = R;
        root = NULL;
    }

    void AddLine(ll slope , ll intercept){
        InsertLine(root , Line(slope , intercept) , xmin , xmax);
    }

    void AddSegment(ll slope , ll intercept , ll segL , ll segR){
        InsertSegment(root , Line(slope , intercept) , xmin , xmax , segL , segR);
    }

    ll Query(ll x){
        return Query(root , x , xmin , xmax);
    }

private:
    void InsertLine(Node* &node , Line newLine , ll L , ll R){
        if(node == NULL){
            node = new Node(newLine);
            return;
        }

        ll mid = (L + R) >> 1;
        bool left_better = newLine.eval(L) > node->line.eval(L);
        bool mid_better = newLine.eval(mid) > node->line.eval(mid);

        if(mid_better) swap(node->line , newLine);

        if(L == R) return;

        if(left_better != mid_better)
            InsertLine(node->left , newLine , L , mid);
        else
            InsertLine(node->right , newLine , mid + 1 , R);
    }

    void InsertSegment(Node*& node , Line newLine , ll L , ll R , ll segL , ll segR){
        if(segR < L || R < segL) return;

        if(segL <= L && R <= segR){
            InsertLine(node , newLine , L , R);
        }
        else{
            if(node == NULL) node = new Node();
            ll mid = (L + R) >> 1;
            InsertSegment(node->left , newLine , L , mid , segL , segR);
            InsertSegment(node->right , newLine , mid + 1 , R , segL , segR);
        }
    }

    ll Query(Node* node , ll x , ll L , ll R){
        if(node == NULL) return 0;

        ll res = node->line.eval(x);
        if(L == R) return res;

        ll mid = (L + R) >> 1;

        if(x <= mid)
            res = max(res , Query(node->left , x , L , mid));
        else
            res = max(res , Query(node->right , x , mid + 1 , R));

        return res;
    }

};


int main() {
    
    return 0;
}