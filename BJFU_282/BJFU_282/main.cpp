//
//  main.cpp
//  BJFU_282
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
    int vernum;
    int arcnum;
    linklist v[maxn];
}graph;

int visit[maxn];
int Stack[maxn];
int top = 0;

void dfs(graph g,int x){
    cout<<x;
    visit[x] = true;
    Stack[top++] = x;
    while (top>0) {
        linklist t = g.v[Stack[top-1]];
        int y = -1;
        while (t) {
            if (!visit[t->data]) {
                y = t->data;
            }
            t=t->next;
        }
        if (y == -1) {
            top--;
        }
        else{
            Stack[top++] = y;
            cout<<" "<<y;
            visit[y] = true;
        }
    }
    cout<<endl;
}

int main(int argc, const char * argv[]) {
    int n,m;
    while (cin >> n >> m) {
        if(!n && !m)    break;
        fill(visit, visit+maxn, false);
        graph g;
        g.vernum = n;
        g.vernum = m;
        for (int i=1; i<=n; i++) {
            g.v[i] = new node;
            g.v[i]->data = i;
            g.v[i]->next = NULL;
        }
        for (int i=1; i<=m; i++) {
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
        int s;
        cin >> s;
        dfs(g,s);
    }
    return 0;
}
