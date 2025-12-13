#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int prefixCount = 0 , endCount = 0;
    Node* child[26];
};

class Trie{

private:  Node *root;

public:

    Trie(){
        root = new Node();
    }
    
    Node* getRoot(){
        return root;
    }

    void add(string &word){
        Node* node = root;
        for(char ch : word){
            if(node->child[ch-'a'] == NULL) node = node->child[ch-'a'] = new Node();
            else node = node->child[ch-'a'];
            node->prefixCount += 1;
        }
        node->endCount += 1;
    }

    int countWords(string &word){
        Node *node = root;
        for(char ch : word){
            if(node->child[ch-'a'] == NULL) return 0;
            node = node->child[ch-'a'];
        }
        return node->endCount;
    }

    int countPrefix(string &word){
        Node *node = root;
        for(char ch : word){
            if(node->child[ch-'a'] == NULL) return 0;
            node = node->child[ch-'a'];
        }
        return node->prefixCount;
    }

};

int main(){
    return 0;
}