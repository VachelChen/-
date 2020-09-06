//
//  main.cpp
//  BJFU_265
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

void CreateTree(tree &t,char str[],int &i){
    if (str[i] == '0') {
        t = NULL;
    }
    else{
        t = new Tnode;
        t->data = str[i];
        CreateTree(t->left,str,++i);
        CreateTree(t->right,str,++i);
    }
}

void showDouble(tree t){
    if (t) {
        cout<<t->data;
        showDouble(t->left);
        cout<<t->data;
        showDouble(t->right);
    }
}

int main(int argc, const char * argv[]) {
    char str[200];
    while (cin >> str) {
        if(str[0] == '0' && str[1] == '\0') break;
        tree t;
        int i=0;
        CreateTree(t,str,i);
        showDouble(t);
        cout<<endl;
    }
    return 0;
}
