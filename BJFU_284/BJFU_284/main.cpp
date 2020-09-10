//
//  main.cpp
//  BJFU_284
//
//  Created by VachelChen on 2020/9/9.
//  Copyright © 2020 VachelChen. All rights reserved.
//

#include <iostream>
#define maxn 100
using namespace std;

typedef struct node{
    char data;
    node *next;
}node,*linklist;

typedef struct {
    int vernum;
    int arcnum;
    linklist v[maxn];
}graph;

int find(char x,graph g){
    for (int i=1; i<=g.vernum; i++) {
        if(x == g.v[i]->data)
            return i;
    }
    return 0;
}

int main(int argc, const char * argv[]) {
    int n,m;
    while (cin >> n >> m) {
        if(!n && !m)    break;
        graph g;
        g.vernum = n;
        g.arcnum = m;
        for (int i=1; i<=n; i++) {
            char c;
            cin >> c;
            g.v[i] = new node;
            g.v[i]->data = c;
            g.v[i]->next = NULL;
        }
        for (int j=1; j<=m; j++) {
            char a,b;
            cin >> a >> b;
            int x,y;
            x = find(a,g);
            y = find(b,g);
            linklist p;
            p = new node;
            p->data = a;
            p->next = g.v[y]->next;
            g.v[y]->next = p;
            
            linklist q;
            q = new node;
            q->data = b;
            q->next = g.v[x]->next;
            g.v[x]->next = q;
        }
        char a,b;
        cin >> a >> b;
        int x = find(a,g);
        linklist t;
        
        //dfs
        bool flag = false;
        int top=0;
        int Stack[maxn];
        bool visit[maxn];
        fill(visit, visit+maxn, false);
        Stack[top++] = x;
        visit[find(a,g)] = true;
        while (top>0 && !flag) {
            t = g.v[Stack[top-1]]->next;
            char p = '.';
            while (t && !flag) {
                if (!visit[find(t->data,g)]) {
                    p = t->data;
                    if (p == b) {
                        flag = true;
                    }
                }
                t = t->next;
            }
            if (p == '.') {
                top--;
            }
            else{
                Stack[top++] = find(p,g);
                visit[find(p,g)] = true;
            }
        }
        if(flag)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}
