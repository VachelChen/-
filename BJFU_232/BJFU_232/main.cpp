//
//  main.cpp
//  BJFU_232
//
//  Created by VachelChen on 2020/7/11.
//  Copyright © 2020 VachelChen. All rights reserved.
//

#include <iostream>
using namespace std;

typedef struct node{
    int data;
    node *last;
    node *next;
}*Linklist;

void InitList(Linklist &l){
    l = new node;
    l->next = NULL;
    l->last = NULL;
}

void creatLink(Linklist &l,int n){
    Linklist t=l,s;
    for (int i=0; i<n; i++) {
        s = new node;
        cin >> s->data;
        s->next = NULL;
        t->next = s;
        s->last = t;
        t = s;
    }
    t->next = l->next;
    l->next->last = t;
}


void printfList(Linklist l){
    Linklist temp = l->next;
    while (temp->next != l->next) {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<temp->data<<endl;
}

void deleteList(Linklist &l){
    int x;
    cin >> x;
    Linklist t=l;
    for (int i=0; i<x; i++) {
        t = t->next;
    }
    int temp = t->data;
    t->data = t->last->data;
    t->last->data = temp;
}

int main(int argc, const char * argv[]) {
    int n;
    while(cin >> n){
        if (!n) break;
        Linklist l;
        InitList(l);
        creatLink(l,n);
        deleteList(l);
        printfList(l);
    }
    return 0;
}
