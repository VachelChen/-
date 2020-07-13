//
//  main.cpp
//  BJFU_237
//
//  Created by VachelChen on 2020/7/12.
//  Copyright © 2020 VachelChen. All rights reserved.
//

#include <iostream>
using namespace std;

typedef struct node{
    int data;
    node *next;
}*linklist;

void InitList(linklist &l){
    l = new node;
    l->next = NULL;
}

void createList(linklist &l,int n){
    linklist t=l,s;
    for (int i=0; i<n; i++) {
        InitList(s);
        cin >> s->data;
        t->next = s;
        t = s;
    }
}

void printMid(linklist a,linklist b,int m){
    linklist pa = a->next,pb = b->next;
    linklist c = a,pc = c;
    while (m--) {
        if (pa->data <= pb->data) {
            pc->next = pa;
            pc = pa;
            pa = pa->next;
        }
        else{
            pc->next = pb;
            pc = pb;
            pb = pb->next;
        }
    }
    cout<<pc->data<<endl;
}

int main(int argc, const char * argv[]) {
    int n;
    while (cin >> n) {
        if(!n)  break;
        linklist a,b;
        InitList(a);InitList(b);
        createList(a,n);createList(b,n);
        printMid(a,b,n);
    }
    return 0;
}
