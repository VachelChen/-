//
//  main.cpp
//  BJFU_266
//
//  Created by VachelChen on 2020/9/3.
//  Copyright © 2020 VachelChen. All rights reserved.
//

#include <iostream>
#include <cstring>
using namespace std;

typedef struct Tnode{
    char data;
    Tnode *left,*right;
    int deep;
}Tnode,*tree;

int o,y,e;

void CreateTree(tree &t,tree p,char str [],int &i){
    if (str[i] == '0') {
        t = NULL;
    }
    else{
        t = new Tnode;
        t->data = str[i];
        CreateTree(t->left,t,str,++i);
        CreateTree(t->right,t,str,++i);
    }
}

void OrderIn(tree t){
    if(t){
        if (t->left && t->right) {
            e++;
        }
        else if((t->left||t->right)&&(!t->left||!t->right)){
            y++;
        }
        else if(!t->left && !t->right){
            o++;
        }
        OrderIn(t->left);
        OrderIn(t->right);
    }
}


int main(int argc, const char * argv[]) {
    char str[200];
    while (cin >> str) {
        if(str[0] == '0' && str[1] == '\0') break;
        tree t;
        int i=0;
        CreateTree(t,NULL,str,i);
        o = y = e = 0;
        OrderIn(t);
        cout<<o<<" "<<y<<" "<<e<<endl;
    }
    return 0;
}
