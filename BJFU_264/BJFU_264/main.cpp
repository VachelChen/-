//
//  main.cpp
//  BJFU_264
//
//  Created by VachelChen on 2020/9/3.
//  Copyright © 2020 VachelChen. All rights reserved.
//

#include <iostream>
using namespace std;

typedef struct Tnode{
    char data;
    Tnode *left,*right;
}Tnode,*tree;

void CreateTree(tree &t,char str[],int &n){
    if (str[n] == '0') {
        t = NULL;
    }
    else{
        t = new Tnode;
        t->data = str[n];
        CreateTree(t->left,str,++n);
        CreateTree(t->right,str,++n);
    }
}

void change(tree &t){
    if (t) {
        tree temp = new Tnode;
        temp = t->left;
        t->left = t->right;
        t->right = temp;
        
        change(t->left);
        change(t->right);
    }
}

void showIn(tree t){
    if (t) {
        cout<<t->data;
        showIn(t->left);
        showIn(t->right);
    }
}

int main(int argc, const char * argv[]) {
    char str1[200];
    while (cin >> str1) {
        if(str1[0] == '0' && str1[1] == '\0')   break;
        int n = 0;
        tree t;
        CreateTree(t,str1,n);
        change(t);
        showIn(t);
        cout<<endl;
    }
    return 0;
}
