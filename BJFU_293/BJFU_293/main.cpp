//
//  main.cpp
//  BJFU_293
//
//  Created by VachelChen on 2020/9/13.
//  Copyright © 2020 VachelChen. All rights reserved.
//

#include <iostream>
#define maxn 13
using namespace std;

typedef struct node{
    int data;
    node *next;
}node,*linklist;

int n;
linklist Hash[maxn];

void Init(){
    for (int i=0; i<maxn; i++) {
        Hash[i] = new node;
        Hash[i]->data = i;
        Hash[i]->next = NULL;
    }
}

void CreateHash(){
    int x;
    cin >> x;
    linklist s = new node;
    s->data = x;
    s->next = NULL;
    linklist t = Hash[x%13];
    while (t->next) {
        t = t->next;
    }
    t->next = s;
}

void DeleteHash(){
    int x;
    cin >> x;
    linklist p = Hash[x%13];
    linklist t = p->next;
    while (t->data!=x && t) {
        p = t;
        t = t->next;
    }
    if (!t && p->data!=x) {
        return;
    }
    else{
        p->next = t->next;
    }
}

void Output(){
    for (int i=0; i<maxn; i++) {
        cout<<i;
        linklist t = Hash[i]->next;
        while (t) {
            cout<<" "<<t->data;
            t = t->next;
        }
        cout<<endl;
    }
}

int main(int argc, const char * argv[]) {
    while (cin >> n) {
        if(!n)  break;
        Init();
        for (int i=0; i<n; i++) {
            CreateHash();
        }
        DeleteHash();
        Output();
    }
    return 0;
}
