//
//  main.cpp
//  PAT_A1066
//
//  Created by VachelChen on 2020/6/28.
//  Copyright © 2020 VachelChen. All rights reserved.
//

#include <iostream>
using namespace std;

struct node{
    int val,height;
    node *left,*right;
};

node* newNode(int v){
    node* Node = new node;
    Node->val = v;
    Node->height = 1;
    Node->left = NULL;  Node->right = NULL;
    return Node;
}

int getHeight(node *root){
    if (root == NULL) {
        return 0;
    }
    return root->height;
}

void updateHeight(node* root){
    root->height = max(getHeight(root->left), getHeight(root->right))+1;
}

void L(node* &root){
    node* temp = root->right;
    root->right = temp->left;
    temp->left = root;
    updateHeight(root);
    updateHeight(temp);
    root = temp;
}

void R(node* &root){
    node* temp = root->left;
    root->left = temp->right;
    temp->right = root;
    updateHeight(root);
    updateHeight(temp);
    root = temp;
}

int getBalence(node* root){
    return getHeight(root->left) - getHeight(root->right);
}

void insertAVL(node* &root,int v){
    if (root == NULL) {
        root = newNode(v);
        return;
    }
    if (v < root->val) {
        insertAVL(root->left, v);
        updateHeight(root);
        if (getBalence(root) == 2) {
            if (getBalence(root->left) == 1) {
                R(root);
            }
            else if(getBalence(root->left) == -1){
                L(root->left);
                R(root);
            }
        }
    }
    else{
        insertAVL(root->right, v);
        updateHeight(root);
        if (getBalence(root) == -2) {
            if (getBalence(root->right) == -1) {
                L(root);
            }
            else if(getBalence(root->right) == 1){
                R(root->right);
                L(root);
            }
        }
    }
}
int main(int argc, const char * argv[]) {
    int n;
    scanf("%d",&n);
    node *root = NULL;
    for (int i=0; i<n; i++) {
        int x;
        scanf("%d",&x);
        insertAVL(root, x);
    }
    if (root != NULL) {
        printf("%d\n",root->val);
    }
    return 0;
}
