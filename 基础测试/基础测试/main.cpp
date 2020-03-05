//
//  main.cpp
//  基础测试
//
//  Created by VachelChen on 2020/2/29.
//  Copyright © 2020 VachelChen. All rights reserved.
//

#include <iostream>
#include <map>
#include <queue>
using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     //TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool isSymmetric(TreeNode* root) {
    bool ans = true;
        if(root == NULL)    return ans;
        if(root->left->val != root->right->val)   return false;
        if(root->left == NULL)  return true;
        queue<TreeNode *> l;
        queue<TreeNode *> r;
        l.push(root->left);
        r.push(root->right);
        while(!l.empty())
        {
            if(l.front() == NULL && r.front() != NULL){
                ans = false;
                break;
            }

            if(l.front() != NULL && r.front() == NULL){
                ans = false;
                break;
            }

            if(l.front()->val != r.front()->val){
                ans = false;
                break;
            }

            if(l.front()->right != NULL || l.front()->left != NULL){
                l.push(l.front()->left);
                l.push(l.front()->right);
            }
            if(r.front()->right != NULL || r.front()->left != NULL){
                r.push(r.front()->right);
                r.push(r.front()->left);
            }
            l.pop();    r.pop();
        }
        return ans;
}

int main(){
    TreeNode x,y,z,a,b;
    x.val = 1;
    y.val = 2;
    z.val = 2;
    a.val = 2;
    b.val = 2;
    x.left = &y;
    x.right = &z;
    y.left = &a;
    y.right = NULL;
    z.left = &b;
    z.right = NULL;
    cout<<isSymmetric(&x)<<endl;
    return 0;
}
