//
//  main.cpp
//  BJFU_239
//
//  Created by VachelChen on 2020/7/13.
//  Copyright © 2020 VachelChen. All rights reserved.
//

#include <iostream>
using namespace std;

typedef struct node{
    int data;
    node *next;
}*LinkList;

void InitList(LinkList &l){
    l = new node;
    l->next = NULL;
}

void createList(LinkList &l,int m){
    LinkList t=l,s;
    for (int i=1; i<=m; i++) {
        InitList(s);
        s->data = i;
        t->next = s;
        t = s;
    }
    t->next = l->next;
}

void circleList(LinkList &l,int m,int n){
    LinkList temp = l->next,h = l;
    int index=1,d = 0;
    while (d+1 != m) {
        if(index == n){
            cout<<temp->data<<" ";
            h->next = temp->next;
            delete temp;
            temp = h->next;
            index = 1;
            d++;
        }
        else{
            h = h->next;
            temp = temp->next;
            index++;
        }
    }
    cout<<temp->data<<endl;
}

int main(int argc, const char * argv[]) {
    int m,n;
    while (cin >> m >> n) {
        if(!n && !m)    break;
        LinkList l;
        InitList(l);
        createList(l,m);
        circleList(l,m,n);
    }
    
    return 0;
}
