//
//  main.cpp
//  BJFU_278
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

typedef struct {
    int vexnum;
    linklist v[maxn];
}graph;

int main(int argc, const char * argv[]) {
    int n,m;
    while (cin >> n >> m) {
        if(!n && !m)    break;
        graph g;
        g.vexnum = n;
        for (int i=1; i<=n; i++) {
            g.v[i] = new node;
            g.v[i]->data = i;
            g.v[i]->next = NULL;
        }
        for (int i=1; i<=m+1; i++) {
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
        for (int i=1; i<=g.vexnum; i++) {
            linklist temp = g.v[i];
            cout<<temp->data;
            temp = temp->next;
            while (temp) {
                cout<<" "<<temp->data;
                temp = temp->next;
            }
            cout<<endl;
        }
    }
    return 0;
}
