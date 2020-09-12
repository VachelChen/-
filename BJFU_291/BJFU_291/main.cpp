//
//  main.cpp
//  BJFU_291
//
//  Created by VachelChen on 2020/9/12.
//  Copyright © 2020 VachelChen. All rights reserved.
//

#include <iostream>
#define maxn 100
using namespace std;

typedef struct node{
    int balance;
    node *left,*right;
}node,*linklist;

void Create(linklist &t,char str[],int &i){
    if (str[i] == '#') {
        t = NULL;
    }
    else{
        t = new node;
        t->balance = (str[i]-'0');
        t->left = NULL;
        t->right = NULL;
        i++;
        Create(t->left, str, i);
        i++;
        Create(t->right, str, i);
    }
}

int GetHeight(linklist t){
    if (!t)
        return 0;
    else if (!t->left && !t->right)
        return 1;
    else
        return GetHeight(t->left)>=GetHeight(t->right)?GetHeight(t->left)+1:GetHeight(t->right)+1;
}


int main(int argc, const char * argv[]) {
    char a[maxn];
    while (cin >> a) {
        if(a[0] == '#') break;
        linklist t;
        int index = 0;
        Create(t,a,index);
        cout<<GetHeight(t)<<endl;
    }
    return 0;
}
