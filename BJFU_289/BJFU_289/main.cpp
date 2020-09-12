//
//  main.cpp
//  BJFU_289
//
//  Created by VachelChen on 2020/9/12.
//  Copyright © 2020 VachelChen. All rights reserved.
//

#include <iostream>
#define maxn 100
using namespace std;

typedef struct node{
    int data;
    node *lchild,*rchild;
}node,*linklist;

int flag;

void CreateTree(linklist &t,int x){
    if (t) {
        t->data<x ? CreateTree(t->rchild, x):CreateTree(t->lchild, x);
    }
    else{
        t = new node;
        t->data = x;
        t->lchild = NULL;
        t->rchild = NULL;
    }
}

void ShowTree(linklist t,int x){
    if (t) {
        ShowTree(t->lchild, x);
        if (t->data >= x && !flag) {
            flag = 1;
        }
        if (flag == 1) {
            cout<<t->data;
            flag++;
        }
        else if(flag > 1)
            cout<<" "<<t->data;
        ShowTree(t->rchild, x);
    }
}

int main(int argc, const char * argv[]) {
    int n;
    while (cin >> n) {
        if(!n) break;
        int a[maxn];
        for (int i=0; i<n; i++) {
            cin >> a[i];
        }
        linklist root=NULL;
        int target;
        cin >> target;
        for (int i=0; i<n; i++) {
            CreateTree(root,a[i]);
        }
        flag = 0;
        ShowTree(root,target);
        cout<<endl;
    }
    return 0;
}
