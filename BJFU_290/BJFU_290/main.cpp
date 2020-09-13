//
//  main.cpp
//  BJFU_290
//
//  Created by VachelChen on 2020/9/12.
//  Copyright © 2020 VachelChen. All rights reserved.
//

#include <iostream>
#define maxn 100
using namespace std;

typedef struct node{
    int data;
    int count;
    node *llink,*rlink;
}node,*linklist;

int once;

void Create(linklist &t,int x){
    linklist s;
    s = new node;
    s->data = x;
    s->count = 0;
    s->llink = s->rlink = NULL;
    if (!t) {
        t = s;
        return;
    }
    linklist q = t,p;
    while (q) {
        if (q->data == x) {
            q->count++;
            return;
        }
        p = q;
        if(q->data > x)
            q=q->llink;
        else
            q=q->rlink;
    }
    if(p->data > x)
        p->llink = s;
    else
        p->rlink = s;
}

void Sreach(linklist t){
    if (t) {
        Sreach(t->llink);
        if (!once) {
            cout<<t->data;
            once=1;
        }
        else
            cout<<" "<<t->data;
        Sreach(t->rlink);
    }
}

void Sreach2(linklist t){
    if (t) {
        Sreach2(t->llink);
        if (!once) {
            cout<<t->count;
            once=1;
        }
        else
            cout<<" "<<t->count;
        Sreach2(t->rlink);
    }
}

int main(int argc, const char * argv[]) {
    int n;
    while (cin >> n) {
        if(!n)  break;
        linklist t = NULL;
        int a[maxn];
        for (int i=0; i<n; i++) {
            cin >> a[i];
            Create(t,a[i]);
        }
        int x;
        cin >> x;
        Create(t, x);
        once = 0;
        Sreach(t);
        cout<<endl;
        once = 0;
        Sreach2(t);
        cout<<endl;
    }
    return 0;
}
