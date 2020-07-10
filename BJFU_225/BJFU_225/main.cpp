//
//  main.cpp
//  BJFU_225-228
//
//  Created by VachelChen on 2020/7/9.
//  Copyright © 2020 VachelChen. All rights reserved.
//

#include <iostream>
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

void unionList(LinkList &a, LinkList &b, LinkList &c){
    LinkList pa = a->next,pb = b->next;
    c = a;
    LinkList pc = c;
    while (pa && pb) {
        if (pa->data < pb->data) {
            pc->next = pa;
            pc = pa;
            pa = pa->next;
            c->length++;
        }
        else if(pa->data > pb->data){
            pb = pb->next;
        }
        else{
            pa = pa->next;
            pb = pb->next;
        }
    }
    while (pa) {
        pc->next = pa;
        pc = pa;
        pa = pa->next;
        c->length++;
    }
    pc->next = NULL;
    
}

void printList(LinkList &l){
    LinkList temp = l->next;
    while (temp->next) {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<temp->data<<endl;
    cout<<l->length<<endl;
}

int main(int argc, const char * argv[]) {
    LinkList a,b,c;
    int la,lb;
    while(cin >> la >> lb){
        if (!la && !lb) {
            break;
        }
        InitList(a);InitList(b);
        creatList(a,la);creatList(b,lb);
        unionList(a,b,c);
        printList(c);
    }
    return 0;
}
