//
//  main.cpp
//  PAT_A1043
//
//  Created by VachelChen on 2020/3/21.
//  Copyright © 2020 VachelChen. All rights reserved.
//

#include <iostream>
using namespace std;

const int maxn = 1010;

struct node{
    int val;
    node* left;
    node* right;
};

node* newNode(int v){
    node* n = new node;
    n->val = v;
    n->left = n->right = NULL;
    return n;
}

void insertTree(node* root,int x){
    if(root == NULL){
        root = newNode(x);
        return ;
    }
    else{
        while (root) {
            if(x < root->val)
                insertTree(root->left, x);
            else
                insertTree(root->right, x);
        }
    }
    
}

int n;

int main(int argc, const char * argv[]) {
    cin >> n;
    int key;
    node* root = new node;
    for (int i=0; i<n; i++) {
        cin >> key;
        insertTree(root,key);
    }
    return 0;
}
