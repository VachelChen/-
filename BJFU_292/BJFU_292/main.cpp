//
//  main.cpp
//  BJFU_292
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

void Create(){
    int x;
    cin >> x;
    linklist s = new node;
    s->data = x;
    s->next = NULL;
    linklist p = Hash[x%13];
    while (p->next) {
        p = p->next;
    }
    p->next = s;
}

void Output(){
    for (int i=0; i<maxn; i++) {
        cout<<i;
        linklist t = Hash[i]->next;
        while (t) {
            cout<<" "<<t->data;
            t=t->next;
        }
        cout<<endl;
    }
}

int main(int argc, const char * argv[]) {
    while (cin >> n) {
        if(!n) break;
        Init();
        for (int i=0; i<n; i++) {
            Create();
        }
        Create();
        Output();
    }
    return 0;
}
