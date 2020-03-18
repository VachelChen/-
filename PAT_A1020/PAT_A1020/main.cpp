//
//  main.cpp
//  PAT_A1020
//
//  Created by VachelChen on 2020/3/18.
//  Copyright © 2020 VachelChen. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;

struct node{
    int key;
    node* left;
    node* right;
}t[31];

int n;
int postOrder[31];
int indOrder[31];

node* tree;

queue<node*> q;

node* getTree(int postL, int postR, int inL ,int inR){
    if(postL > postR)
        return NULL;
    
    node* x = new node;
    x->key = postOrder[postR];
    
    int i;
    for(i=inL; i<inR; i++){
        if(indOrder[i] == postOrder[postR]){
            break;
        }
    }
    int numLeft = i - inL;
    
    x->left = getTree(postL, postL+numLeft-1, inL, i-1);
    x->right = getTree(postL+numLeft, postR-1, i+1, inR);
    
    return x;
}


int main(int argc, const char * argv[]) {
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> postOrder[i];
    for(int i=0; i<n; i++)
        cin >> indOrder[i];
    
    tree = getTree(0, n-1, 0, n-1);
    
    q.push(tree);
    
    bool flag = true;
    if(tree != NULL)
        cout<<tree->key;
    else
        return 0;
    
    while (!q.empty()) {
        node* temp = q.front();
        if (temp != NULL) {
            if(!flag){
                cout<<" "<<temp->key;
            }
            if(flag){
                flag = false;
            }
        }
        if (temp->left != NULL) {
            q.push(temp->left);
        }
        if (temp->right != NULL) {
            q.push(temp->right);
        }
        q.pop();
    }
    cout<<endl;
    return 0;
}
