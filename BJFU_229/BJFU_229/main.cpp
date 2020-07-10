//
//  main.cpp
//  BJFU_229
//
//  Created by VachelChen on 2020/7/9.
//  Copyright © 2020 VachelChen. All rights reserved.
//
#include <iostream>
#include <algorithm>
using namespace std;

typedef struct node{
    int data,length;
    node *next;
}*LinkList;

void InitList(LinkList &l){
    l = new node;
    l->next = NULL;
    l->length = 0;
}

void creatList(LinkList &l,int num){
    LinkList t = l,s;
    //后插法
    for (int i=0; i<num; i++) {
        s = new node;
        cin >> s->data;
        s->next = NULL;
        t->next = s;
        t = s;
    }
}

void reverseList(LinkList &l){
    LinkList h = l,t = l->next,s = t->next;
    while (s) {
        t->next = h;
        h = t;
        t = s;
        s = s->next;
    }
    t->next = h;
    h = t;
    l->next = NULL;
    l = h;
    while (h->next->next) {
        cout<<h->data<<" ";
        h = h->next;
    }
    cout<<h->data<<endl;
}

int main(int argc, const char * argv[]) {
    LinkList a;
    int la;
    while(cin >> la){
        if (!la) {
            break;
        }
        InitList(a);
        creatList(a,la);
        reverseList(a);
    }
    return 0;
}
