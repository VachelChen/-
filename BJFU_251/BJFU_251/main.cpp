//
//  main.cpp
//  BJFU_251
//
//  Created by VachelChen on 2020/7/29.
//  Copyright © 2020 VachelChen. All rights reserved.
//

#include <iostream>
#define ok 1
#define error 0
using namespace std;

typedef struct Lnode{
    int data;
    Lnode *next;
}Lnode,*LinkList;   //一个是指针类型，一个是节点类型

int initNode(LinkList &l){
    l = new Lnode;
    if(!l) return error;
    l->next = NULL;
    return ok;
}

int insertNode(LinkList &l,int n){
    LinkList t;
    for (int i=0; i<n; i++) {
        t = new Lnode;
        cin >> t->data;
        t->next = l->next;
        l->next = t;
    }
    return ok;
}

int findAve(LinkList l,double num){
    if (!l->next) {
        num += l->data;
        return num;
    }
    else{
        return findAve(l->next,num+l->data);
    }
}

int main(int argc, const char * argv[]) {
    int n;
    LinkList l;
    while (cin >> n) {
        if(!n) break;
        initNode(l);
        insertNode(l,n);
        printf("%.2f\n",1.0*findAve(l->next,0)/n);
    }
    return 0;
}
