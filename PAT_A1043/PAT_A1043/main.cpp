//
//  main.cpp
//  PAT_A1043
//
//  Created by VachelChen on 2020/3/21.
//  Copyright © 2020 VachelChen. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int n,coutn;
vector<int> v;
vector<int> temp;

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

void insertTree(node* &root,int x){
    if(root == NULL){
        root = newNode(x);
        return ;
    }
    else{
        if(x < root->val)
            insertTree(root->left, x);
        else
            insertTree(root->right, x);
    }
}

void insertBSTTree(node* &root,int x){
    if(root == NULL){
        root = newNode(x);
        return ;
    }
    else{
        if(x >= root->val)
            insertBSTTree(root->left, x);
        else
            insertBSTTree(root->right, x);
    }
}

void pre(node* root){
    if(root != NULL){
        temp.push_back(root->val);
        if(root->left != NULL)   pre(root->left);
        if(root->right != NULL)  pre(root->right);
    }
}

bool judgePre(node* root){
    temp.clear();
    pre(root);
    if(v == temp){
        return true;
    }
    return false;
}

void printPost(node* root){
    if(root != NULL){
        if(root->left != NULL){
            printPost(root->left);
        }
        if(root->right != NULL){
            printPost(root->right);
        }
        coutn++;
        cout<<root->val;
        if(coutn < n)
            cout<<" ";
        else
            cout<<endl;
    }
}

int main(int argc, const char * argv[]) {
    cin >> n;
    int key;
    node* root = NULL;
    node* BSTroot = NULL;
    for (int i=0; i<n; i++) {
        cin >> key;
        v.push_back(key);
        insertTree(root,key);
        insertBSTTree(BSTroot,key);
    }
    if(judgePre(root)){
        cout<<"YES"<<endl;
        coutn = 0;
        printPost(root);
    }
    else if(judgePre(BSTroot)){
        cout<<"YES"<<endl;
        coutn = 0;
        printPost(BSTroot);
    }
    else
        cout<<"NO"<<endl;
    return 0;
}
