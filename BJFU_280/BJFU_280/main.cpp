//
//  main.cpp
//  BJFU_280
//
//  Created by VachelChen on 2020/9/7.
//  Copyright © 2020 VachelChen. All rights reserved.
//

#include <iostream>
#define maxn 100
using namespace std;

typedef struct node{
    int data;
    node *next;
}node,*linklist;

typedef struct{
    int vex;
    int num;
    linklist v[maxn];
}graph;

int main(int argc, const char * argv[]) {
    int n,m;
    while (cin >> n >> m) {
        if(!n && !m)  break;
        graph g;
        g.vex = n;
        for (int i=1; i<=g.vex; i++) {
            g.v[i] = new node;
            g.v[i]->data = i;
            g.v[i]->next = NULL;
        }
        for (int j=1; j<=m; j++) {
            int x,y;
            cin >> x >> y;
            linklist p;
            p = new node;
            p->data = x;
            p->next = g.v[y]->next;
            g.v[y]->next = p;
            
            linklist q;
            q = new node;
            q->data = y;
            q->next = g.v[x]->next;
            g.v[x]->next = q;
        }
        int x,y;
        cin >> x >> y;
        linklist t1=g.v[x],t2=g.v[x]->next;
        while (t2) {
            if (t2->data == y) {
                t1->next = t2->next;
                break;
            }
            t1 = t2;
            t2 = t2->next;
        }
        t1=g.v[y];
        t2=g.v[y]->next;
        while (t2) {
            if (t2->data == x) {
                t1->next = t2->next;
                break;
            }
            t1 = t2;
            t2 = t2->next;
        }
        for (int i=1; i<=g.vex; i++) {
            cout<<g.v[i]->data;
            t1 = g.v[i]->next;
            while (t1) {
                cout<<" "<<t1->data;
                t1 = t1->next;
            }
            cout<<endl;
        }
    }
    return 0;
}
