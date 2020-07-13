//
//  main.cpp
//  BJFU_238
//
//  Created by VachelChen on 2020/7/12.
//  Copyright © 2020 VachelChen. All rights reserved.
//

#include <iostream>
using namespace std;

typedef struct node{
    char data;
    node *next;
}*LinkList;

void InitList(LinkList &l){
    l = new node;
    l->next = NULL;
}

void createList(LinkList &l,int n){
    LinkList s;
    for (int i=0; i<n; i++) {
        s = new node;
        cin >> s->data;
        s->next = l->next;
        l->next = s;
    }
}

void checkList(LinkList a,LinkList b){
    LinkList pa=a->next,pb=b->next;
    while (pa->next && pb->next) {
        if (pa->next->data != pb->next->data) {
            cout<<pa->data<<endl;
            return;
        }
        else{
            pa = pa->next;
            pb = pb->next;
        }
    }
}

int main(int argc, const char * argv[]) {
    int n,m;
    while(cin >> n >> m){
        if(!n && !m)    break;
        LinkList a,b;
        InitList(a);InitList(b);
        createList(a, n);
        createList(b, m);
        checkList(a,b);
    }
    
    return 0;
}
