#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    Node* child[2];
};

class Trie{

private: Node *root;

public:

    Trie(){
        root = new Node();
    }

    void add(int num){
        Node* node = root;
        for(int pos = 31 ; pos >= 0 ; pos--){
            int bit = num >> pos & 1;
            if(node->child[bit] == NULL) node = node->child[bit] = new Node();
            else node = node->child[bit];
        }
    }

    bool search(int num){
        Node* node = root;
        for(int pos = 31 ; pos >= 0 ; pos--){
            int bit = num >> pos & 1;
            if(node->child[bit] == NULL) return false;
            node = node->child[bit];
        }
        return true;
    }

    int maximumXor(int num , int Xor = 0){
        Node* node = root;
        for(int pos = 31 ; pos >= 0 ; pos--){
            int bit = num >> pos & 1;
            if(node->child[1 - bit] != NULL){
                Xor += 1LL << pos;
                node = node->child[1 - bit];  
            } 
            else if(node->child[bit] != NULL){
                node = node->child[bit];
            }
            else{
                return 0;
            }
        }
        return Xor;
    }

};

int main(){
    Trie t;
    t.add(1);
    t.add(2);
    cout << t.maximumXor(2) << endl;
    return 0;
}