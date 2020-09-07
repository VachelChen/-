//
//  main.cpp
//  BJFU_277
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

void DN(linklist &l,int x){
    linklist s1,s2;
    s1 = l;
    s2 = s1->next;
    while (s2->data != x) {
        s1 = s2;
        s2 = s2->next;
    }
    s1->next = s2->next;
    delete s2;
}

int main(int argc, const char * argv[]) {
    int n,m;
    while (cin >> n >> m) {
        if(!n && !m ) break;
        graph g;
        g.vexnum = n;
        for (int i=1; i<=n; i++) {
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
        int deleteNode;
        cin >> deleteNode;
        if (deleteNode>g.vexnum || deleteNode < 1) {
            cout<<"error"<<endl;
        }
        else{
            linklist temp = g.v[deleteNode]->next;
            while (temp) {
                DN(g.v[temp->data],deleteNode);
                temp = temp->next;
            }
            g.v[deleteNode] = NULL;
            for (int i=1; i<=g.vexnum; i++) {
                if(g.v[i]){
                    cout<<g.v[i]->data;
                    temp = g.v[i]->next;
                    while (temp) {
                        cout<<" "<<temp->data;
                        temp=temp->next;
                    }
                    cout<<endl;
                }
            }
        }
    }
    return 0;
}
