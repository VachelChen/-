//
//  main.cpp
//  BJFU_275
//
//  Created by VachelChen on 2020/9/6.
//  Copyright © 2020 VachelChen. All rights reserved.
//

#include <iostream>
#define maxn 100
using namespace std;

//side表
typedef struct Lnode{
    int data;
    Lnode *next;
}Lnode,*LinkList;

typedef struct {
    int vernum;
    int arcnum;
    LinkList v[maxn];
}graph;

int main(int argc, const char * argv[]) {
    // insert code here...
    int n,m;
    while (cin >> n >> m) {
        if(!n && !m)    break;
        graph g;
        g.vernum = n;
        g.arcnum = m;
        for (int i=1; i<=n; i++) {
            g.v[i] = new Lnode;
            g.v[i]->data = i;
            g.v[i]->next = NULL;
        }
        for(int i=1;i<=m;i++){
            int x,y;
            cin >> x >> y;
            LinkList p;
            p = new Lnode;
            p->data = x;
            p->next = g.v[y]->next;
            g.v[y]->next = p;
            LinkList q;
            q = new Lnode;
            q->data = y;
            q->next = g.v[x]->next;
            g.v[x]->next = q;
        }
        int newNode;
        cin >> newNode;
        g.vernum++;
        g.v[g.vernum] = new Lnode;
        g.v[g.vernum]->data = newNode;
        g.v[g.vernum]->next = NULL;
        
        for (int i=1;i<=g.vernum; i++) {
            cout<<g.v[i]->data;
            LinkList t = g.v[i]->next;
            while (t) {
                cout<<" "<<t->data;
                t=t->next;
            }
            cout<<endl;
        }
    }
    return 0;
}
