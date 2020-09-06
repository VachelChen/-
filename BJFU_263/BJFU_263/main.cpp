//
//  main.cpp
//  BJFU_263
//
//  Created by VachelChen on 2020/9/1.
//  Copyright © 2020 VachelChen. All rights reserved.
//

#include <iostream>
#include <cstring>
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
        CreateTree(t->left, str, ++n);
        CreateTree(t->right, str, ++n);
    }
}

int flag;
void Compare(tree t1,tree t2){
    if ((!t1 || !t2) && ((t1 || t2))) {
        flag = false;
    }
    if(t1&&t2){
        if (t1->data != t2->data) {
            flag = false;
            return;
        }
        else{
            Compare(t1->left, t2->left);
            Compare(t1->right, t2->right);
        }
    }
}

int main(int argc, const char * argv[]) {
    char str1[100],str2[100];
    while (cin>>str1) {
        flag = true;
        if(str1[0] == '0' && str1[1] == '\0')   break;
        cin >> str2;
        tree t1,t2;
        int a = 0,b = 0;
        CreateTree(t1,str1,a);
        CreateTree(t2,str2,b);
        Compare(t1,t2);
        if(flag)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}
