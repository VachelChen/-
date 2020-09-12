//
//  main.cpp
//  BJFU_288
//
//  Created by VachelChen on 2020/9/12.
//  Copyright © 2020 VachelChen. All rights reserved.
//

#include <iostream>
#define maxn 100
using namespace std;

typedef struct node{
    char data;
    node *left,*right;
}node,*linklist;

bool flag;
int top;
char b[maxn];

void createPre(linklist &t,char str[],int &index){
    if(str[index] == '#')
        t = NULL;
    else{
        t = new node;
        t->data = str[index];
        t->left = t->right = NULL;
        index++;
        createPre(t->left,str,index);
        index++;
        createPre(t->right,str,index);
    }
}

void InOrder(linklist t){
    if (t) {
        InOrder(t->left);
        b[top++] = t->data;
        if (top>1 && b[top-2]>b[top-1]) {
            flag = false;
            return;
        }
        InOrder(t->right);
    }
}

int main(int argc, const char * argv[]) {
    char a[maxn];
    while (cin >> a) {
        if(a[0] == '#') break;
        linklist root;
        int index = 0;
        top = 0;
        createPre(root,a,index);
        flag = true;
        InOrder(root);
        if (flag) {
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}
